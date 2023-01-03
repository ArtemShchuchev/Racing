#include "myFunc.h"


COORD GetConsoleCursorPosition()
{
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
    {
        return cbsi.dwCursorPosition;
    }
    else
    {
        // The function failed. Call GetLastError() for details.
        COORD invalid = { 0, 0 };
        return invalid;
    }
}
void consolePos(const short column, const short line)
{
    COORD coord{};
    if (line < 0) coord = GetConsoleCursorPosition();
    else coord.Y = line;
    coord.X = column;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void consoleKursorVisible(const bool key)
{
    CONSOLE_CURSOR_INFO curs = { sizeof(curs), key };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curs);
}
/*
    00 - ������
    01 - �����
    02 - �������
    03 - �������
    04 - �������
    05 - ����������
    06 - ������
    07 - �����
    ----
    08 - �����
    09 - ���. �����
    10 - ���. �������
    11 - ���. �������
    12 - ���. �������
    13 - ���. ����������
    14 - ���. ������
    15 - ���. �����
*/
void consoleCol(WORD color) // �� ��������� ����� �� ������ ����
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// ���������
void printHeader(Data& d)
{
    using namespace std;
    system("cls");

    const char* trStr[] = { "�������� �����", "��������� �����", "��������� �����" };
    const int sizeArr = sizeof trStr / sizeof trStr[0];
    int offset = d.typeRacing - 1;

    cout << "����� ���������� � �������� ���������!\n"
        << "--------------------------------------" << endl;
    if (d.typeRacing != NONE) // ���������� ���� �����?
    {
        if (offset < 0 || offset >= sizeArr)
        {
            throw std::range_error("��� ������ ���� �����.");
        }
        cout << "��� �����: " << trStr[offset] << endl;
    }
    if (d.distance > 0) cout << "����� �� ���������: " << d.distance << endl;
}

// ����� ���� �����.
void typeRaceChoice(Data& d)
{
    printHeader(d);
    const char* str = "�������� ��� �����...\n\
1. ����� ��� ��������� ����������\n\
2. ����� ��� ���������� ����������\n\
3. ����� ��� ��������� � ���������� ����������\n";
    
    d.typeRacing = static_cast<RacingType>(numInput(str, 1, 1, sizeof RacingType - 1));
}

 // ���� ��������� �� ������
void distanceChoice(Data& d)
{
    do
    {
        printHeader(d);
        d.distance = numInput("������� ����� ���������: ");
    } while (d.distance <= 0);
}

// ����� ��������� �����.
void racerChoice(Data& d)
{
    using namespace std;

    int numList(0);                     // ����� ������������
    do
    {
        printHeader(d);

        short countMemb(0);             // ������� ����������
        short countAppl(0);             // ������� ������������
        int racerChoice = d.typeRacing == LAND ? ON_FOOT : d.typeRacing == AIR ? FLYING : ON_FOOT + FLYING;
        
        COORD consPos = GetConsoleCursorPosition();
        consPos.X = 3;
        ++consPos.Y;
        consoleCol(6);
        consolePos(consPos.X, consPos.Y);
        cout << "�������� ���������...";
        consoleCol();
        consolePos(consPos.X + 30, consPos.Y);
        cout << "������ ����������:" << endl;

        for (int i = 0; i < d.qtyVehicle; ++i)
        {
            // ��������� �������� ���� �����
            if (d.vehicle[i]->getTypeRacer() & racerChoice)
            {
                if (d.vehicle[i]->checkIsMembers()) // ��������� ����� ����������
                {
                    ++countMemb;
                    ++countAppl;

                    consoleCol();
                    consolePos(consPos.X + 30, consPos.Y + countAppl);
                    //cout << countAppl << ". "
                    cout << d.vehicle[i]->getNameRacer();

                    consoleCol(8);
                    consolePos(consPos.X - 1, consPos.Y + countAppl);
                    cout << "(" << countAppl << ") "
                        << d.vehicle[i]->getNameRacer();
                }
                else                                // ��������� ����� ������������
                {
                    ++countAppl;
                    consoleCol(6);
                    consolePos(consPos.X, consPos.Y + countAppl);
                    cout << countAppl << ". " << d.vehicle[i]->getNameRacer();
                }
            }
        }
        
        consoleCol();
        consPos = GetConsoleCursorPosition();
        consPos.X = 3;
        ++consPos.Y;
        // ���������� ���������/����������
        short choiceMin(1);     // ���. ����� ��� ������
        if (countMemb > 0)
        {
            consoleCol(12);
            consolePos(consPos.X, ++consPos.Y);
            cout << "����� ����� � ������� (), ����� �������� �����." << endl;
            consoleCol();

            if (countMemb > 1)
            {
                consoleCol(2);
                consolePos(consPos.X, ++consPos.Y);
                cout << "0. ������ �����" << endl;
                consoleCol();
                choiceMin = 0;  // �������� "0" � �����
            }
        }
        numList = numInput("", 1, choiceMin, countAppl);// ����� ������������

        // ��� ���������� ����� ���������
        int count(0);
        for (int i = 0; i < d.qtyVehicle; ++i)
        {
            if (d.vehicle[i]->getTypeRacer() & racerChoice) // ��������� �������� ���� �����
            {
                if (++count == numList)
                {
                    // ������ ��� ��������/����������
                    d.vehicle[i]->setMembers(!d.vehicle[i]->checkIsMembers());
                }
            }
        }
    } while (numList);
}

// ������ � ����� ���������� � �����
int startRace(Data& d)
{
    using namespace std;
    printHeader(d);
    cout << "���������� �����:" << endl;

    // ���������� �� ���������� ������
    bool change = false;
    do
    {
        change = false;
        for (int i = 0; i < d.qtyVehicle - 1; ++i)
        {
            if (d.vehicle[i]->checkIsMembers() == true) // ��� 1�� ���������
            {
                for (int j = i + 1; j < d.qtyVehicle; ++j)
                {
                    if (d.vehicle[j]->checkIsMembers() == true) // ��� 2�� ���������
                    {
                        // ��������� �� ������ � ��� �����. ����� �������
                        if (d.vehicle[i]->timeCalc(d.distance) > d.vehicle[j]->timeCalc(d.distance))
                        {
                            Vehicle* temp = d.vehicle[i];
                            d.vehicle[i] = d.vehicle[j];
                            d.vehicle[j] = temp;
                            change = true;
                            break;
                        }
                    }
                }
            }
        }
    } while (change);

    // ����� ���������� � �������
    short count(0);     // ������� ������� ����������
    for (int i = 0; i < d.qtyVehicle; ++i)
    {
        if (d.vehicle[i]->checkIsMembers())
        {
            cout << "  " << ++count << ". " << d.vehicle[i]->getNameRacer()
                << ". �����: " << d.vehicle[i]->timeCalc(d.distance) << endl;
            d.vehicle[i]->setMembers(false);
        }
    }
    const char* str = "\n�������� ��������...\n1. �������� ��� ���� �����\n2. ����� �� ����\n";
    int numList = numInput(str, 1, 1, 2);

    return numList;
}

// ���� � �������� ����������.
int numInput(const std::string& userText, const short QTY, const short MIN, const short MAX, const short SPECIAL)
{
    using namespace std;
    
    short counter = 0;      // ������� ��������
    int num = 0;            // ������������ ��������
    bool inpEND = false;    // ����� �����
    cout << userText;
    do
    {
        char ch = 0;        // �������� ������
        int temp = 0;       // ��������� int
        bool inpNUM = true; // ������� �������� �������
        
        if (_kbhit())       // ���� ������� ���� ������
        {
            ch = _getch();
            //cout << static_cast<int>(ch) << " ";
            switch (ch)
            {
            /*
            case 43:    // +
            case 45:    // -
            case 61:    // =
            case 88:    // X
            case 120:   // x
            case 215:   // �
            case 247:   // �
            */
            case 48:    // 0
            case 49:    // 1
            case 50:    // 2
            case 51:    // 3
            case 52:    // 4
            case 53:    // 5
            case 54:    // 6
            case 55:    // 7
            case 56:    // 8
            case 57:    // 9
                temp = static_cast<int>(ch) - 48;
                if (temp < MIN || temp > MAX) inpNUM = false;
                break;

            case 8:    // Backspace
                inpNUM = false;
                if (counter != 0)
                {
                    num /= 10;
                    cout << ch << ' ' << ch;
                    --counter;
                }
                break;

            case 13:    // Enter
                inpNUM = false;
                if (counter != 0)
                {
                    inpEND = true;
                    cout << endl;
                }
                break;

            case 27:    // ESC
                inpNUM = false;
                if (SPECIAL == 1)
                {
                    num = -1;
                    inpEND = true;
                    ++counter;
                }
                break;

            default:    // �� ����� � ������ ������
                inpNUM = false;
                break;
            }

            if (inpNUM)
            {
                num = counter == 0 ? temp : num * 10 + temp;
                ++counter;
                if (counter == QTY) inpEND = true;
                else cout << ch;
            }
        }
    } while ( !(inpEND && counter) );

    return num;
}

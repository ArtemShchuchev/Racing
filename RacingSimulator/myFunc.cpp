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
    00 - черный
    01 - синий
    02 - зеленый
    03 - голубой
    04 - красный
    05 - фиолетовый
    06 - желтый
    07 - белый
    ----
    08 - серый
    09 - ярк. синий
    10 - ярк. зеленый
    11 - ярк. голубой
    12 - ярк. красный
    13 - ярк. фиолетовый
    14 - ярк. желтый
    15 - ярк. белый
*/
void consoleCol(WORD color) // по умолчанию белый на черном фоне
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// заголовок
void printHeader(Data& d)
{
    using namespace std;
    system("cls");

    const char* trStr[] = { "Наземная гонка", "Воздушная гонка", "Смешанная гонка" };
    const int sizeArr = sizeof trStr / sizeof trStr[0];
    int offset = d.typeRacing - 1;

    cout << "Добро пожаловать в гоночный симулятор!\n"
        << "--------------------------------------" << endl;
    if (d.typeRacing != NONE) // показывать этот пункт?
    {
        if (offset < 0 || offset >= sizeArr)
        {
            throw std::range_error("Нет такого вида гонки.");
        }
        cout << "Тип гонки: " << trStr[offset] << endl;
    }
    if (d.distance > 0) cout << "Гонка на дистанцию: " << d.distance << endl;
}

// Выбор типа гонки.
void typeRaceChoice(Data& d)
{
    printHeader(d);
    const char* str = "Выберите тип гонки...\n\
1. Гонка для наземного транспорта\n\
2. Гонка для воздушного транспорта\n\
3. Гонка для наземного и воздушного транспорта\n";
    
    d.typeRacing = static_cast<RacingType>(numInput(str, 1, 1, sizeof RacingType - 1));
}

 // Ввод дистанции до финиша
void distanceChoice(Data& d)
{
    do
    {
        printHeader(d);
        d.distance = numInput("Укажите длину дистанции: ");
    } while (d.distance <= 0);
}

// Выбор участника гонки.
void racerChoice(Data& d)
{
    using namespace std;

    int numList(0);                     // выбор пользователя
    do
    {
        printHeader(d);

        short countMemb(0);             // счетчик участников
        short countAppl(0);             // счетчик претендентов
        int racerChoice = d.typeRacing == LAND ? ON_FOOT : d.typeRacing == AIR ? FLYING : ON_FOOT + FLYING;
        
        COORD consPos = GetConsoleCursorPosition();
        consPos.X = 3;
        ++consPos.Y;
        consoleCol(6);
        consolePos(consPos.X, consPos.Y);
        cout << "Выберите участника...";
        consoleCol();
        consolePos(consPos.X + 30, consPos.Y);
        cout << "Список участников:" << endl;

        for (int i = 0; i < d.qtyVehicle; ++i)
        {
            // отображаю согласно типа гонки
            if (d.vehicle[i]->getTypeRacer() & racerChoice)
            {
                if (d.vehicle[i]->checkIsMembers()) // показываю списк участников
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
                else                                // показываю списк претендентов
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
        // управление удалением/окончанием
        short choiceMin(1);     // мин. цифра для опроса
        if (countMemb > 0)
        {
            consoleCol(12);
            consolePos(consPos.X, ++consPos.Y);
            cout << "Нажми цифру в скобках (), чтобы отменить выбор." << endl;
            consoleCol();

            if (countMemb > 1)
            {
                consoleCol(2);
                consolePos(consPos.X, ++consPos.Y);
                cout << "0. Начать гонку" << endl;
                consoleCol();
                choiceMin = 0;  // включить "0" в выбор
            }
        }
        numList = numInput("", 1, choiceMin, countAppl);// выбор пользователя

        // ищу порядковый номер участника
        int count(0);
        for (int i = 0; i < d.qtyVehicle; ++i)
        {
            if (d.vehicle[i]->getTypeRacer() & racerChoice) // участники согласно типу гонки
            {
                if (++count == numList)
                {
                    // теперь это участник/претендент
                    d.vehicle[i]->setMembers(!d.vehicle[i]->checkIsMembers());
                }
            }
        }
    } while (numList);
}

// Расчет и вывод информации о гонке
int startRace(Data& d)
{
    using namespace std;
    printHeader(d);
    cout << "Результаты гонки:" << endl;

    // сортировка по занимаемым местам
    bool change = false;
    do
    {
        change = false;
        for (int i = 0; i < d.qtyVehicle - 1; ++i)
        {
            if (d.vehicle[i]->checkIsMembers() == true) // ищу 1го участника
            {
                for (int j = i + 1; j < d.qtyVehicle; ++j)
                {
                    if (d.vehicle[j]->checkIsMembers() == true) // ищу 2го участника
                    {
                        // сравниваю их успехи и при необх. меняю местами
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

    // вывод участников в консоль
    short count(0);     // счетчик строчек участников
    for (int i = 0; i < d.qtyVehicle; ++i)
    {
        if (d.vehicle[i]->checkIsMembers())
        {
            cout << "  " << ++count << ". " << d.vehicle[i]->getNameRacer()
                << ". Время: " << d.vehicle[i]->timeCalc(d.distance) << endl;
            d.vehicle[i]->setMembers(false);
        }
    }
    const char* str = "\nВыберите действие...\n1. Провести еще одну гонку\n2. Выйти из игры\n";
    int numList = numInput(str, 1, 1, 2);

    return numList;
}

// Ввод с цифрофой клавиатуры.
int numInput(const std::string& userText, const short QTY, const short MIN, const short MAX, const short SPECIAL)
{
    using namespace std;
    
    short counter = 0;      // счетчик символов
    int num = 0;            // возвращаемое значение
    bool inpEND = false;    // конец ввода
    cout << userText;
    do
    {
        char ch = 0;        // введеный символ
        int temp = 0;       // введенные int
        bool inpNUM = true; // введены цыфровые символы
        
        if (_kbhit())       // если клавиша была нажата
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
            case 215:   // Ч
            case 247:   // ч
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

            default:    // не попал в нужные кнопки
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

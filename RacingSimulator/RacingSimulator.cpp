#include <iostream> // консоль - cout
#include "myFunc.h"

#include "../RaceLib/Camel.h"
#include "../RaceLib/Centaur.h"
#include "../RaceLib/Boots.h"
#include "../RaceLib/CamelFast.h"
#include "../RaceLib/Carpet.h"
#include "../RaceLib/Eagle.h"
#include "../RaceLib/Broom.h"


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");   // задаём русский текст
    system("chcp 1251");            // настраиваем кодировку консоли
    SetConsoleTitleA("Гоночный симулятор!");
    consoleKursorVisible(false);    // отключил курсор
    
    try
    {
        int answer(0);
        do
        {
            Vehicle* veh[]                  // общий список
            {
                new Camel,
                new CamelFast,
                new Centaur,
                new Boots,
                new Carpet,
                new Eagle,
                new Broom
            };

            Data data;
            data.vehicle = veh;
            data.qtyVehicle = sizeof veh / sizeof veh[0];   // кол-во претендентов

            data.distance = 0;
            data.typeRacing = NONE;

            // выбери тип гонки
            typeRaceChoice(data);

            // укажи дистанцию
            distanceChoice(data);

            // выбери участников
            racerChoice(data);

            // начать гонку
            answer = startRace(data);

            for (int i = 0; i < data.qtyVehicle; i++)
            {
                delete data.vehicle[i];
            }
        } while (answer != 2);

    }
    catch (const std::range_error& err)
    {
        std::cout << "Ошибка: range_error! " << err.what() << std::endl;
    }
    catch (const std::bad_alloc& err)
    {
        // не знаю что сделать, чтобы это сработало
        // я пытался выделить гору памяти... копьютер долго-долго
        // тупил, мышка еле двигалась, но он смог, чере пару минут
        // раздумий. Исключение не сработало, как я ожидал.
        std::cout << "Ошибка: bad_alloc! " << err.what() << std::endl;
    }
    catch (const std::runtime_error& err)
    {
        std::cout << "Ошибка: runtime_error! " << err.what() << std::endl;
    }
    catch (const std::exception& err)
    {
        std::cout << "Ошибка! " << err.what() << std::endl;
    }


    return 0;
}
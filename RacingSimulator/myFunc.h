#pragma once

#include <iostream>		// консоль - cout
#include <Windows.h>	// for color change of text and background
#include <conio.h>		// _kbhit()

#include "../RaceLib/Vehicle.h"

enum RacingType { NONE, LAND, AIR, MIX };    // Тип гонки

// структура содержит данные о гонке
struct Data
{
	RacingType typeRacing = NONE;	// тип гонки
	int distance = 0;				// дистанция гонки
	short qtyVehicle = 0;			// кол-во всех доступных гонщиков
	Vehicle** vehicle = nullptr;	// массив всех классов гонщиков
};

COORD GetConsoleCursorPosition();
void consolePos(const short column, const short line = -1);
void consoleKursorVisible(const bool key);
void consoleCol(WORD color = 7); // по умолчанию белый на черном фоне
/*
* мышиные координаты (по разрешению дисплея)
POINT position;
GetCursorPos(&position);
*/

// вывод заголовка программы
void printHeader(Data&);

/*
	Меню:
	Выбор типа гонки.
*/
void typeRaceChoice(Data&);

/*
	Меню:
	Ввод дистанции до финиша
*/
void distanceChoice(Data&);

/*
	Меню:
	Выбор участника гонки.
*/
void racerChoice(Data&);

/*
	Меню:
	Расчет и вывод информации о гонке
*/
int startRace(Data&);

/*
	Ввод с цифрофой клавиатуры.
	Принимает:
		строка: выводится перед вводом данных
		кол-во вводимых символов: 0 - до нажатия "Enter" (по умолчанию)
		диапазон от: по умолчанию от 0 (включительно)
		диапазон до: по умолчанию до 9 (включительно)
		ожидает спец. символы:	0 - нет спец. символов
								1 - ESC
	Возвращает: введенный пользователем int
*/
int numInput(const std::string& , const short = 0, const short = 0, const short = 9, const short = 0);

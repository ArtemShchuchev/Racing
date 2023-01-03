#pragma once

#include <iostream>		// ������� - cout
#include <Windows.h>	// for color change of text and background
#include <conio.h>		// _kbhit()

#include "../RaceLib/Vehicle.h"

enum RacingType { NONE, LAND, AIR, MIX };    // ��� �����

// ��������� �������� ������ � �����
struct Data
{
	RacingType typeRacing = NONE;	// ��� �����
	int distance = 0;				// ��������� �����
	short qtyVehicle = 0;			// ���-�� ���� ��������� ��������
	Vehicle** vehicle = nullptr;	// ������ ���� ������� ��������
};

COORD GetConsoleCursorPosition();
void consolePos(const short column, const short line = -1);
void consoleKursorVisible(const bool key);
void consoleCol(WORD color = 7); // �� ��������� ����� �� ������ ����
/*
* ������� ���������� (�� ���������� �������)
POINT position;
GetCursorPos(&position);
*/

// ����� ��������� ���������
void printHeader(Data&);

/*
	����:
	����� ���� �����.
*/
void typeRaceChoice(Data&);

/*
	����:
	���� ��������� �� ������
*/
void distanceChoice(Data&);

/*
	����:
	����� ��������� �����.
*/
void racerChoice(Data&);

/*
	����:
	������ � ����� ���������� � �����
*/
int startRace(Data&);

/*
	���� � �������� ����������.
	���������:
		������: ��������� ����� ������ ������
		���-�� �������� ��������: 0 - �� ������� "Enter" (�� ���������)
		�������� ��: �� ��������� �� 0 (������������)
		�������� ��: �� ��������� �� 9 (������������)
		������� ����. �������:	0 - ��� ����. ��������
								1 - ESC
	����������: ��������� ������������� int
*/
int numInput(const std::string& , const short = 0, const short = 0, const short = 9, const short = 0);

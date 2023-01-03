#include "Carpet.h"

// ���������: ��� ����������, ��������
Carpet::Carpet() : VehicleAir("����-������", 10) {}
/*
	���������� ������ ��� ����������

	����������� ���������� ����������:
	���� ���������� ������ 1000 � ��� ����������
	���� ���������� ������ 5000 � 3%
	���� ���������� ������ 10000 � 10%
	���� ���������� ������ ��� ����� 10000 � 5%
*/
double Carpet::getDeltaDist(const int distance)
{
	double distMult = 5.0 / 100;	// ������ ��� ����� 10000 � 5%
	if (distance < 1000) distMult = 0.0;
	else if (distance < 5000) distMult = 3.0 / 100;
	else if (distance < 10000) distMult = 10.0 / 100;
	double delta = distMult * distance;
	
	return delta;
}

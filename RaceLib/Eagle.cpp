#include "Eagle.h"

// ���������: ��� ����������, ��������
Eagle::Eagle() : VehicleAir("���", 8) {}
/*
	���������� ������ ��� ����������
	
	����������� ���������� ����������:
	������ 6%
*/
double Eagle::getDeltaDist(const int distance)
{
	double distMult = 6.0 / 100;
	double delta = distMult * distance;

	return delta;
}

#include "Broom.h"
// ���������: ��� ����������, ��������
Broom::Broom() : VehicleAir("�����", 20) {}
/*
	���������� ������ ��� ����������

	����������� ���������� ����������:
	������������� �� 1% �� ������ 1000 �.�. ����������
	��������, ��� ���������� 5600 ����������� ����� 5%

	��� ���������� � 100 000 ��������� ��������������� 
	� ������!?
*/
double Broom::getDeltaDist(const int distance)
{
	double distMult = static_cast<double>(distance / 1000) / 100;
	if (distMult > 0.4) distMult = 0.4;	// ������� �� ���� (�� ����� 40%)
	double delta = distMult * distance;

	return delta;
}

#include "Boots.h"

// ����� ������ (2 ��������): 1�� ���, ����������� ����
const double Boots::T_REST[]{ 10.0 , 5.0 };
short Boots::qtyRest = sizeof T_REST / sizeof T_REST[0];

// ���������: ��� ����������, ��������, ����� � ��������,
// ���-�� ��������� ������, ����� ������ (�������)
Boots::Boots() : VehicleLand("�������-���������", 6, 60, qtyRest, T_REST) {}

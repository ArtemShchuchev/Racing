#include "Camel.h"

// ����� ������ (2 ��������): 1 ���, ����������� ����
const double Camel::T_REST[]{ 5.0 , 8.0 };
short Camel::qtyRest = sizeof T_REST / sizeof T_REST[0];

// ���������: ��� ����������, ��������, ����� � ��������,
// ���-�� ��������� ������, ����� ������ (�������)
Camel::Camel() : VehicleLand("�������", 10, 30, qtyRest, T_REST) {}

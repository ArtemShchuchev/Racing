#include "CamelFast.h"

// ����� ������ (3 ��������): 1�� ���, 2��, ����������� ����
const double CamelFast::T_REST[]{ 5.0 , 6.5 , 8.0 };
short CamelFast::qtyRest = sizeof T_REST / sizeof T_REST[0];

// ���������: ��� ����������, ��������, ����� � ��������,
// ���-�� ��������� ������, ����� ������ (�������)
CamelFast::CamelFast() : VehicleLand("�������-���������", 40, 10, qtyRest, T_REST) {}

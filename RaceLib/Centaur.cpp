#include "Centaur.h"

// ����� ������ (1 �������): ������
const double Centaur::T_REST[]{ 2.0 };
short Centaur::qtyRest = sizeof T_REST / sizeof T_REST[0];

// ���������: ��� ����������, ��������, ����� � ��������,
// ���-�� ��������� ������, ����� ������ (�������)
Centaur::Centaur() : VehicleLand("�������", 15, 8, qtyRest, T_REST) {}

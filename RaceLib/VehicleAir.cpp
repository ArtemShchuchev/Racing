#include "VehicleAir.h"

VehicleAir::VehicleAir(const char* name, const short speed) : Vehicle(speed, name) {}

double VehicleAir::timeCalc(const int distance)
{
    if (SPEED == 0 ) throw std::runtime_error("������ ������ �� 0. (VehicleAir)");
    // ��������� ���������� ���������� � ������ ���������
    double newDist = distance - getDeltaDist(distance);
    // ����� � ��������
    double time = newDist / SPEED;

    return time;
}

RaceType VehicleAir::getTypeRacer()
{
    return FLYING;
}

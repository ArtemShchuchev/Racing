#include "VehicleAir.h"

VehicleAir::VehicleAir(const char* name, const short speed) : Vehicle(speed, name) {}

double VehicleAir::timeCalc(const int distance)
{
    if (SPEED == 0 ) throw std::runtime_error("Нельзя делить на 0. (VehicleAir)");
    // определяю пройденное расстояние с учетом множителя
    double newDist = distance - getDeltaDist(distance);
    // время в движении
    double time = newDist / SPEED;

    return time;
}

RaceType VehicleAir::getTypeRacer()
{
    return FLYING;
}

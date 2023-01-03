#include "Vehicle.h"

Vehicle::Vehicle(const short speed, const char* name) :
    SPEED(speed), NAME(name), members(false) {}

const char* Vehicle::getNameRacer()
{
    return NAME;
}

bool Vehicle::checkIsMembers()
{
    return members;
}

void Vehicle::setMembers(bool memb)
{
    members = memb;
}

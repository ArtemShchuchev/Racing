#pragma once
#include <stdexcept>
#include "Vehicle.h"
#include "RaceLib.h"

class VehicleAir : public Vehicle
{
protected:
	VehicleAir(const char* name, const short speed);
	virtual ~VehicleAir() = default;

public:
	RACER_DLL_API double timeCalc(int distance) override;
	RACER_DLL_API RaceType getTypeRacer() override;

private:
	virtual double getDeltaDist(const int distance) = 0;

};

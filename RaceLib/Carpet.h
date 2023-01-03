#pragma once
#include "VehicleAir.h"
#include "RaceLib.h"

class Carpet : public VehicleAir
{
public:
	RACER_DLL_API Carpet();

private:
	double getDeltaDist(const int distance) override;
};

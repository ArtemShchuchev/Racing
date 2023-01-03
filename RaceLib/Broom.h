#pragma once
#include "VehicleAir.h"
#include "RaceLib.h"

class Broom : public VehicleAir
{
public:
	RACER_DLL_API Broom();

private:
	double getDeltaDist(const int distance) override;
};

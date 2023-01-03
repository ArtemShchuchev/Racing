#pragma once
#include "VehicleAir.h"
#include "RaceLib.h"

class Eagle : public VehicleAir
{
public:
	RACER_DLL_API Eagle();

private:
	double getDeltaDist(const int distance) override;
};

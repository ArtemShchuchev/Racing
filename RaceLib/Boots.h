#pragma once
#include "VehicleLand.h"
#include "RaceLib.h"

class Boots : public VehicleLand
{
public:
	RACER_DLL_API Boots();

private:
	static const double T_REST[];	// время отдыха
	static short qtyRest;			// кол-во вариантов отдыха
};

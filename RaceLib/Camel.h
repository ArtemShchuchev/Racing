#pragma once
#include "VehicleLand.h"
#include "RaceLib.h"

class Camel : public VehicleLand
{
public:
	RACER_DLL_API Camel();

private:
	static const double T_REST[];	// ����� ������
	static short qtyRest;			// ���-�� ��������� ������
};

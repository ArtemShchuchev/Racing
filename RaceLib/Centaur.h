#pragma once
#include "VehicleLand.h"
#include "RaceLib.h"

class Centaur : public VehicleLand
{
public:
	RACER_DLL_API Centaur();

private:
	static const double T_REST[];	// ����� ������
	static short qtyRest;			// ���-�� ��������� ������
};

#pragma once
#include "VehicleLand.h"
#include "RaceLib.h"

class CamelFast : public VehicleLand
{
public:
	RACER_DLL_API CamelFast();

private:
	static const double T_REST[];	// ����� ������
	static short qtyRest;			// ���-�� ��������� ������
};

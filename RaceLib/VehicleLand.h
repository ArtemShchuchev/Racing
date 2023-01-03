#pragma once
#include <stdexcept>
#include "Vehicle.h"
#include "RaceLib.h"

class VehicleLand : public Vehicle
{
protected:
	VehicleLand(const char* name, const short speed, const short tRun, const short qtyRest, const double* const tRest_ptr);
	virtual ~VehicleLand() = default;

	const short TIME_RUN;				// ����� � ��������
	const short QTY_VAR_REST;			// ���-�� ��������� ������
	const double* const TIME_REST_PTR;	// ����� ������ (��� ������� �� ���������)

public:
	RACER_DLL_API double timeCalc(const int distance) override;
	RACER_DLL_API RaceType getTypeRacer() override;
};

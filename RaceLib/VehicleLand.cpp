#include "VehicleLand.h"

VehicleLand::VehicleLand(const char* name, const short speed, const short tRun, const short qtyRest, const double* const tRest_ptr) :
	TIME_RUN(tRun), QTY_VAR_REST(qtyRest), TIME_REST_PTR(tRest_ptr), Vehicle(speed, name) {}

double VehicleLand::timeCalc(const int distance)
{
	if (SPEED == 0 || TIME_RUN == 0) throw std::runtime_error("Ќельз€ делить на 0. (VehicleLand)");
	// врем€ в движении
	double time = static_cast<double>(distance) / SPEED;
	// скольно раз нужно отдохнуть, чтоб пройти дистанцию
	int amountOfRest = static_cast<int>(time) / TIME_RUN;
	// если врем€ начала отдыха совпадает с окончанием гонки
	if (static_cast<int>(time) % TIME_RUN == 0) --amountOfRest;

	int temp = 0;
	while (temp < amountOfRest)
	{
		time += temp >= QTY_VAR_REST ? TIME_REST_PTR[QTY_VAR_REST - 1] : TIME_REST_PTR[temp];
		++temp;
	}

	return time;
}

RaceType VehicleLand::getTypeRacer()
{
	return ON_FOOT;
}

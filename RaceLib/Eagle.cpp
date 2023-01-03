#include "Eagle.h"

// Принимает: имя транспорта, скорость
Eagle::Eagle() : VehicleAir("Орёл", 8) {}
/*
	Вычисление дельты для расстояния
	
	Коэффициент сокращения расстояния:
	Всегда 6%
*/
double Eagle::getDeltaDist(const int distance)
{
	double distMult = 6.0 / 100;
	double delta = distMult * distance;

	return delta;
}

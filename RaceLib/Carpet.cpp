#include "Carpet.h"

// Принимает: имя транспорта, скорость
Carpet::Carpet() : VehicleAir("Ковёр-самолёт", 10) {}
/*
	Вычисление дельты для расстояния

	Коэффициент сокращения расстояния:
	Если расстояние меньше 1000 — без сокращения
	Если расстояние меньше 5000 — 3%
	Если расстояние меньше 10000 — 10%
	Если расстояние больше или равно 10000 — 5%
*/
double Carpet::getDeltaDist(const int distance)
{
	double distMult = 5.0 / 100;	// больше или равно 10000 — 5%
	if (distance < 1000) distMult = 0.0;
	else if (distance < 5000) distMult = 3.0 / 100;
	else if (distance < 10000) distMult = 10.0 / 100;
	double delta = distMult * distance;
	
	return delta;
}

#include "Broom.h"
// Принимает: имя транспорта, скорость
Broom::Broom() : VehicleAir("Метла", 20) {}
/*
	Вычисление дельты для расстояния

	Коэффициент сокращения расстояния:
	Увеличивается на 1% за каждую 1000 у.е. расстояния
	Например, для расстояния 5600 коэффициент будет 5%

	При расстоянии в 100 000 мгновенно телепортируется 
	к финишу!?
*/
double Broom::getDeltaDist(const int distance)
{
	double distMult = static_cast<double>(distance / 1000) / 100;
	if (distMult > 0.4) distMult = 0.4;	// добавил от себя (не более 40%)
	double delta = distMult * distance;

	return delta;
}

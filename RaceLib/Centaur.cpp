#include "Centaur.h"

// время отдыха (1 вариант): всегда
const double Centaur::T_REST[]{ 2.0 };
short Centaur::qtyRest = sizeof T_REST / sizeof T_REST[0];

// Принимает: имя транспорта, скорость, время в движении,
// кол-во вариантов отдыха, время отдыха (списком)
Centaur::Centaur() : VehicleLand("Кентавр", 15, 8, qtyRest, T_REST) {}

#include "Camel.h"

// время отдыха (2 варианта): 1 раз, последующие разы
const double Camel::T_REST[]{ 5.0 , 8.0 };
short Camel::qtyRest = sizeof T_REST / sizeof T_REST[0];

// Принимает: имя транспорта, скорость, время в движении,
// кол-во вариантов отдыха, время отдыха (списком)
Camel::Camel() : VehicleLand("Верблюд", 10, 30, qtyRest, T_REST) {}

#include "CamelFast.h"

// время отдыха (3 варианта): 1ый раз, 2ой, последующие разы
const double CamelFast::T_REST[]{ 5.0 , 6.5 , 8.0 };
short CamelFast::qtyRest = sizeof T_REST / sizeof T_REST[0];

// Принимает: имя транспорта, скорость, время в движении,
// кол-во вариантов отдыха, время отдыха (списком)
CamelFast::CamelFast() : VehicleLand("Верблюд-быстроход", 40, 10, qtyRest, T_REST) {}

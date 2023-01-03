#include "Boots.h"

// время отдыха (2 варианта): 1ый раз, последующие разы
const double Boots::T_REST[]{ 10.0 , 5.0 };
short Boots::qtyRest = sizeof T_REST / sizeof T_REST[0];

// Принимает: имя транспорта, скорость, время в движении,
// кол-во вариантов отдыха, время отдыха (списком)
Boots::Boots() : VehicleLand("Ботинки-вездеходы", 6, 60, qtyRest, T_REST) {}

#pragma once
#include "RaceLib.h"

enum RaceType { ON_FOOT = 1, FLYING };    // Тип транспорта

class Vehicle
{
protected:
	Vehicle(const short speed, const char* name);
	const short SPEED;			// скорость
	const char* NAME;			// имя транспорта

public:
	RACER_DLL_API virtual ~Vehicle() = default;
	RACER_DLL_API virtual double timeCalc(const int distance) = 0;
	RACER_DLL_API virtual RaceType getTypeRacer() = 0;
	RACER_DLL_API const char* getNameRacer();
	RACER_DLL_API bool checkIsMembers();
	RACER_DLL_API void setMembers(bool);

private:
	bool members;				// false = претенденты, true - участник гонки
};

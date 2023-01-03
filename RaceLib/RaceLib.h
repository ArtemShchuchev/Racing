#pragma once

#ifdef RaceLib_EXPORTS
#define RACER_DLL_API __declspec(dllexport)
#else
#define RACER_DLL_API __declspec(dllimport)
#endif

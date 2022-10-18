#pragma once

#ifdef COMPILING_DLL
#define SIDESWIPE_API __declspec(dllexport)
#else
#define SIDESWIPE_API __declspec(dllimport)
#endif

#include "tester/Tester.hpp"
#pragma once

#ifdef GE_PLATFORM_WINDOWS
#ifdef COMPILING_DLL
#define SIDESWIPE_API __declspec(dllexport)
#else
#define SIDESWIPE_API __declspec(dllimport)
#endif
#else
	#error Bonfire only supports Windows!
#endif

#include "tester/Tester.hpp"
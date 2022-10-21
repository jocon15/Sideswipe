#pragma once

#include "../pch.hpp"

namespace timing {
	/**
	* Get the current point in time
	* 
	* @return a high resolution timepoint
	*/
	inline std::chrono::high_resolution_clock::time_point TimePoint() {
		return std::chrono::high_resolution_clock::now();
	};
}
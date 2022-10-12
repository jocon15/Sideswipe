#pragma once

#include "../pch.hpp"
#include "../Core.hpp"

// test bonfire input
//#include "Bonfire.hpp"
//#include "Bonfire.hpp"

#ifdef COMPILING_DLL
	#include "Bonfire.hpp"
#else
	#include "../dependencies/Bonfire/Bonfire/include/Bonfire.hpp"
#endif 

//  IT WORKS!!!!



// We might need to put a ifdef conditional here,
// When you are building Sideswipe, you include 
// Bonfire from the repo

// Sideswipe Bonfire include dir needs to be
// ../../../dependencies/Bonfire/Bonfire/include

// but Example, which is the project that is 
// sourcing the error, is trying to include
// sideswipe 

// Example Sideswipe Bonfire include dir needs to be
// ../dependencies/Bonfire/Bonfire/include

// BECAUSE EXAMPLE AND SIDESWIPE HAVE DIFFERENT DIRECTORY STRUCTURES



class SIDESWIPE_API Tester {
public:
	Tester();

	Tester(double epsilonD, float epsilonF);
	~Tester();

	void TestTester();

	void PrintGrouping(std::string group);
	void NotTestable(std::string test);

	void AssertEqual(std::string expected, std::string actual);
	void AssertEqual(int expected, int actual);
	void AssertEqual(double expected, double actual);
	void AssertEqual(float expected, float actual);
	void AssertTrue(bool actual);
	void AssertFalse(bool actual);

private:
	CustomLogger m_logger = CustomLogger();
	double m_epsilonDouble = 0.001;
	float m_epsilonFloat = 0.001f;
	unsigned int m_passCnt = 0;
	unsigned int m_failCnt = 0;

	//bool IsEqual(std::string expected, std::string actual);
	//bool IsEqual(int expected, int actual);
	//bool IsEqual(double expected, double actual);
	//bool IsEqual(float expected, float actual);
	
	bool IsTrue(bool val);
	bool IsFalse(bool val);


	template<typename T>
	void PrintTestPassed(T expected, T actual);

	//void PrintTestPassed(int expected, int actual);
	//void PrintTestPassed(double expected, double actual);
	//void PrintTestPassed(float expected, float actual);
	//void PrintTestPassed(bool expected, bool actual);

	template<typename T>
	void PrintTestFailed(T expected, T actual);
	//void PrintTestFailed(int expected, int actual);
	//void PrintTestFailed(double expected, double actual);
	//void PrintTestFailed(float expected, float actual);
	//void PrintTestFailed(bool expected, bool actual);

	void PrintTestingEnvironment();
	void ResetTerminalColor();
};
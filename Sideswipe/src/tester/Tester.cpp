#include "../../include/tester/Tester.hpp"

// ========== Public Definitions ==========

Tester::Tester(){
	PrintTestingEnvironment();
}

Tester::Tester(double epsilonD, float epsilonF){
	m_epsilonDouble = epsilonD;
	m_epsilonFloat = epsilonF;
	PrintTestingEnvironment();
}

Tester::~Tester(){
	std::cout << std::endl << std::endl;
	std::cout << "Total Tests  : " << m_passCnt + m_failCnt << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "Tests passed : " << m_passCnt << std::endl;
	std::cout << "Tests failed : " << m_failCnt << std::endl;
}

void Tester::TestTester(){
	std::cout << "TestTester not implemented yet" << std::endl;
}

void Tester::PrintGrouping(std::string group)
{
}

void Tester::NotTestable(std::string test)
{
}

void Tester::AssertEqual(std::string expected, std::string actual)
{
}

void Tester::AssertEqual(int expected, int actual)
{
}

void Tester::AssertEqual(double expected, double actual)
{
}

void Tester::AssertEqual(float expected, float actual)
{
}

void Tester::AssertTrue(bool actual)
{
	if (IsTrue(actual)) {
		//you can use it like this
		//PrintTestPassed(true, actual);
		// or
		PrintTestPassed<bool>(true, actual);
		m_passCnt++;
	}
	else {
		PrintTestFailed<bool>(true, actual);
		m_failCnt++;
	}
}

void Tester::AssertFalse(bool actual)
{
}

// =========== Private Definitions ===========

//bool Tester::IsEqual(std::string expected, std::string actual){
//	if (IsEqual(expected, actual)) {
//		PrintTestPassed(expected, actual);
//		m_passCnt++;
//	}
//	else {
//		PrintTestFailed(expected, actual);
//		m_failCnt++;
//	}
//}
//
//bool Tester::IsEqual(int expected, int actual){
//	if (IsEqual(expected, actual)) {
//		PrintTestPassed(expected, actual);
//		m_passCnt++;
//	}
//	else {
//		PrintTestFailed(expected, actual);
//		m_failCnt++;
//	}
//}
//
//bool Tester::IsEqual(double expected, double actual){
//	if (IsEqual(expected, actual)) {
//		PrintTestPassed(expected, actual);
//		m_passCnt++;
//	}
//	else {
//		PrintTestFailed(expected, actual);
//		m_failCnt++;
//	}
//}
//
//bool Tester::IsEqual(float expected, float actual){
//	if (IsEqual(expected, actual)) {
//		PrintTestPassed(expected, actual);
//		m_passCnt++;
//	}
//	else {
//		PrintTestFailed(expected, actual);
//		m_failCnt++;
//	}
//}

bool Tester::IsTrue(bool actual){
	return actual;
}

bool Tester::IsFalse(bool actual) {
	return !actual;
}

//bool Tester::IsFalse(bool actual){
//	if (IsFalse(actual)) {
//		PrintTestPassed(false, actual);
//		m_passCnt++;
//	}
//	else {
//		PrintTestFailed(false, actual);
//		m_failCnt++;
//	}
//}

/*
* 
* It would be nice to have a template here so we only have to have one of these functions
* 
* need to figure out what the errors mean
*/


template<typename T>
void Tester::PrintTestPassed(T expected, T actual) {
	std::stringstream pre;
	pre << "[&2Pass&] [Expected: " << expected << "] [Actual: " << actual << "]" << std::endl;
	//std::string output = "[&2Pass&] [Expected: " + expected + "] [Actual: " + actual + "]";
	std::string output = pre.str();
	m_logger.ToTerminal(output);
}

//void Tester::PrintTestPassed(int expected, int actual)
//{
//}
//
//void Tester::PrintTestPassed(double expected, double actual)
//{
//}
//
//void Tester::PrintTestPassed(float expected, float actual)
//{
//}
//
//void Tester::PrintTestPassed(bool expected, bool actual)
//{
//}
//
template<typename T>
void Tester::PrintTestFailed(T expected, T actual){
	std::stringstream pre;
	pre << "[&4Failed&] [Expected: " << expected << "] [Actual: " << actual << "]" << std::endl;
	//std::string output = "[&2Pass&] [Expected: " + expected + "] [Actual: " + actual + "]";
	std::string output = pre.str();
	m_logger.ToTerminal(output);
}
//
//void Tester::PrintTestFailed(int expected, int actual)
//{
//}
//
//void Tester::PrintTestFailed(double expected, double actual)
//{
//}
//
//void Tester::PrintTestFailed(float expected, float actual)
//{
//}
//
//void Tester::PrintTestFailed(bool expected, bool actual)
//{
//}

void Tester::PrintTestingEnvironment(){
	std::cout << "Testing Environment" << std::endl;
	std::cout << "Epsilon double : " << m_epsilonDouble << std::endl;
	std::cout << "Epsilon float  : " << m_epsilonFloat << std::endl;
	std::cout << std::endl;
}

void Tester::ResetTerminalColor()
{
}

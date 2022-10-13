#include "../../include/tester/Tester.hpp"

namespace sideswipe {

	// ========== Public Definitions ==========

	Tester::Tester() {
		m_startTime = timing::TimePoint();
		PrintTestingEnvironment();
	}

	Tester::Tester(double epsilonD, float epsilonF) {
		m_startTime = timing::TimePoint();
		m_epsilonDouble = epsilonD;
		m_epsilonFloat = epsilonF;
		PrintTestingEnvironment();
	}

	Tester::~Tester() {
		// call the Logger destructor to initiate cleanup
		m_logger.~CustomLogger();

		m_duration = timing::TimePoint() - m_startTime;

		// print the test results
		PrintResults();
	}

	void Tester::TestTester() {
		std::cout << "TestTester not implemented yet" << std::endl;
	}

	void Tester::StartGroup(std::string groupName) {
		m_groupName = groupName;
		m_inGroup = true;
		PrintGroupStart();
	}

	void Tester::EndGroup() {
		m_inGroup = false;
		PrintGroupEnd();
	}

	void Tester::NotTestable(std::string entity) {
		std::stringstream pre;
		if (m_inGroup) {
			pre << "\t";
		}
		pre << "[&6Warning&] [" << entity << " is not testable]";
		std::string output = pre.str();
		m_logger.ToTerminal(output);
	}

	void Tester::AssertEqual(std::string expected, std::string actual) {
		if (IsEqual(expected, actual)) {
			PrintTestPassed<std::string>(expected, actual);
			m_passCnt++;
		}
		else {
			PrintTestFailed<std::string>(expected, actual);
			m_failCnt++;
		}
	}

	void Tester::AssertEqual(int expected, int actual) {
		if (IsEqual(expected, actual)) {
			PrintTestPassed<int>(expected, actual);
			m_passCnt++;
		}
		else {
			PrintTestFailed<int>(expected, actual);
			m_failCnt++;
		}
	}

	void Tester::AssertEqual(double expected, double actual) {
		if (IsEqual(expected, actual)) {
			PrintTestPassed<double>(expected, actual);
			m_passCnt++;
		}
		else {
			PrintTestFailed<double>(expected, actual);
			m_failCnt++;
		}
	}

	void Tester::AssertEqual(float expected, float actual) {
		if (IsEqual(expected, actual)) {
			PrintTestPassed<float>(expected, actual);
			m_passCnt++;
		}
		else {
			PrintTestFailed<float>(expected, actual);
			m_failCnt++;
		}
	}

	void Tester::AssertTrue(bool actual) {
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

	void Tester::AssertFalse(bool actual) {
		if (IsFalse(actual)) {
			PrintTestPassed<bool>(false, actual);
			m_passCnt++;
		}
		else {
			PrintTestFailed<bool>(false, actual);
			m_failCnt++;
		}
	}

	// =========== Private Definitions ===========

	bool Tester::IsEqual(std::string expected, std::string actual) {
		if (expected == actual)
			return true;
		else
			return false;
	}

	bool Tester::IsEqual(int expected, int actual) {
		if (expected == actual)
			return true;
		else
			return false;
	}

	bool Tester::IsEqual(double expected, double actual) {
		if (abs(expected - actual) < m_epsilonDouble)
			return true;
		else
			return false;
	}

	bool Tester::IsEqual(float expected, float actual) {
		if (abs(expected - actual) < m_epsilonFloat)
			return true;
		else
			return false;
	}

	bool Tester::IsTrue(bool actual) {
		return actual;
	}

	bool Tester::IsFalse(bool actual) {
		return !actual;
	}

	template<typename T>
	void Tester::PrintTestPassed(T expected, T actual) {
		std::stringstream pre;
		if (m_inGroup) {
			pre << "\t";
		}
		pre << "[&2Pass&] [Expected: " << expected << "] [Actual: " << actual << "]";
		std::string output = pre.str();
		m_logger.ToTerminal(output);
	}

	template<typename T>
	void Tester::PrintTestFailed(T expected, T actual) {
		std::stringstream pre;
		if (m_inGroup) {
			pre << "\t";
		}
		pre << "[&4Fail&] [Expected: " << expected << "] [Actual: " << actual << "]";
		std::string output = pre.str();
		m_logger.ToTerminal(output);
	}

	void Tester::PrintGroupStart() {
		std::stringstream pre;
		pre << "[Group &3" << m_groupName << "&]";
		std::string output = pre.str();
		m_logger.ToTerminal(output);
	}

	void Tester::PrintGroupEnd() {
		std::stringstream pre;
		pre << "[End &3" << m_groupName << "&]";
		std::string output = pre.str();
		m_logger.ToTerminal(output);
	}

	void Tester::PrintTestingEnvironment() {
		std::cout << "    Testing Environment" << std::endl;
		std::cout << "===========================" << std::endl;
		std::cout << "Epsilon double :    " << m_epsilonDouble << std::endl;
		std::cout << "Epsilon float  :    " << m_epsilonFloat << std::endl;
		std::cout << "===========================" << std::endl << std::endl;
	}

	void Tester::PrintResults() {
		std::cout << std::endl << std::endl;
		std::cout << "      Test Results" << std::endl;
		std::cout << "=======================" << std::endl;
		std::cout << "Total Tests   :    " << m_passCnt + m_failCnt << std::endl;
		std::cout << "-----------------------" << std::endl;
		std::cout << "Tests passed  :    " << m_passCnt << std::endl;
		std::cout << "Tests failed  :    " << m_failCnt << std::endl;
		std::cout << "=======================" << std::endl;
		std::cout << "Elapsed time  : " << m_duration.count() << "s" << std::endl;
		std::cout << "=======================" << std::endl;
	}
}
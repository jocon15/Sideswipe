#include "../../include/tester/Tester.hpp"

namespace ss {

	// ========== Public Definitions ==========

	Tester::Tester() {
		m_testStartTime = timing::TimePoint();
		OutputTestEnvironment();
	}

	Tester::Tester(double epsilonD, float epsilonF) {
		m_testStartTime = timing::TimePoint();
		m_epsilonDouble = epsilonD;
		m_epsilonFloat = epsilonF;
		OutputTestEnvironment();
	}

	Tester::~Tester() {
		m_testElapsedTime = timing::TimePoint() - m_testStartTime;

		// Output the test results
		OutputTestResults();

		// call the Logger destructor to initiate cleanup
		m_logger.~CustomLogger();
	}

	void Tester::TestTester() {
		std::cout << "TestTester not implemented yet" << std::endl;
	}

	void Tester::StartGroup(std::string groupName) {
		m_groupName = groupName;
		m_inGroup = true;
		OutputGroupStart();
		m_groupStartTime = timing::TimePoint();
	}

	void Tester::EndGroup() {
		m_groupElapsedTime = timing::TimePoint() - m_groupStartTime;
		m_inGroup = false;
		OutputGroupEnd();
	}

	void Tester::NotTestable(std::string entity) {
		std::stringstream ss;
		if (m_inGroup) {
			ss << "\t";
		}
		ss << "[&6Warning&] [" << entity << " is not testable]";
		std::string output = ss.str();
		m_logger.ToTerminal(output);
	}

	void Tester::SaveToFile(std::string filepath) {
		m_filepath = filepath;
		m_saveToFile = true;
	}

	void Tester::TestNote(std::string message) {
		std::stringstream ss;
		if (m_inGroup) {
			ss << "\t";
		}
		//ss << "[&8Note&: " << message << "]";
		ss << "[&8" << message << "&]";
		std::string output = ss.str();
		m_logger.ToTerminal(output);

		if (m_saveToFile) {
			m_logger.ToFile(m_filepath, output);
		}
	}

	void Tester::TestPlainText(std::string message) {
		std::stringstream ss;
		if (m_inGroup) {
			ss << "\t";
		}
		ss << message;
		std::string output = ss.str();
		m_logger.ToTerminal(output);

		if (m_saveToFile) {
			m_logger.ToFile(m_filepath, output);
		}
	}

	void Tester::AssertEqual(std::string expected, std::string actual) {
		if (IsEqual(expected, actual)) {
			OutputTestPassed<std::string>(AddQuotations(expected), AddQuotations(actual));
			m_passCnt++;
		}
		else {
			OutputTestFailed<std::string>(AddQuotations(expected), AddQuotations(actual));
			m_failCnt++;
		}
	}

	void Tester::AssertEqual(int expected, int actual) {
		if (IsEqual(expected, actual)) {
			OutputTestPassed<int>(expected, actual);
			m_passCnt++;
		}
		else {
			OutputTestFailed<int>(expected, actual);
			m_failCnt++;
		}
	}

	void Tester::AssertEqual(double expected, double actual) {
		if (IsEqual(expected, actual)) {
			OutputTestPassed<double>(expected, actual);
			m_passCnt++;
		}
		else {
			OutputTestFailed<double>(expected, actual);
			m_failCnt++;
		}
	}

	void Tester::AssertEqual(float expected, float actual) {
		if (IsEqual(expected, actual)) {
			OutputTestPassed<float>(expected, actual);
			m_passCnt++;
		}
		else {
			OutputTestFailed<float>(expected, actual);
			m_failCnt++;
		}
	}

	void Tester::AssertTrue(bool actual) {
		if (IsTrue(actual)) {
			OutputTestPassed<bool>(true, actual);
			m_passCnt++;
		}
		else {
			OutputTestFailed<bool>(true, actual);
			m_failCnt++;
		}
	}

	void Tester::AssertFalse(bool actual) {
		if (IsFalse(actual)) {
			OutputTestPassed<bool>(false, actual);
			m_passCnt++;
		}
		else {
			OutputTestFailed<bool>(false, actual);
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

	template<typename T>
	void Tester::OutputTestPassed(T expected, T actual) {
		std::stringstream ss;
		if (m_inGroup) {
			ss << "\t";
		}
		ss << "[&2Pass&] [Expected: " << expected << "] [Actual: " << actual << "]";
		std::string output = ss.str();
		m_logger.ToTerminal(output);

		if (m_saveToFile) {
			m_logger.ToFile(m_filepath, output);
		}
	}

	template<typename T>
	void Tester::OutputTestFailed(T expected, T actual) {
		std::stringstream ss;
		if (m_inGroup) {
			ss << "\t";
		}
		ss << "[&4Fail&] [Expected: " << expected << "] [Actual: " << actual << "]";
		std::string output = ss.str();
		m_logger.ToTerminal(output);

		if (m_saveToFile) {
			m_logger.ToFile(m_filepath, output);
		}
	}

	void Tester::OutputGroupStart() {
		std::stringstream ss;
		ss << "[Group &3" << m_groupName << "&]";
		std::string output = ss.str();
		m_logger.ToTerminal(output);

		if (m_saveToFile) {
			m_logger.ToFile(m_filepath, output);
		}
	}

	void Tester::OutputGroupEnd() {
		std::stringstream ss;
		ss << "[Elapsed time: " << m_groupElapsedTime.count() << " s]";
		std::string output1 = ss.str();
		m_logger.ToTerminal(output1);

		ss.str(std::string()); // clear the stringstream
		ss << "[End &3" << m_groupName << "&]";
		std::string output2 = ss.str();
		m_logger.ToTerminal(output2);

		if (m_saveToFile) {
			m_logger.ToFile(m_filepath, output1);
			m_logger.ToFile(m_filepath, output2);
		}
	}

	void Tester::OutputTestEnvironment() {
		m_logger.ToTerminal("    Testing Environment");
		m_logger.ToTerminal("===========================");
		m_logger.ToTerminal("Epsilon double : " + std::to_string(m_epsilonDouble));
		m_logger.ToTerminal("Epsilon float  : " + std::to_string(m_epsilonFloat));
		m_logger.ToTerminal("===========================");
		m_logger.ToTerminal("\n");
		
		if (m_saveToFile) {
			m_logger.ToFile(m_filepath, "    Testing Environment");
			m_logger.ToFile(m_filepath, "===========================");
			m_logger.ToFile(m_filepath, "Epsilon double : " + std::to_string(m_epsilonDouble));
			m_logger.ToFile(m_filepath, "Epsilon float  : " + std::to_string(m_epsilonFloat));
			m_logger.ToFile(m_filepath, "===========================");
			m_logger.ToFile(m_filepath, "\n");
		}
	}

	void Tester::OutputTestResults() {
		m_logger.ToTerminal("\n");
		m_logger.ToTerminal("      Test Results");
		m_logger.ToTerminal("=======================");
		m_logger.ToTerminal("Total Tests   :    " + std::to_string(m_passCnt + m_failCnt));
		m_logger.ToTerminal("-----------------------");
		m_logger.ToTerminal("Tests passed  :    " + std::to_string(m_passCnt));
		m_logger.ToTerminal("Tests failed  :    " + std::to_string(m_failCnt));
		m_logger.ToTerminal("=======================");
		m_logger.ToTerminal("Elapsed Time  : " + std::to_string(m_testElapsedTime.count()) + " s");
		m_logger.ToTerminal("=======================");

		if (m_saveToFile) {
			m_logger.ToFile(m_filepath, "\n");
			m_logger.ToFile(m_filepath, "      Test Results");
			m_logger.ToFile(m_filepath, "=======================");
			m_logger.ToFile(m_filepath, "Total Tests   :    " + std::to_string(m_passCnt + m_failCnt));
			m_logger.ToFile(m_filepath, "-----------------------");
			m_logger.ToFile(m_filepath, "Tests passed  :    " + std::to_string(m_passCnt));
			m_logger.ToFile(m_filepath, "Tests failed  :    " + std::to_string(m_failCnt));
			m_logger.ToFile(m_filepath, "=======================");
			m_logger.ToFile(m_filepath, "Elapsed Time  : " + std::to_string(m_testElapsedTime.count()) + " s");
			m_logger.ToFile(m_filepath, "=======================");
		}		
	}
}
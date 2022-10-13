#pragma once

#include "../pch.hpp"
#include "../Core.hpp"
#include "../timing/timing.hpp"

#ifdef COMPILING_DLL
	#include "Bonfire.hpp"
#else
	#include "../dependencies/Bonfire/Bonfire/include/Bonfire.hpp"
#endif 

namespace sideswipe {

	class SIDESWIPE_API Tester {
	public:
		/**
		* Constructor
		*/
		Tester();

		/**
		* Constructor
		*
		* @param epsilonD the epislon used to compare doubles
		* @param epsilonF the epsilon used to compare floats
		*/
		Tester(double epsilonD, float epsilonF);

		/**
		* Destructor
		*/
		~Tester();

		/**
		* Verify the integrity of the tester
		*/
		void TestTester();

		/**
		* Begin a test group
		*
		* @param groupName the name of the new group
		*/
		void StartGroup(std::string groupName);

		/*
		* End a test group
		*/
		void EndGroup();

		/**
		* Provides a visual queue that the test is not testible.
		* Intended to be used inside a group
		*
		* @param test the name of the entity that cannot be tested
		*/
		void NotTestable(std::string entity);

		/**
		* Test the equality of 2 strings
		*
		* @param expected the expected value
		* @param actual the actual value
		*/
		void AssertEqual(std::string expected, std::string actual);

		/**
		* Test the equality of 2 integers
		*
		* @param expected the expected value
		* @param actual the actual value
		*/
		void AssertEqual(int expected, int actual);

		/**
		* Test the equality of 2 doubles
		*
		* @param expected the expected value
		* @param actual the actual value
		*/
		void AssertEqual(double expected, double actual);

		/**
		* Test the equality of 2 floats
		*
		* @param expected the expected value
		* @param actual the actual value
		*/
		void AssertEqual(float expected, float actual);

		/**
		* Test that a boolean is true
		*
		* @param actual the actual value
		*/
		void AssertTrue(bool actual);

		/**
		* Test that a boolean is false
		*
		* @param actual the actual value
		*/
		void AssertFalse(bool actual);

	private:
		CustomLogger m_logger = CustomLogger();
		double m_epsilonDouble = 0.001;
		float m_epsilonFloat = 0.001f;
		unsigned int m_passCnt = 0;
		unsigned int m_failCnt = 0;
		bool m_inGroup = false;
		std::string m_groupName;
		std::chrono::high_resolution_clock::time_point m_startTime;
		std::chrono::duration<float> m_duration;

		bool IsEqual(std::string expected, std::string actual);

		bool IsEqual(int expected, int actual);

		bool IsEqual(double expected, double actual);

		bool IsEqual(float expected, float actual);

		bool IsTrue(bool val);

		bool IsFalse(bool val);

		template<typename T>
		void PrintTestPassed(T expected, T actual);

		template<typename T>
		void PrintTestFailed(T expected, T actual);

		void PrintGroupStart();

		void PrintGroupEnd();

		void PrintTestingEnvironment();

		void PrintResults();
	};
}
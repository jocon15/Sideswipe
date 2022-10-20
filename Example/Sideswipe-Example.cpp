#include "Sideswipe.hpp"


int main(int argc, char* argv[]) {
	sideswipe::Tester tester = sideswipe::Tester();
	tester.SaveToFile("D:/log.txt");
	tester.StartGroup("TestCases");
	tester.AssertTrue(true);
	tester.TestNote("Starting engine");
	tester.AssertEqual("apple", "apple");
	tester.AssertEqual("apple", "orange");
	tester.AssertTrue(true);
	tester.AssertTrue(true);
	tester.AssertTrue(true);
	tester.NotTestable("Iphone");
	tester.AssertTrue(true);
	tester.AssertTrue(true);
	tester.AssertTrue(false);
	tester.AssertTrue(false);
	tester.AssertTrue(false);
	tester.EndGroup();

	return 0;
}
//============================================================================
// Name        : Program5.cpp
//============================================================================

#include <iostream>
#include <stdexcept> // for invalid_argument exception class
#include "Time.h"
using namespace std;

int main() {
	Time firstTime;
	firstTime.printStandard();
	firstTime++;
	firstTime.printUniversal();
	Time secondTime;
	try
	{
		secondTime.setTime(25, 25, 45);
	}
	catch (const invalid_argument& e)
	{
		cerr << e.what() << endl << "Time is: " << secondTime << endl;
	}

	secondTime.setTime(12, 30, 15);
	cout << firstTime << endl;
	cout << firstTime++ << endl;
	cout << firstTime << endl;
	cout << ++firstTime <<endl;
	cout << firstTime << endl;

	return 0;
}

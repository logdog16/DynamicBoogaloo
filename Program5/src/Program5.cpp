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
		cerr << e.what() << endl << "secondTime is: " << secondTime << endl;
	}

	secondTime.setTime(12, 30, 15);
	cout << "Before changes: " << firstTime << endl;
	firstTime++;
	cout << "After PostFix: " << firstTime << endl;
	++firstTime;
	cout <<"After PreFix: " << firstTime << endl;

	firstTime.setTime(6, 59, 59);
	cout << "New First Time: " << firstTime << endl;
	firstTime++;
	cout << "firstTime + 1 Second: " << firstTime << endl;

	if(firstTime == secondTime)
	{
		cout << "Times are equal" << endl;
	}
	if(firstTime != secondTime)
	{
		cout << "Times not equal" << endl;
	}
	if (firstTime < secondTime)
	{
		cout << "firstTime is less than secondTime" << endl;
	}
	if (firstTime <= secondTime)
	{
		cout << "firstTime is less than or equal to secondTime" << endl;
	}
	if (firstTime > secondTime)
	{
		cout << "firstTime is greater than secondTime" << endl;
	}
	if (firstTime >= secondTime)
	{
		cout << "firstTime is greater than or equal to secondTime" << endl;
	}

	cout << "Before adding 181 seconds, secondTime is: "  << secondTime << endl;
	secondTime+= 181;
	cout << "SecondTime is now: " <<  secondTime << endl;

	int timeTester = firstTime;

	cout << "firstTime in seconds from midnight: " << timeTester << endl;

	return 0;
}

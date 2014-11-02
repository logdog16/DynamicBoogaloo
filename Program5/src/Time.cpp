#include <iostream>
#include <ostream>
#include <iomanip>
#include <stdexcept> // for invalid_argument exception class
#include "Time.h"
using namespace std;



// Time constructor initializes each data member to zero.
Time::Time()
{
	hour = minute = second = 0;
} // end Time constructor

// set new Time value using universal time
void Time::setTime( int h, int m, int s )
{
	// validate hour, minute and second
	if ( ( h >= 0 && h < 24 ) && ( m >= 0 && m < 60 ) && ( s >= 0 && s < 60 ) )
	{
		hour = h;
		minute = m;
		second = s;
	} // end if
	else
		throw invalid_argument(
				"hour, minute and/or second was out of range" );

} // end function setTime

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal()
{
	cout << setfill('0') << setw( 2 ) << hour << ":"
			<< setw( 2 ) << minute << ":" << setw( 2 ) << second << endl;
} // end function printUniversal

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard()
{
	cout << ( (hour == 0 || hour == 12 ) ? 12 : hour % 12 ) << ":"
			<< setfill('0') << setw( 2 ) << minute << ":" << setw( 2 )
			<< second << (hour < 12 ? " AM" : " PM" ) << endl;
} // end function printStandard

//Overload the ostream operator
std::ostream &operator<< (std::ostream &out, Time &ourTime)
{

	out << setfill('0') << setw( 2 ) << ourTime.hour << ":"
			<< setw( 2 ) << ourTime.minute << ":" << setw( 2 ) << ourTime.second;
	return out;
}

//Overload the pre decrementation
Time &Time::operator++()
{
	if((this->second) != 60)
	{
		this->second++;
	}
	else
	{
		//Spill over to minute
		this->minute++;
		this->second = 0;

			if(this->minute == 60)
			{
				//Spill over to hours
				this->hour++;
				this->minute = 0;

				if(this->hour == 24)
				{
					//Spill over to new day
					this->hour = 0;
				}
			}
	}
	return *this;
}

//Post decrementing
Time &Time::operator++(int)
{
	static Time temp = *this;

	if((this->second) != 59)
	{
		this->second++;
	}
	else
	{
		this->minute++;
		this->second = 0;

			if(this->minute == 60)
			{
				this->hour++;
				this->minute = 0;

				if(this->hour == 24)
				{
					this->hour = 0;
				}
			}

	}
	//return temp;
	return temp;
}

//Add to seconds
Time Time::operator+=(int secToAdd)
{
	this->second += secToAdd;

	if(this->second > 60)
	{
		this->minute += this->second / 60;
		this->second = this->second % 60;
	}
	return *this;
}

//Convert to int
Time::operator int()
{
	return (this->second + (this->minute * 60) + (this->hour * 60 * 60) );
}

//Check if both are equal
bool  Time::operator==(Time secondTime)
{
	if ((this->hour == secondTime.hour) && (this->minute == secondTime.minute) && (this->second == secondTime.second))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Mare sure they aren't equal
bool  Time::operator!=(Time secondTime)
{
	return !(*this == secondTime);
}
//See if first is less than second time
bool  Time::operator<(Time secondTime)
{
	if (this->hour > secondTime.hour)
	{
		return false;
	}
	else if (this->minute > secondTime.minute)
	{
		return false;
	}
	else if (this->second > secondTime.second)
	{
		return false;
	}
	else
	{
		return true;
	}
}
//Less than or equal to second time
bool  Time::operator<=(Time secondTime)
{
	if ((*this == secondTime) || *this < secondTime)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//See if greater than second time
bool Time::operator>(Time secondTime)
{
	if (this->hour < secondTime.hour)
	{
		return false;
	}
	else if (this->minute < secondTime.minute)
	{
		return false;
	}
	else if (this->second < secondTime.second)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//See if greater than or equal to second time
bool Time::operator>=(Time secondTime)
{
	if ((*this == secondTime) || *this > secondTime)
	{
		return true;
	}
	else
	{
		return false;
	}

}

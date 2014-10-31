#ifndef TIME_H
#define TIME_H

class Time
{
 public:
 Time(); // constructor
 void setTime( int, int, int ); // set hour, minute and second
 void printUniversal(); // print time in universal-time format
 void printStandard(); // print time in standard-time format
 friend std::ostream& operator<< (std::ostream &, Time &);
 Time &operator++();
 Time operator++(int);
 Time operator+=(int);

 private:
 int hour; // 0 - 23 (24-hour clock format)
 int minute; // 0 - 59
 int second; // 0 - 59
 }; // end class Time

#endif

#pragma warning (disable: 4996)
#ifndef __DATE_H
#define __DATE_H

class Date
{
private:
	int day;
	int month;
	int year;

public:
	//c'tor
	Date(int day, int month, int year) :day(day), month(month), year(year) {}

	//gets
	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }
};

#endif // #ifndef __DATE_H

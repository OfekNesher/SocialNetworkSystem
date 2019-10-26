#pragma warning (disable: 4996)
#ifndef __OURTIME_H
#define __OURTIME_H

#include <time.h>
#include <stdio.h> 
#include <iostream>
#include <string>
using namespace std;

class OurTime
{
private:
	time_t currTime;
	string timeAsStr;

public:
	//c'tor
	OurTime();

	//gets
	time_t getcurrTime() const { return currTime; }
	const string getTimeAsStr() const { return timeAsStr; }

	friend int compareTime(const OurTime& time1, const OurTime& time2);
	void show() const;
};

#endif // #ifndef __TIME_H

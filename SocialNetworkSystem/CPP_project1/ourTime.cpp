#include "ourTime.h"

OurTime::OurTime()
{
	time_t rawtime;

	time(&rawtime);
	currTime = rawtime;
	timeAsStr = ctime(&rawtime);
}

int compareTime(const OurTime& time1, const OurTime& time2)
{
	if (difftime(time1.getcurrTime(), time2.getcurrTime()) > 0.0)
		return 1;	//if the first one is bigger
	else if (difftime(time1.getcurrTime(), time2.getcurrTime()) < 0.0)
		return -1;	//if the second one is bigger
	else
		return 0;	//equals
}

void OurTime::show() const
{
	cout << timeAsStr;
}
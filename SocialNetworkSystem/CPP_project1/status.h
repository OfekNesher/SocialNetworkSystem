#pragma warning (disable: 4996)
#ifndef __STATUS_H
#define __STATUS_H

#include <iostream>
using namespace std;
#include "ourTime.h"
#include "color.h"

//abstract class
class Status
{
public:
	enum eStatusType { TEXT, PICTURE, VIDEO, TEXT_AND_PICTURE, TEXT_AND_VIDEO };

	//c'tor
	Status(const string postedBy, const OurTime& time, const string content) : postedBy(postedBy), time(time), content(content) {}
	//d'tor
	virtual ~Status() {}

	//gets
	const string getPostedBy() const { return postedBy; }
	const OurTime& getTime() const { return time; }
	const string getContent() const { return content; }

	virtual void show() const = 0;

	virtual bool operator==(const Status& other) const;
	virtual bool operator!=(const Status& other) const;


protected:
	string postedBy;
	OurTime time;
	string content;

	//copy c'tor
	Status(const Status& other) = default;
};

#endif // __STATUS_H

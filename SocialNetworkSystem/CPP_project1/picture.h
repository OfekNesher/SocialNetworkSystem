#pragma warning (disable: 4996)
#ifndef __PICTURE_H
#define __PICTURE_H

#include "status.h"

class Picture : virtual public Status
{
protected:

	//copy c'tor
	Picture(const Picture& other) = default;

public:
	//c'tor
	Picture(const string postedBy, const OurTime& time, const string content) : Status(postedBy, time, content) {}
	//d'tor
	virtual ~Picture() {}

	virtual void show() const override;

	virtual bool operator==(const Status& other) const override;
	virtual bool operator!=(const Status& other) const override;
};

#endif // __PICTURE_H

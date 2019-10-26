#pragma warning (disable: 4996)
#ifndef __VIDEO_H
#define __VIDEO_H

#include "status.h"

class Video : virtual public Status
{
protected:
	//copy c'tor
	Video(const Video& other) = default;

public:
	//c'tor
	Video(const string postedBy, const OurTime& time, const string content) : Status(postedBy, time, content) {}
	//d'tor
	virtual ~Video() {}

	virtual void show() const override;

	virtual bool operator==(const Status& other) const override;
	virtual bool operator!=(const Status& other) const override;
};

#endif // __VIDEO_H


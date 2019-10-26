#pragma warning (disable: 4996)
#ifndef __TEXT_H
#define __TEXT_H

#include "status.h"

class Text : virtual public Status
{
protected:
	string text;

	//copy c'tor
	Text(const Text& other) = default;

public:
	//c'tor
	Text(const string postedBy, const OurTime& time, const string content, const string text) : Status(postedBy, time, content), text(text) {}
	//d'tor
	virtual ~Text() {}

	//gets
	const string getText() const { return text; }

	virtual void show() const override;

	virtual bool operator==(const Status& other) const override;
	virtual bool operator!=(const Status& other) const override;
};

#endif // __TEXT_H
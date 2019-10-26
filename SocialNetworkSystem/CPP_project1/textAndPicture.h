#pragma warning (disable: 4996)
#ifndef __TEXTANDPICTURE_H
#define __TEXTANDPICTURE_H

#include "text.h"
#include "picture.h"

class TextAndPicture : public Text, public Picture
{
private:
	//copy c'tor
	TextAndPicture(const TextAndPicture& other) = default;

public:
	//c'tor
	TextAndPicture(const string postedBy, const OurTime& time, const string content, const string text) : Status(postedBy, time, content), Text(postedBy, time, content, text), Picture(postedBy, time, content) {}

	virtual void show() const override;

	virtual bool operator==(const Status& other) const override;
	virtual bool operator!=(const Status& other) const override;
};

#endif // __TEXTANDPICTURE_H


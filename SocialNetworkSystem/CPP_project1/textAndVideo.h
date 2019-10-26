#pragma warning (disable: 4996)
#ifndef __TEXTANDVIDEO_H
#define __TEXTANDVIDEO_H

#include "text.h"
#include "video.h"

class TextAndVideo : public Text , public Video
{

private:

	//copy c'tor
	TextAndVideo(const TextAndVideo& other) = default;

public:
	//c'tor
	TextAndVideo(const string postedBy, const OurTime& time, const string content, const string text) : Status(postedBy, time, content),Text(postedBy, time, content,text),Video(postedBy, time, content){}

	virtual void show() const override;

	virtual bool operator==(const Status& other) const override;
	virtual bool operator!=(const Status& other) const override;
};

#endif // __TEXTANDVIDEO_H


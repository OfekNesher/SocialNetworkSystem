#include "textAndVideo.h"

void TextAndVideo::show() const
{
	Video::show();

	cout << "Text: " << text << endl;
}

bool TextAndVideo::operator==(const Status& other) const
{
	return (Text::operator==(other));
}

bool TextAndVideo:: operator!=(const Status& other) const
{
	return !(*this == other);
}
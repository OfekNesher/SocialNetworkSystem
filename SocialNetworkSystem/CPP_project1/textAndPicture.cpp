#include "textAndPicture.h"

void TextAndPicture::show() const
{
	Picture::show();

	cout << "Text: " << text << endl;
}

bool TextAndPicture::operator==(const Status& other) const
{
	return (Text::operator==(other));
}

bool TextAndPicture:: operator!=(const Status& other) const
{
	return !(*this == other);
}
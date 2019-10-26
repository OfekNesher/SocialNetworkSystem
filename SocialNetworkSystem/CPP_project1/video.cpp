#include "video.h"

void Video::show() const
{
	Status::show();

	setTextColor(LIGHTBLUE);
	cout << "Playing the video." << endl;

	setTextColor(LIGHTGREY);
}

bool Video::operator==(const Status& other) const
{
	return (Status::operator==(other));
}

bool Video:: operator!=(const Status& other) const
{
	return !(*this == other);
}
#include "picture.h"

void Picture::show() const
{
	Status::show();

	setTextColor(LIGHTRED);
	cout << "Showing the picture." << endl;

	setTextColor(LIGHTGREY);
}

bool Picture::operator==(const Status& other) const
{
	return (Status::operator==(other));
}

bool Picture:: operator!=(const Status& other) const
{
	return !(*this == other);
 }

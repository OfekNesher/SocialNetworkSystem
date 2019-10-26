#include "status.h"

void Status::show() const
{
	cout << "Posted by: " << postedBy << endl;

	getTime().show();

	cout << "Content: " << content << endl;
}

bool Status::operator==(const Status& other) const
{
	return (content == other.getContent());
}

bool Status::operator!=(const Status& other) const
{
	return !(*this == other);
}

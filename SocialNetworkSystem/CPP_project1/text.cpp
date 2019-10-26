#include "text.h"

void Text::show() const
{
	Status::show();

	cout << "Text: " << text << endl;
}

bool Text::operator==(const Status& other) const
{
	if (!Status::operator==(other))
		return false;

	const Text* temp = dynamic_cast<const Text*>(&other);
	return (text == temp->getText());
}

bool Text::operator!=(const Status& other) const
{
	return !(*this == other);
}

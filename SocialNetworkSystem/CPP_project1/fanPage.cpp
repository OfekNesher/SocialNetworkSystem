#include "fanPage.h"
#include "person.h"

void FanPage::addFan(Person* newFan)
{
	//realloc
	if (allMembers.size() == allMembers.capacity())
		allMembers.reserve(allMembers.size() * 2);

	allMembers.push_back(newFan);
}

void FanPage::addStatus()
{
	Entity::addStatus();
}




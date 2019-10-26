#include "person.h"
#include "fanPage.h"

void Person::addFriend(Person* newFriend, bool flag)
{
	bool fContinue = true;
	vector<Entity*>::iterator itr = allMembers.begin();
	vector<Entity*>::iterator itrEnd = allMembers.end();

	//friend can't be linked to himself
	if (this->getName() == newFriend->getName())
	{
		cout << "Friend can't be linked to himself.\n";
	}
	
	else
	{
		//check whether there is such a friend
		while (fContinue && itr != itrEnd)
		{
			if ((*itr)->getName() == newFriend->getName())
				fContinue = false;

			++itr;
		}
		//if not -> add
		if (fContinue)
		{
			//realloc
			if (allMembers.size() == allMembers.capacity())
				allMembers.reserve(allMembers.size() * 2);

			allMembers.push_back(newFriend);

			//activate the method in reverse
			newFriend->addFriend(this, false);
			cout << this->getName() << " was linked to " << newFriend->getName() << "." << endl;

			//update the most recnet statuses
			if(newFriend->allStatuses.size() > 0)
				addToRecnetStatuses(newFriend);
		}

		else
			if (flag)
				cout << "Both friends are already linked.\n";
	}
}

bool Person::addFanPage(FanPage* newFanPage)
{
	vector<FanPage*>::iterator itr = allFanPages.begin();
	vector<FanPage*>::iterator itrEnd = allFanPages.end();
	bool fContinue = true;

	//search for whether there is such a fan page
	while (fContinue && itr != itrEnd)
	{
		if ((*itr)->getName() == newFanPage->getName())
			fContinue = false;
	}

	//if not -> add
	if (fContinue)
	{
		//realloc
		if (allFanPages.size() == allFanPages.capacity())
			allFanPages.reserve(allFanPages.size() * 2);

		allFanPages.push_back(newFanPage);

		//activate the method in reverse
		newFanPage->addFan(this);
	}

	return fContinue;
}

void Person::addStatus()
{
	vector <Entity*>::iterator itr = allMembers.begin();
	vector <Entity*>::iterator itrEnd = allMembers.end();
	Entity::addStatus();

	//update the most recnet statuses
	for (; itr != itrEnd; ++itr)
		((Person*)(*itr))->updateMostRecentStatuses(allStatuses.back());
}

void Person::updateMostRecentStatuses(Status* newStatus)
{
	int i;

	for (i = MAX_STATUSES; i > 0; i--)
		recentStatuses[i] = recentStatuses[i - 1];

	recentStatuses[0] = newStatus;
}

void Person::showMostRecentStatuses()
{
	int i;
	if (recentStatuses[0] == nullptr)
		cout << "There are no statuses.\n";
	else
	{
		cout << "The most recent statuses are:\n";
		for (i = 0; i < MAX_STATUSES && recentStatuses[i] != nullptr; i++)
			recentStatuses[i]->show();
	}
}

void Person::addToRecnetStatuses(Person* newFriend)
{
	vector <Status*>::iterator itrEnd = newFriend->allStatuses.end();
	vector <Status*>::iterator itr = newFriend->allStatuses.begin();

	int i, k;
	--itrEnd;

	//RecentStatuses array is full
	if (this->getLogNumOfRecentStatuses() == MAX_STATUSES)
	{	
		for (i = 0; i < MAX_STATUSES && itr != itrEnd ; i++)
			if (compareTime(recentStatuses[i]->getTime(),(*itrEnd)->getTime()) == -1)
			{
				//shift
				for (k = MAX_STATUSES; k > 0; k--)
					recentStatuses[k] = recentStatuses[k - 1];

				this->recentStatuses[i] = (*itrEnd);
				--itrEnd;
			}
		//for the first status of newFriend
		if (compareTime(recentStatuses[i]->getTime(), (*itr)->getTime()) == -1)
		{
			//shift
			for (k = MAX_STATUSES; k > 0; k--)
				recentStatuses[k] = recentStatuses[k - 1];

			this->recentStatuses[i] = (*itr);
		}
	}

	//RecentStatuses array is not full
	else
	{
		for (i = 0; i < MAX_STATUSES && itr != itrEnd; i++)
		{
			if (recentStatuses[i] == nullptr)
			{
				this->recentStatuses[i] = (*itrEnd);
				--itrEnd;
			}

			else
			{
				if (compareTime(recentStatuses[i]->getTime(), (*itrEnd)->getTime()) == -1)

				{
					//shift
					for (k = MAX_STATUSES; k > 0; k--)
						recentStatuses[k] = recentStatuses[k - 1];

					this->recentStatuses[i] = (*itrEnd);
					--itrEnd;
				}
			}
		}
		
		//for the first status of newFriend
		if (recentStatuses[i] == nullptr)
		{
			this->recentStatuses[i] = (*itr);
		}
		else
		{
			if (compareTime(recentStatuses[i]->getTime(), (*itr)->getTime()) == -1)
			{
				//shift
				for (k = MAX_STATUSES; k > 0; k--)
					recentStatuses[k] = recentStatuses[k - 1];

				this->recentStatuses[i] = (*itr);
			}
		}
	}
}

int Person::getLogNumOfRecentStatuses() const
{
	int i, count = 0;

	for (i = 0; i < MAX_STATUSES; i++)
		if (recentStatuses[i] != nullptr)
			count++;

	return count;
}

void Person::operator+=(Person& other)
{
	this->addFriend(&other, true);
}

void Person::operator+=(FanPage& other)
{
	this->addFanPage(&other);
}


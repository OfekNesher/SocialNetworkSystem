#include "entity.h"

void Entity::addStatus() 
{
	OurTime time;
	int choice;
	string content;
	string text;

	cout << "Choose one of the status types below:\n0)Text\n1)Picture\n2)Video\n3)Text and picture\n4)Text and video\n";
	cin >> choice;

	Status::eStatusType statusType = Status::eStatusType(choice);
	getchar();
	cout << "Enter content: \n";
	getline(cin, content);
	
	//realloc
	if (allStatuses.size() == allStatuses.capacity())
		allStatuses.reserve(allStatuses.size() * 2);

	if (statusType == Status::TEXT)
	{
		cout << "Enter text: \n";
		getline(cin, text);
		allStatuses.push_back(new Text(this->getName(), time, content, text));
	}

	if (statusType == Status::PICTURE)
		allStatuses.push_back(new Picture(this->getName(), time, content));

	if (statusType == Status::VIDEO)
		allStatuses.push_back(new Video(this->getName(), time, content));

	if (statusType == Status::TEXT_AND_PICTURE)
	{
		cout << "Enter text: \n";
		getline(cin, text);
		allStatuses.push_back(new TextAndPicture(this->getName(), time, content, text));
	}

	if (statusType == Status::TEXT_AND_VIDEO)
	{
		cout << "Enter text: \n";
		getline(cin, text);
		allStatuses.push_back(new TextAndVideo(this->getName(), time, content, text));
	}
}

void Entity::showAllStatuses()
{
	vector <Status*>::iterator itr = allStatuses.begin();
	vector <Status*>::iterator itrEnd = allStatuses.end();

	if (allStatuses.size() == 0)
		cout << this->getName() << " have no statuses." << endl;
	
	else
		for ( ; itr!=itrEnd ; ++itr)
			(*itr)->show();
}

void Entity::showAllMembers()
{
	vector <Entity*>::iterator itr = allMembers.begin();
	vector <Entity*>::iterator itrEnd = allMembers.end();

	if (allMembers.size() == 0)
		cout << this->getName() << " have no members." << endl;
	else
	{
		cout << "All the members of " << this->getName() << " are: " << endl;
		for (; itr != itrEnd; ++itr)
		{
			cout << (*itr)->getName();
			if (itr != itrEnd - 1)
				cout << ", ";
		}
	}

	cout << endl;
}

int Entity::operator>(const Entity& other) const
{
	if (this->allMembers.size() > other.allMembers.size())
		return 1;

	else if (this->allMembers.size() == other.allMembers.size())
		return 0;

	else
		return -1;
}

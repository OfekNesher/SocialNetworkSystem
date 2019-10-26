#include "facebook.h"

Facebook::Facebook()
{
	numOfFriends = 0;
	numOfFanPages = 0;
}

void Facebook::addFriend()
{
	string name;
	int day, month, year;

	getchar();
	cout << "Enter name: \n";
	getline(cin, name);

	//check whether there is such a name
	while (this->isFriendExist(name))
	{
		cout << "This name already exist.\n";
		cout << "Enter another name: \n";
		getline(cin, name);
	}
	
	cout << "Enter birthday(DD MM YYYY): \n";
	cin >> day >> month >> year;
	while (day > 31 || month > 12)
	{
		cout << "Please enter a valid date:" << endl;
		cin >> day >> month >> year;
	}

	Date d(day, month, year);

	//realloc
	if (allEntities.size() == allEntities.capacity())
		allEntities.reserve(allEntities.size() * 2);

	allEntities.push_back(new Person(name, d));

	cout << name << " was added." << endl;
	numOfFriends++;
}

bool Facebook::isFriendExist(const string name) const
{
	vector<Entity*>::const_iterator itr = allEntities.begin();
	vector<Entity*>::const_iterator itrEnd = allEntities.end();
	bool res = false;

	for ( ; itr != itrEnd && !res; ++itr)
	{
		Person* tempPerson = dynamic_cast<Person*>(*itr);
		if (tempPerson)
		{
			if ((*itr)->getName() == name)
				res = true;
		}
	}
	return res;
}

void Facebook::addFanPage()
{
	string name;

	getchar();
	cout << "Enter name: \n";
	getline(cin, name);

	//check whether there is such a name
	while (this->isFanPageExist(name))
	{
		cout << "This name already exist.\n";
		cout << "Enter another name: \n";
		getline(cin, name);
	}

	//realloc
	if (allEntities.size() == allEntities.capacity())
		allEntities.reserve(allEntities.size() * 2);

	allEntities.push_back(new FanPage(name));

	cout << name << " was created." << endl;
	numOfFanPages++;
}

bool Facebook::isFanPageExist(const string name) const
{
	vector<Entity*>::const_iterator itr = allEntities.begin();
	vector<Entity*>::const_iterator itrEnd = allEntities.end();
	bool res = false;

	for ( ; itr != itrEnd && !res; ++itr)
	{
		FanPage* tempFanPage = dynamic_cast<FanPage*>(*itr);
		if (tempFanPage)
		{
			if ((*itr)->getName() == name)
				res = true;
		}
	}
	return res;
}

void Facebook::addStatus()
{
	int choice;

	if (allEntities.size()<1)
		cout << "There are not enough friends / fan pages in the database.\n";
	else
	{
		cout << "Choose one of the options below:\n1) Add status to friend\n2) Add status to fan page\n";
		cin >> choice;
		if (choice == 1)
		{
			if (numOfFriends <1)
				cout << "There are not enough friends in the database.\n";
			else
			{
				this->searchPerson(false)->addStatus();
				cout << "The status was created." << endl;
			}
		}

		if (choice == 2)
		{
			if (numOfFanPages <1)
				cout << "There are not enough fan pages in the database.\n";
			else
			{
				this->searchFanPage(false)->addStatus();
				cout << "The status was created." << endl;
			}
		}
	}
}

void Facebook::showAllStatuses()
{
	int choice;

	if (allEntities.size()<1)
		cout << "There are not enough friends / fan pages in the database.\n";

	else
	{
		cout << "Choose one of the options below:\n1) Show all Statuses of particular friend\n2) Show all Statuses of particular fan page\n";
		cin >> choice;

		if (choice == 1)
		{
			if (numOfFriends < 1)
				cout << "There are not enough friends in the database.\n";
			else
				this->searchPerson(false)->showAllStatuses();
		}

		if (choice == 2)
		{
			if (numOfFanPages < 1)
				cout << "There are not enough fan pages in the database.\n";
			else
				this->searchFanPage(false)->showAllStatuses();
		}
	}
}

Person* Facebook::searchPerson(bool isSecondTime)
{
	vector<Entity*>::const_iterator itr = allEntities.begin();
	vector<Entity*>::const_iterator itrEnd = allEntities.end();
	string name;
	Person* res = nullptr;

	if (!isSecondTime)
	{
		getchar();
		cout << "What is the friend's name?\n";
		getline(cin, name);
	}
	else
	{
		cout << "Which friend do you want to link to him?\n";
		getline(cin, name);
	}

	//check whether there is such a friend
	while (!this->isFriendExist(name))
	{
		cout << "This friend doesn't exist.\n";
		cout << "Enter another friend's name: \n";
		getline(cin, name);
	}
	//search for the friend
	for ( ; itr!=itrEnd; ++itr)
	{
		Person* tempPerson = dynamic_cast<Person*>(*itr);
		if (tempPerson)
		{
			if ((*itr)->getName() == name)
				res = (Person*)(*itr);
		}
	}

	return res;
}

FanPage* Facebook::searchFanPage(bool isSecondTime)
{
	vector<Entity*>::const_iterator itr = allEntities.begin();
	vector<Entity*>::const_iterator itrEnd = allEntities.end();
	string name;
	FanPage* res = nullptr;

	if (!isSecondTime)
	{
		getchar();
		cout << "What is the fan page name?\n";
		getline(cin, name);
	}
	else
	{
		cout << "Which fan page do you want to link to him?\n";
		getline(cin, name);
	}

	//check whether there is such a fan page
	while (!this->isFanPageExist(name))
	{
		cout << "This fan page doesn't exist.\n";
		cout << "Enter another fan page name: \n";
		getline(cin, name);
	}
	//search for the fan page
	for ( ; itr!=itrEnd ; ++itr)
	{
		FanPage* tempFanPage = dynamic_cast<FanPage*>(*itr);
		if (tempFanPage)
		{
			if ((*itr)->getName() == name)
				res = (FanPage*)(*itr);
		}
	}

	return res;
}

void Facebook::linkFriends()
{
	if (numOfFriends < 2)
		cout << "There are not enough friends in the database.\n";
	else
	{
		Person* p1 = searchPerson(false);
		Person* p2 = searchPerson(true);

		p1->addFriend(p2, true);
	}
}

void Facebook::addFanToPage()
{
	if (numOfFriends < 1 || numOfFanPages < 1)
		cout << "There are not enough friends / fan pages in the database.\n";
	else
	{
		bool flag;
		Person* p = searchPerson(false);
		FanPage* f = searchFanPage(true);

		flag = p->addFanPage(f);
		if (flag)
			cout << f->getName() << " was added to entities that interest " << p->getName() << "." << endl;
		else
			cout << p->getName() << " is already fan of " << f->getName() << ".\n";
	}
}

void Facebook::DisplayAllRegisteredEntities()
{
	vector<Entity*>::const_iterator itr = allEntities.begin();
	vector<Entity*>::const_iterator itrEnd = allEntities.end();
	int counter;

	if (numOfFriends == 0)
		cout << "There are no friends.";

	else
	{
		cout << "Friends: " << endl;
		counter = 0;
		for ( ; itr!=itrEnd ; ++itr)
		{
			Person* tempPerson = dynamic_cast<Person*>(*itr);
			if (tempPerson)
			{
				counter++;
				cout << (*itr)->getName();
				if (counter < numOfFriends)
					cout << ", ";
	
			}
		}
	}
	cout << endl;

	//init
	itr = allEntities.begin();
	itrEnd = allEntities.end();

	if (numOfFanPages == 0)
		cout << "There are no fan pages.";
	else
	{
		counter = 0;
		cout << "Fan pages: " << endl;
		for ( ; itr!=itrEnd ; ++itr)
		{
			FanPage* tempFanPage = dynamic_cast<FanPage*>(*itr);
			if (tempFanPage)
			{
				counter++;
				cout << (*itr)->getName();
				if (counter < numOfFanPages)
					cout << ", ";
			}
		}
	}
	cout << endl;
}

void Facebook::DisplayMembersOfParticular()
{
	int choice;

	if (allEntities.size() < 1)
		cout << "There are not enough friends / fan pages in the database.\n";
	else
	{
		cout << "Choose one of the options below:\n1) Show all friends of particular friend\n2) Show all fans of particular fan page\n";
		cin >> choice;

		if (choice == 1)
		{
			if (numOfFriends < 1)
				cout << "There are not enough friends in the database.\n";
			else
			{
				Person* p = searchPerson(false);
				p->showAllMembers();
			}
		}

		if (choice == 2)
		{
			if (numOfFanPages < 1)
				cout << "There are not enough fan pages in the database.\n";
			else
			{
				FanPage* f = searchFanPage(false);
				f->showAllMembers();
			}
		}
	}
}

void Facebook::showMostRecentStatuses()
{
	if (numOfFriends < 1)
		cout << "There are not enough friends in the database.\n";
	else
	{
		Person* p1 = searchPerson(false);
		p1->showMostRecentStatuses();
	}
}

void Facebook::start()
{
	int choice;

	cout << "Welcome to PartzufSefer!\n";

	do
	{
		cout << "Choose one of the options below:\n1) Add friend\n2) Add fan page\n3) Add status to friend / fan page\n"
			<< "4) Show all statuses of friend/ fan page\n5) Link between two friends\n6) Add fan to page\n"
			<< "7) Display all registered entities\n8) Display all members of a particular friend / fans of a particular page\n"
			<< "9) Display the 10 most recent member statuses of a particular friend\n10) ESC\n";

		cin >> choice;

		switch (choice)
		{
		case 1:
			this->addFriend();
			cout << endl;
			break;
		case 2:
			this->addFanPage();
			cout << endl;
			break;
		case 3:
			this->addStatus();
			cout << endl;
			break;
		case 4:
			this->showAllStatuses();
			cout << endl;
			break;
		case 5:
			this->linkFriends();
			cout << endl;
			break;
		case 6:
			this->addFanToPage();
			cout << endl;
			break;
		case 7:
			this->DisplayAllRegisteredEntities();
			cout << endl;
			break;
		case 8:
			this->DisplayMembersOfParticular();
			cout << endl;
			break;
		case 9:
			this->showMostRecentStatuses();
			cout << endl;
			break;
		case 10:
			cout << "Goodbye!\n";
			break;
		}

	} while (choice != ESC);
}


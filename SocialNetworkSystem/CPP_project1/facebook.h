#pragma warning (disable: 4996)
#ifndef __FACEBOOK_H
#define __FACEBOOK_H

#include "person.h"
#include "fanPage.h"

class Facebook
{
private:
	vector<Entity*> allEntities;
	int numOfFriends, numOfFanPages;

	//copy c'tor
	Facebook(const Facebook& other) = default;

	bool isFriendExist(const string name) const;
	bool isFanPageExist(const string name) const;
	Person* searchPerson(bool isSecondTime);
	FanPage* searchFanPage(bool isSecondTime);

public:
	static constexpr int ESC = 10;

	//c'tor
	Facebook();

	void addFriend();
	void addFanPage();
	void addStatus();
	void showAllStatuses();
	void linkFriends();
	void addFanToPage();
	void DisplayAllRegisteredEntities();
	void DisplayMembersOfParticular();
	void showMostRecentStatuses();
	void start();
};

#endif // __FACEBOOK_H
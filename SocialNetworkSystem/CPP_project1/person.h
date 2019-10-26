#pragma warning (disable: 4996)
#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
using namespace std;
#include "entity.h"
#include "date.h"

class FanPage;
class Person : public Entity
{ 
public:
	static constexpr int MAX_STATUSES = 10;
	//c'tor
	Person(const string name, const Date& birthday) : Entity(name), birthday(birthday) {}
	//gets
	const Date& getBirthday() const { return birthday; }

	void addFriend(Person* newFriend, bool flag);
	bool addFanPage(FanPage* newFanPage);
	void addStatus() override;
	void showMostRecentStatuses();

	void operator+=(Person& other);
	void operator+=(FanPage& other);

private:
	Date birthday;
	Status* recentStatuses[MAX_STATUSES] = { nullptr };		// from the newest to the oldest (recentStatuses[0] is the newest)
	vector<FanPage*> allFanPages;

	//copy c'tor
	Person(const Person& other) = default;

	void updateMostRecentStatuses(Status* newStatus);
	void addToRecnetStatuses(Person* newFriend);
	int getLogNumOfRecentStatuses() const;
};

#endif // __PERSON_H
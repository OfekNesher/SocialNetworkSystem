#pragma warning (disable: 4996)
#ifndef __ENTITY_H
#define __ENTITY_H

#include "textAndPicture.h"
#include "textAndVideo.h"
#include <vector>

//abstract class
class Entity
{
protected:
	string name;
	vector <Entity*> allMembers;
	vector <Status*> allStatuses;

	//copy c'tor
	Entity(const Entity& other) = default;

public:
	//c'tor
	Entity(const string name) : name(name) {}
	//d'tor
	virtual ~Entity() {}

	//gets
	const string getName() const { return name; }

	virtual void addStatus() = 0;
	void showAllStatuses();
	void showAllMembers();

	//return 1 if this's number of friends is bigger than other's number of friends, 0 if equals, otherwise -1
	int operator>(const Entity& other) const;
};

#endif // __ENTITY_H

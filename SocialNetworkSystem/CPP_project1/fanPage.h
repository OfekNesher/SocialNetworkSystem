#pragma warning (disable: 4996)
#ifndef __FANPAGE_H
#define __FANPAGE_H

#include "entity.h"

class Person;
class FanPage : public Entity
{
private:
	//copy c'tor
	FanPage(const FanPage& other) = default;
	
	void addFan(Person* newFan);

public:
	//c'tor
	FanPage(const string name) : Entity(name) {}
	void addStatus() override;

	friend class Person;	//provide friendship to Person
};

#endif // __FANPAGE_H

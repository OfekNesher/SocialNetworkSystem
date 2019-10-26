/*********************************************************************************************
Project1
Ofek Nehser & Eliyahu Yohanan
24/12/18
**********************************************************************************************/

#include "facebook.h"

void main()
{
	Facebook facebook;
	facebook.start();

	//Date d(17, 11, 1993);

	//Person p1("ofek", d);
	//Person p2("eli", d);
	//Person p3("lidor", d);
	//FanPage f1("page1");
	//FanPage f2("page2");

	//OurTime time;

	////operator +=
	//p1 += p2;
	//p1 += p3;
	//p1.showAllMembers();	//should show all the firends of p1: eli, lidor

	//p1 += f1;
	//f1.showAllMembers();	//should show all the fans of f1: ofek

	////operator >
	//int compare1 = p1 > p3;
	//cout << compare1 << endl;	//should print '1' because p1 have more friends than p3

	//int compare2 = p2 > p3;
	//cout << compare2 << endl;	//should print '0' because p2 and p3 have the same number of friends

	//int compare3 = f2 > f1;
	//cout << compare3 << endl;	//should print '-1' because f2 have less fans than f1

	////operator == / !=
	//Status* s1 = new Picture("eli", time, "picture1");
	//Status* s2 = new Picture("eli", time, "picture1");
	//Status* s3 = new Text("ofek", time, "text1", "going to the sea.");
	//Status* s4 = new Text("ofek", time, "text1", "having fun.");
	//Status* s5 = new TextAndPicture("ofek", time, "textAndPicture1", "playing football.");
	//Status* s6 = new TextAndPicture("eli", time, "textAndPicture1", "playing football.");

	//bool compare4 = (*s1==*s2);
	//cout << compare4 << endl;	//should print '1' because s1 and s2 have the same content field
	//bool compare5 = (*s3==*s4);
	//cout << compare5 << endl;	//should print '0' because s3 and s4 have different text
	//bool compare6 = (*s3!=*s4);
	//cout << compare6 << endl;	//should print '1' because s3 and s4 have different text
	//bool compare7 = (*s5 == *s6);
	//cout << compare7 << endl;	//should print '1' because s3 and s4 have the same content and text
}
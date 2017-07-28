#include <iostream>
#include <string>

using namespace std;

struct Person
{
	string name;
	Person* ptrFriend; 
};

int main()
{
	Person* personA = new Person;
	Person* personB = new Person;
	Person* personC = new Person;

	personA->name = "Grant";
	personB->name = "Ben";
	personC->name = "Sandy";

	personA->ptrFriend = personB;
	personB->ptrFriend = personC;
	personC->ptrFriend = personA;

	cout << "Person A: " << "\t" << personA->name << ", friend: " << personA->ptrFriend->name << endl;
	cout << "Person B: " << "\t" << personB->name << ", friend: " << personB->ptrFriend->name << endl;
	cout << "Person C: " << "\t" << personC->name << ", friend: " << personC->ptrFriend->name << endl;
	cout << endl << endl;

	int* myInt;
	string* myStr;
	float* myFloat;

	myInt = new int;
	myStr = new string;
	myFloat = new float;

	*myInt = 20;
	*myStr = "Grant";
	*myFloat = 199.99;

	cout << *myInt << "\t" << *myStr << "\t" << *myFloat << endl;

	delete personA;
	delete personB;
	delete personC;
	personA = NULL;
	personB = NULL;
	personC = NULL;
	delete myInt;
	delete myStr;
	delete myFloat;
	myInt = NULL;
	myStr = NULL;
	myFloat = NULL;

	cin.get();
	return 0;
}
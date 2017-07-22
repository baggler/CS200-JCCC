#include <iostream>
#include <string>
using namespace std;

void print(int* x, float* y, string* z);

int main()
{
	using namespace std;
	int interger = 20;
	float floatNumber = 9.99;
	string name = "Bob";
	

	cout << "OUTPUT FROM PROJECT 1\n";
	cout << &interger << " = " << interger << endl;
	cout << &floatNumber << " = " << floatNumber << endl;
	cout << &name << " = " << name << endl << endl;

	print(&interger, &floatNumber, &name);
	cin.get();
	return 0;
}

void print(int* x, float* y, string* z)
{
	using namespace std;
	cout << "OUTPUT FROM PROJECT 3 EDITS\n";
	cout << x << " = " << *x << endl;
	cout << y << " = " << *y << endl;
	cout << z << " = " << *z << endl;
}
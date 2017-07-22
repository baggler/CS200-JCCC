#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string names[] = { "JCCC", "KCKCC", "UMKC", "KU", "MS&T" };

	cout << "Array address: " << names << endl;
	cout << "Item 0 address: " << &names[0] << "\t" << "value: " << names[0] << endl;
	cout << "Item 0 address: " << &names[1] << "\t" << "value: " << names[1] << endl;
	cout << "Item 0 address: " << &names[2] << "\t" << "value: " << names[2] << endl;
	cout << "Item 0 address: " << &names[3] << "\t" << "value: " << names[3] << endl;
	cout << "Item 0 address: " << &names[4] << "\t" << "value: " << names[4] << endl;

	cin.get();
	return 0;
}
#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string items[3];
	string prices[3];
	int arraySize = 3, itemCount = 0;

	for (itemCount = 0; itemCount < arraySize; itemCount++)
	{
		cout << "Enter item name: ";
		cin >> items[itemCount];
		cout << "Enter a price: ";
		cin >> prices[itemCount];
	}
	int counter = 0;
	cout << endl;

	for (counter = 0; counter < itemCount; counter++)
	{
		cout << "Item #" << counter << ": " << items[counter] << ", $" << prices[counter] << endl;
	}
	cin.get();
	cin.get();
	return 0;
}
#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string items[3];
	string prices[3];
	int arraySize = 3, itemCount = 0;

	while (itemCount < arraySize)
	{
		cout << "Enter item name: ";
		cin >> items[itemCount];
		cout << "Enter a price: ";
		cin >> prices[itemCount];
		itemCount++;
	}
	int counter = 0;
	cout << endl;
	while (counter < itemCount)
	{
		cout << "Item #" << counter << ": " << items[counter] << ", $" << prices[counter] << endl;
		counter++;
	}
	cin.get();
	cin.get();
	return 0;
}
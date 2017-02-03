#include <iostream>
#include <string>

int main()
{
	using namespace std;
	// Declared Variables
	float nPriceOfItem;
	string strNameOfCity;
	float nTotalPlusTax;


	cout << "What is the item price: ";
	cin >> nPriceOfItem;

	cout << "What city: ";
	cin >> strNameOfCity;


	if ((strNameOfCity).compare("Olathe") == 0)
	{
		nTotalPlusTax = nPriceOfItem + (nPriceOfItem * .065);
		cout << "Total price is: " << nTotalPlusTax << endl;
	}

	else if ((strNameOfCity).compare("Raytown") == 0)
	{
		nTotalPlusTax = nPriceOfItem + (nPriceOfItem * .08225);
		cout << "Total price is: " << nTotalPlusTax << endl;
	}

	else if ((strNameOfCity).compare("OverlandPark") == 0)
	{
		nTotalPlusTax = nPriceOfItem + (nPriceOfItem * .0935);
		cout << "Total price is: " << nTotalPlusTax << endl;
	}

	else if ((strNameOfCity).compare("Independence") == 0)
	{
		nTotalPlusTax = nPriceOfItem + (nPriceOfItem * .07725);
		cout << "Total price is: " << nTotalPlusTax << endl;
	}

	else
	{
		nTotalPlusTax = nPriceOfItem + (nPriceOfItem * .080);
		cout << "Total price is: $" << nTotalPlusTax << endl;
	}

	cin.get();
	cin.get();
	return 0;
}
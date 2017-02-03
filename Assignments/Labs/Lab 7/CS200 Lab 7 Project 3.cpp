// Grant Haugland
// CS200 LAB 7 PROJECT 3: ADDING CHANGE
// FEB 3, 2017


#include <iostream>
#include <string>

float CountChange(int, int, int, int);

int main()
{
	using namespace std;

	while (true)
	{
		int quarters, dimes, nickels, pennies;

		cout << "How many quarters? ";
		cin >> quarters;

		cout << "How many dimes? ";
		cin >> dimes;

		cout << "How many nickels? ";
		cin >> nickels;

		cout << "How many pennies? ";
		cin >> pennies;

		float money = CountChange(quarters, dimes, nickels, pennies);
		cout << "Money: $" << money << endl;

		cout << endl << endl;
	}

	return 0;
}

float CountChange(int q, int d, int n, int p)
{
	const float quater = .25;
	const float dime = .10;
	const float nickel = .05;
	const float penny = .01;
	float amount = (q * quater) + (d * dime) + (n * nickel) + (p * penny);
	return amount;
}
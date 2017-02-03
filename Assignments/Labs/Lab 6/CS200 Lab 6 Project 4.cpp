#include <iostream>

int main()
{
	using namespace std;
	float startingWage, percentRaisePerYear, adjustedWage;
	int yearsWorked;

	cout << " What is your starting wage? >> ";
	cin >> startingWage;

	cout << "What % of a raise do you get per year? >> ";
	cin >> percentRaisePerYear;
	percentRaisePerYear /= 100;

	cout << "How many years have you worked? >> ";
	cin >> yearsWorked;

	adjustedWage = startingWage;

	for (int i = 0; i < yearsWorked; i++)
	{
		adjustedWage += adjustedWage * percentRaisePerYear;
	}

	cout << "Your new wage is $" << adjustedWage << endl;
	cin.get();
	cin.get();
	return 0;
}
#include <iostream>
int main()
{
	using namespace std;

	int nUserChoice;
	cout << "Please enter a number between 0 and 5: ";
	cin >> nUserChoice;

	while (nUserChoice > 5 || nUserChoice < 0)
	{
		cout << "Invalid entry.  Try again please: ";
		cin >> nUserChoice;
	}

	cout << "Thank you.  Input is valid.\n";
	cout << "Press Enter/Return to exit now!";

	cin.get();
	cin.get();
	return 0;
}

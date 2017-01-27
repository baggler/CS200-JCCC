#include <iostream>
int main()
{
	using namespace std;
	int nSecretNumber = 42;
	int nPlayerGuess;
	int nGuessCount = 1;

	do
	{
		cout << "Please enter your guess: ";
		cin >> nPlayerGuess;
		if (nPlayerGuess < nSecretNumber)
		{
			cout << "Too low!\n";
			nGuessCount++;
		}
		else if (nPlayerGuess > nSecretNumber)
		{
			cout << "Too high!\n";
			nGuessCount++;
		}
	} while (nSecretNumber != nPlayerGuess);

	cout << "\n--------------------------------------------------------------\n";
	cout << endl << "\t\tYou Won in " << nGuessCount << " guesses" << endl;

	cin.get();
	cin.get();
	return 0;
}
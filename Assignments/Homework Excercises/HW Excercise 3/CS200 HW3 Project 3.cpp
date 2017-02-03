#include <iostream>

int main()
{
	using namespace std;

	int nSum = 0;
	bool isDone = false;

	while (isDone == false)
	{
		int nUserNums;
		cout << "Enter a number: ";
		cin >> nUserNums;
		nSum += nUserNums;

		cout << "Type (Q) to quit, or (A) to enter another.\n";
		cout << "Choice: ";
		char choice;
		cin >> choice;

		if (choice == 'Q' || choice == 'q')
			isDone = true;
	}

	cout << "The sum is " << nSum << endl;

	cin.get();
	cin.get();
	return 0;
}
#include <iostream>

int main()
{
	using namespace std;
	bool isDone = false;

	while (isDone == false)
	{
		int nRulerFeet;
		cout << "Enter the amount of feet to display on your ruler: ";
		cin >> nRulerFeet;
		int nRulerInches = nRulerFeet * 12;

		for (int i = 0; i <= nRulerInches; ++i)
		{
			if (i % 12 == 0)
			{
				cout << "|";
			}
			else
			{
				cout << "-";
			}
		}

		//cout << endl;
		cout << "\n\nType (Q) to quit, or (C) for another ruler: ";
		char choice;
		cin >> choice;

		if (choice == 'Q' || choice == 'q')
			isDone = true;

		cout << endl;
	}
	return 0;
}
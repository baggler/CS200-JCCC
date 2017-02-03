#include <iostream>
#include <string>

int main()
{
	using namespace std;
	while (true)
	{
		int nUserInput;
		string strRomanNum;

		cout << "Enter a number between 1 and 5: ";
		cin >> nUserInput;

		if (nUserInput > 5 || nUserInput < 1)
		{
			cout << "Invalid input, try again\n\n";
			continue;
		}

		switch (nUserInput)
		{
		case 1:
			strRomanNum = "I";
			break;
		case 2:
			strRomanNum = "II";
			break;
		case 3:
			strRomanNum = "III";
			break;
		case 4:
			strRomanNum = "IV";
			break;
		case 5:
			strRomanNum = "V";
			break;
		}
		cout << "Roman numeral is: " << strRomanNum << endl << endl;
	}
	return 0;
}
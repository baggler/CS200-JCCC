/*If the user enters 'a' and 'A' the program will say that A comes before a, this is correct.
Each ASCII letter, number, or character is assigned a 7-bit binary number string, the ASCII value
of 'A' is lower then 'a', if you want to see what the value is you can do
cout << int(cLetters1) and get the ASCII value.*/

#include <iostream>
#include <string>

int main() {
	using namespace std;
	char strKeepRunning;
	char cLetter1, cLetter2;
	do{
		cout << endl;
		cout << "Please enter your first letter:  ";
		cin >> cLetter1;
		cout << endl;
		cout << "Please enter your second letter:  ";
		cin >> cLetter2;
		cout << endl;

	
		if (cLetter1 < cLetter2) {
			cout << "The first letter comes first alphabetically\n";
		}
		else if (cLetter1 == cLetter2) {
			cout << "The two letters entered are identical\n";
		}
		else {
			cout << "The second letter comes first alphabetically\n";
		}
		cout << endl;
		cout << "Would you like to check some more letters, Y or N?:\t";
		cin >> strKeepRunning;
	} while (strKeepRunning == 'Y');
	
	cin.get();
	return 0;
}
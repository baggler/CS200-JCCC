/* Program asks for two user input variables and then asks the user what type of mathematical operation
they want to perform on them.  This program uses a do-while loop incase the user wants to perform multiple
operations, it also practices using functions that return values and switch-case statments base on the users
input. */


#include <iostream>
#include <string>
float Addition(float, float);
float Subtraction(float, float);
float Multiplication(float, float);
float Division(float, float);

int main() {
	using namespace std;
	char keeprunning;
	do {
		float nA, nB;
		cout << endl;
		cout << "Enter a value for A: ";
		cin >> nA;
		cout << "Enter a value for B: ";
		cin >> nB;
		cout << endl;
		cout << "Please type of mathematical operation would you like to perform:\n";
		cout << "\t 1. Addition\n";
		cout << "\t 2. Subtraction\n";
		cout << "\t 3. Multiplication\n";
		cout << "\t 4. Division\n\n";

		int nChoice;
		cout << "Please select an operation now: ";
		cin >> nChoice;


		switch (nChoice) {
		case 1:
			float nADD;
			nADD = Addition(nA, nB);
			cout << nA << " + " << nB << " = " << nADD;
			break;
		case 2:
			float nSUB;
			nSUB = Subtraction(nA, nB);
			cout << nA << " - " << nB << " = " << nSUB;
			break;
		case 3:
			float nMULTI;
			nMULTI = Multiplication(nA, nB);
			cout << nA << " * " << nB << " = " << nMULTI;
			break;
		case 4:
			float nDIV;
			nDIV = Division(nA, nB);
			cout << nA << " / " << nB << " = " << nDIV;
			break;
		default:
			cout << "Error, bad input, quitting\n";
		}

		cout << "\n\nWould you like to perform more calculations ? Y/N ";
		cin >> keeprunning;
	} while (keeprunning == 'Y');

	cin.get();

	return 0;
}

float Addition(float x, float y) {
	return x + y;
}
float Subtraction(float x, float y) {
	return x - y;
}
float Multiplication(float x, float y) {
	return x * y;
}
float Division(float x, float y) {
	return x / y;
}
#include <iostream>
#include <string>

int main() {
	using namespace std;
	enum fruit { Apple = 1, Banana, Pear, Strawberry };
	int nUserChoice;

	cout << "What is your favorite fruit?\n" << " 1: Apple\n 2: Banana\n 3: Pear\n 4: Strawberry\n";
	cout << "Please make your selection: ";
	cin >> nUserChoice;

	fruit choice = static_cast<fruit>(nUserChoice);
	
	if (choice == Apple) {
		cout << "\nApples are the best\n";
	}
	else if (choice == Banana) {
		cout << "\nBananas are great\n";
	}
	else if (choice == Pear) {
		cout << "\nPears are tasty\n";
	}
	else if (choice == Strawberry) {
		cout << "\nStrawberries are my favorite too!\n";
	}
	else {
		cout << "\nYou did not enter a valid response!\n";
	}

	cin.get();
	cin.get();
	return 0;
}
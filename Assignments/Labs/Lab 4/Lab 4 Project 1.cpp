#include <iostream>
#include <string>

int main() {
	using namespace std;
	string strHomeTown, strName;

	cout << "What is your home town? \n";
	getline(cin, strHomeTown);

	if (strHomeTown.size() > 6) {
		cout << "\nThat's a long name!\n";
	}

	cout << "\nWhat is your name?\n";
	getline(cin, strName);

	cout << "\nHello, " << strName << " from " << strHomeTown << "!\n";

	cin.get();
	return 0;
}
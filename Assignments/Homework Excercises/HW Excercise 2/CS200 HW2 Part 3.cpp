/*No, the boolean expression that is written in as a condition of a "if" statement cannot be done 
for a variable of type bool.  Bools only accept true and false as initializers or 0 meaning false and any
other value can be used for true.
*/
#include <iostream>
#include <string>

int main() {
	using namespace std;

	int nFeet;
	bool bIsTallEnoughForRide = true;  // tried assining it the value of (feet > 3), compiler did not like that

	cout << "What is your height in feet? ";
	cin >> nFeet;

	if ((nFeet > 3) == bIsTallEnoughForRide) {
		cout << "Permitted to ride the roller coaster!\n";
	}
	else {
		cout << "Too short to ride the roller coaster!\n";
	}

	cin.get();
	cin.get();
	return 0;
}
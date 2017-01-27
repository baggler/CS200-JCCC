#include <iostream>

int main() {
	using namespace std;
	//Decalred Variables
	float nX1 = 5.00;
	float nX2;
	cout << "x1 = " << nX1 << endl << endl;
	cout << "Where is x2?   ";
	cin >> nX2;
	if (nX1 - 5 <= nX2 && nX2 <= nX1 + 5) {
		cout << nX2 << " is within 5 units of x1\n";
	}
	else {
		cout << nX1 << " is to far away....\n";
	}
	cin.get();
	cin.get();

	return 0;
}
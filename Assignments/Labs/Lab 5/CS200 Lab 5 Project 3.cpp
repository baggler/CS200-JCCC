#include <iostream>
int main()
{
	using namespace std;
	int nCounter = 0;
	while (nCounter <= 20) {
		cout << nCounter << " ";
		nCounter += 5;
	}
	cout << endl << endl << "DONE!" << endl;
	
	cin.get();
	return 0;
}
#include <iostream>
int main()
{
	using namespace std;
	int nCountDown = 10;
	while (nCountDown > 0) {
		cout << nCountDown << " ";
		nCountDown--;
	}
	cout << endl << endl << "DONE!" << endl;
	
	cin.get();
	return 0;
}
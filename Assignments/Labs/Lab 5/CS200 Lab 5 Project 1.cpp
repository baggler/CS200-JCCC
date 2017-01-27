#include <iostream>
int main()
{
	using namespace std;
	int nCountUp = 1;
	while (nCountUp < 11) {
		cout << nCountUp << " ";
		++nCountUp;
	}
	cout << endl << endl << "DONE!" << endl;
	
	cin.get();
	return 0;
}
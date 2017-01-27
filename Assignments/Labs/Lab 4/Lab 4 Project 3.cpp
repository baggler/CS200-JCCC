#include <iostream>

int main(){
	using namespace std;
	float nBattery;

	cout << "What is your current battery charge/percentage: ";
	cin >> nBattery;

	if (nBattery >= 75){
		cout << "[****]\n";
	}
	else if (nBattery >= 50)	{
		cout << "[*** ]\n";
	}
	else if (nBattery >= 25)	{
		cout << "[**  ]\n";
	}
	else	{
		cout << "[*   ]n";
	}

	cin.get();
	cin.get();

	return 0;
}
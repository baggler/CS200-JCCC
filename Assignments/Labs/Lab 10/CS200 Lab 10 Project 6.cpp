#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string cities[20];
	int arraySize = 20;
	cities[0] = "Lee' s Summit";
	cities[1] = "Raytown";
	cities[2] = "Independence";
	cities[3] = "Belton";
	int itemCount = 4;

	for (int i = 0; i < itemCount; i++)
	{
		cout << cities[i] << endl;
	}
	cin.get();
	return 0;

}
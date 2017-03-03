#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string names[5] = { "Xia", "Shang", "Zhou", "Qin", "Han" };
	
	for (int arraySize = 0; arraySize < 5; arraySize++)
	{
		cout << names[arraySize] << endl;
	}
	cin.get();
	return 0;
}
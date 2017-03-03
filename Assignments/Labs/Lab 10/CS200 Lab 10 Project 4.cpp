#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string letters[5] = { "A", "B", "C", "D", "E" };
	for (int i = 0; i < 5; i++)
	{
		cout << letters[i] << endl;
	}
	cin.get();
	return 0;

}
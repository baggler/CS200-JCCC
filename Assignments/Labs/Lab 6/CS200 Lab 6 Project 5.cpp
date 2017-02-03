#include <iostream>

int main()
{
	using namespace std;
	int sum = 0;
	cout << "Calculate a sum... ";
	for (int i = 1; i <= 10; i++ )
	{
		cout << i;
		sum += i;
		if (i <= 9)
		{
			cout << " + ";
		}
	}
	cout << "\nSum: " << sum;

	cin.get();
	return 0;
}

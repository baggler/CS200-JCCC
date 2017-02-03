#include <iostream>

int main()
{
	using namespace std;

	for (int i = 50; i > 0; i -= 2)
	{
		cout << i << " ";
	}

	cout << "\n\nPress ENTER/RETURN to EXIT!";
	cin.get();
	return 0;
}
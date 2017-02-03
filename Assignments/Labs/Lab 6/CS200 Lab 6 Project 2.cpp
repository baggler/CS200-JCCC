#include <iostream>

int main()
{
	using namespace std;

	for ( int i = 10; i <= 100; i +=5 )
	{
		cout << i << " ";
	}

	cout << "\n\nPress ENTER/RETURN to EXIT";

	cin.get();
	return 0;
}
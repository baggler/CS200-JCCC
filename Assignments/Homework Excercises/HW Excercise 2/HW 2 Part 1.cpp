#include <iostream>

int main()
{
	using namespace std;
	int nAge;
	float nTicketPrice;

	cout << "Age? ";
	cin >> nAge;

	if (nAge < 13)
	{
		nTicketPrice = 5.00;
	}
	else
	{
		nTicketPrice = 7.00;
	}

	cout << "Ticket price: " << nTicketPrice << endl;

	cin.get();
	cin.get();

	return 0;
}
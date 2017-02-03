// Grant Haugland
// CS200 LAB 7 PROJECT 2: PRICE AND TAX
// FEB 3, 2017

#include <iostream>
#include <iomanip>

float AddTax(float);

int main()
{
	using namespace std;
	float priceOne, priceTwo, priceThree;

	std::cout << std::fixed;
	std::cout << std::showpoint;
	std::cout << std::setprecision(2);

	cout << "Price: $" << 9.99 << " \t with tax: $" << AddTax(9.99) << endl;
	cout << "Price: $" << 19.95 << " \t with tax: $" << AddTax(19.95) << endl;
	cout << "Price: $" << 10.00 << " \t with tax: $" << AddTax(10.00) << endl;

	cin.get();
	return 0;

}

float AddTax(float dollar)
{
	const float tax = .12;
	dollar += dollar * tax;
	return dollar;
}
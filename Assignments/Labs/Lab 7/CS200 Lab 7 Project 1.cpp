// Grant Haugland
// CS200 LAB 7 PROJECT 1: CALLING A FUNCTION
// FEB 3, 2017

#include <iostream>

float PercentToDecimal(float);

int main()
{
	using namespace std;
	float a, b, c;

	a = PercentToDecimal(50);
	b = PercentToDecimal(12.5);
	c = PercentToDecimal(99.99);

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;

	cin.get();
	return 0;

}

float PercentToDecimal(float percentage)
{
	float decimal = percentage / 100;
	return decimal;
}
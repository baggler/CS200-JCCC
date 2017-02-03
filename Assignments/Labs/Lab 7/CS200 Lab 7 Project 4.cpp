// Grant Haugland
// CS200 LAB 7 PROJECT 4: CALCULATE DISTANCE
// FEB 3, 2017

#include <iostream>
#include <string>
#include <cmath> // needed for square root

float GetDistance(float, float, float, float);

int main()
{
	using namespace std;
	while (true)
	{
		float x1, y1, x2, y2;

		cout << "First coordinate pair, enter x and y: ";
		cin >> x1 >> y1;

		cout << "Second coordinate pair, enter x and y: ";
		cin >> x2 >> y2;

		float distance = GetDistance(x1, y1, x2, y2);
		cout << "Distance: " << distance << endl;

		cout << endl << endl;
	}

	return 0;
}

float GetDistance(float x1, float y1, float x2, float y2)
{
	float distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	return distance;
}
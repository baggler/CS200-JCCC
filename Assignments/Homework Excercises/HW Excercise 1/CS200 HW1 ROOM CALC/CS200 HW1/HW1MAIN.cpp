#include <iostream>     		// input/output commands
float AREA(float, float);   		//protype functions
float PERIMETER(float, float);

int main()
{
	using namespace std;
	cout << "ROOM CALCULATOR\n";      // Added a program title

	int i = 1;

	while (i < 3) {
		// Variable declarations
		float width;
		float length;
		cout << "\nRoom " << i << endl << endl;
		// Get user input:
		cout << "Enter the width: ";        // text output
		cin >> width;                       // input from the user
		cout << "Enter the length: ";
		cin >> length;
		AREA(width, length), PERIMETER(width, length);  // Pass User input to functions
		i++;		//increment i and run the loop once more
	}
	cin.get();
	cin.get();
	return 0;
}

float AREA(float X, float Y) {
	using namespace std;
	float area = X * Y;
	cout << endl;
	cout << "Area: " << area << endl;
	return 0;
}

float PERIMETER(float X, float Y) {
	using namespace std;
	float perimeter = 2 * (X + Y);
	cout << "Perimeter: " << perimeter << endl;
	return 0;
}
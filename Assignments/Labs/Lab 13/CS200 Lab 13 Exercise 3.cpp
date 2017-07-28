#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

struct Employee
{
	string name;
};

struct Manager
{
	string name;
	Employee* employees;
	int employeeCount;
};

int main()
{
	srand(time(NULL));
	int size;

	cout << "How many lottery balls?:  ";
	cin >> size;

	int* lotteryNumber;
	lotteryNumber = new int[size];
	for (int i = 0; i < size; i++)
	{
		lotteryNumber[i] = rand() % 100 + 1;
		cout << lotteryNumber[i] << "    ";
	}
	delete[] lotteryNumber;
	return 0;
}
#include <iostream>
#include <string>

int main() {
	using namespace std;
	float nStudentPoints, nTotalPoints;

	cout << "What was your score? ";
	cin >> nStudentPoints;

	cout << "What was the total points possible? ";
	cin >> nTotalPoints;

	float nPercentage = (nStudentPoints / nTotalPoints) * 100;

	cout << "Score: " << nPercentage << "% \t";

	if (nPercentage >= 70) {
		cout << "PASS\n";
	}
	else {
		cout << "FAIL\n";
	}

	cin.get();
	cin.get();
	return 0;
}
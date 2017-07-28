#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	cout << "What word do you want to search for?" << endl;
	cout << ">>";
	string userChoice;
	cin >> userChoice;

	cout << "What word do you want to replace the search word with?" << endl;
	cout << ">>";
	string userReplace;
	cin >> userReplace;

	string buffer;

	ifstream fin;
	fin.open("original_story.txt");

	ofstream fout;
	fout.open("modified_story");
	while (fin >> buffer)
	{
		if (buffer == userChoice)
		{
			fout << userReplace << " ";
		}
		else
		{
			fout << buffer << " ";
		}
	}
	fin.close();
	fout.close();
	return 0;
}
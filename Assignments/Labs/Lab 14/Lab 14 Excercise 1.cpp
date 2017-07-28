#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Option
{
	string title;
	int count;
};

struct Poll
{
	string question;
	Option options[4];
};
int main()
{
	Poll myPoll;

	myPoll.question = "What is the best food?";
	myPoll.options[0].title = "Pizza"; myPoll.options[0].count = 0;
	myPoll.options[1].title = "Veggie Taco"; myPoll.options[1].count = 0;
	myPoll.options[2].title = "Samosas"; myPoll.options[2].count = 0;
	myPoll.options[3].title = "Sushi"; myPoll.options[3].count = 0;

	bool done = false;
	while (!done)
	{
		cout << myPoll.question << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << i << ".   "<< myPoll.options[i].title << endl;
		}

		cout << "What is your selection?" << endl;
		cout << ">>";
		int choice;
		cin >> choice;
		++myPoll.options[choice].count;

		char cont;
		cout << "Do you want to continue (y/n)?" << endl;
		cout << ">>";
		cin >> cont;
		if (cont != 'n')
		{
			continue;
		}
		else if (cont == 'n')
		{
			done = true;
		}
	}
	
	ofstream fout;
	fout.open("results.txt");
	fout << "POLL QUESTION" << endl;
	fout << myPoll.question << endl << endl;
	fout << "RESULTS:" << endl;
	for (int i = 0; i < 4; i++)
	{
		fout << myPoll.options[i].title << "---------" << myPoll.options[i].count << endl;
	}
	fout.close();
	return 0;
}
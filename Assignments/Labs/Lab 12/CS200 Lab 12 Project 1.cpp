#include <iostream>
#include <string>
using namespace std;

struct College
{
	string name;
	string state;

};

struct Student
{
	string name;
	College* ptrSchool;
};

void SetupColleges(College* collegeList);
void SetupStudents(Student* studentList, int studentCount, College* collegeList, int collegeCount);

int main()
{
	College* collegeList;
	collegeList = new College[3];
	SetupColleges(collegeList);

	Student* studentList;
	studentList = new Student[5];
	SetupStudents(studentList, 5, collegeList, 3);

	cout << endl << "ALL STUDENTS:" << endl << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << ".  " << studentList[i].name << "\t" << studentList[i].ptrSchool->name << "\t" << studentList[i].ptrSchool->state << endl;
	}

	cin.get();
	cin.get();

	delete[] collegeList;
	delete[] studentList;

	return 0;
}

void SetupColleges(College* collegeList) 
{
	collegeList[0] = { "JCCC", "KS" },
	collegeList[1] = { "MCCKC", "MO" },
	collegeList[2] = { "KCKCC", "KS" };
}

void SetupStudents(Student* studentList, int studentCount, College* collegeList, int collegeCount)
{
	for (int i = 0; i < studentCount; i++)
	{
		cout << "Student " << i + 1 << "'s name?  ";
		cin >> studentList[i].name;

		cout << "Colleges: " << endl;
		for (int c = 0; c < collegeCount; c++)
		{
			cout << c + 1 << ". " << collegeList[c].name << ", " << collegeList[c].state << endl;
		}

		cout  << "Which college for " << studentList[i].name << " ? " << endl;
		cout << ">>  ";
		
		int index;
		cin >> index;

		studentList[i].ptrSchool = &collegeList[index -1];
	}
}
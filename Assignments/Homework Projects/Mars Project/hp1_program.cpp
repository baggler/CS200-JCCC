// Grant Haugland
// CS 200 @ JCCC SPRING 2017
// MARS PROJECT, DUE 02/24/17

#include "hp1_program.hpp"

/*
MODIFY THIS FILE
*/

#include <iostream>
#include <string>
using namespace std;

/* Menu Functions **********************************************/

/*
DisplayMenu()
Inputs: None
Outputs: None
This function should just display a simple # list and header, such as:
1. Set mission parameters, 2. View parameters, 3. Run simulation, 4. Quit
*/
void Program::DisplayMenu()
{
	cout << "---------------------------\n";
	cout << "     MARS SIMULATION\n";
	cout << "---------------------------\n";
	cout << "1.  Set mission parameters\n";
	cout << "2.  View parameters\n";
	cout << "3.  Run simulation\n";
	cout << "4.  Quit\n";
}

/*
SetParameters()
Inputs: None
Outputs: None
In this function, we will get the user's input for the following fields:
- food grown per day (int)		- cleanup per person per day (int)
- team name	(string)			- team size (int)
- mission length in days (int)	- starting units of food (int)

Create variables for each of these. Prompt the user for each
of these items with a cout command ("please enter ___:"),
and get their input through cin.

Finally, once those are all entered, you will use the following functions
to set these variables in the simulator:
- SetFoodGrown_PerDay(int)		- SetCleanup_PerPersonPerDay(int)
- SetTeamName(string)			- SetTeamSize(int)
- SetMissionLength(int)			- SetFoodCount(int)
*/
void Program::SetParameters()
{
	int foodGrownPerDay, cleanupPerPersonPerDay, teamSize, missionLengthInDays, startingUnitsOfFood;
	string teamName;

	cout << "Please enter the following information\n";
	cout << "Team name (ONE WORD): ";
	cin >> teamName;
	cout << "Team size: ";
	cin >> teamSize;
	cout << "Mission length: ";
	cin >> missionLengthInDays;
	cout << "Food grown per day: ";
	cin >> foodGrownPerDay;
	cout << "Cleanup, per person, per day: ";
	cin >> cleanupPerPersonPerDay;
	cout << "Starting units of food: ";
	cin >> startingUnitsOfFood;

	SetFoodGrown_PerDay(foodGrownPerDay);
	SetCleanup_PerPersonPerDay(cleanupPerPersonPerDay);
	SetTeamName(teamName);
	SetTeamSize(teamSize);
	SetMissionLength(missionLengthInDays);
	SetFoodCount(startingUnitsOfFood);
}

/*
ViewParameters()
Inputs: None
Outputs: None
In this function, you will just display the parameters that were entered
in the SetParameters() function. You can do this by utilizing the "getter"
functions available to the simulation...:
- GetFoodConsumed_PerPersonPerDay()			- GetWasteCreated_PerPersonPerDay()
- GetOxygenCreated_PerDay()					- GetOxygenUsed_PerPersonPerDay()
- GetFoodGrown_PerDay()						- GetCleanup_PerPersonPerDay()
- GetTeamName()								- GetTeamSize()
- GetMissionLength()

All of these functions *return* a value - either ints or strings.
You can cout each of these, like:
cout << GetOxygenUsed_PerPersonPerDay() << endl;

Just display each value, but also make sure to display a label for each.
*/
void Program::ViewParameters()
{
	cout << "Food consumed, per day, per person: " << GetFoodConsumed_PerPersonPerDay() << endl;
	cout << "Waste created, per day, per person: " << GetWasteCreated_PerPersonPerDay() << endl;
	cout << "Oxygen created per day: " << GetOxygenCreated_PerDay() << endl;
	cout << "Oxygen used, per day, per person: " << GetOxygenUsed_PerPersonPerDay() << endl;
	cout << "Food grown per day: " << GetFoodGrown_PerDay() << endl;
	cout << "Cleanup per day, per person: " << GetCleanup_PerPersonPerDay() << endl;
	cout << "Team name: " << GetTeamName() << endl;
	cout << "Team size: " << GetTeamSize() << endl;
	cout << "Mission length: " << GetMissionLength() << endl;
}

/*
AdjustFood()
Inputs: None
Outputs: None
This function deals with the following functions:
- GetFoodGrown_PerDay()		- GetFoodConsumed_PerPersonPerDay()
- GetFoodCount()			- GetTeamSize()

It will calculate the amount of food produced and consumed,
and update the food count.

First, create a temporary local int variable, named something like "foodCount".
Assign it the return value of the GetFoodCount() function.

Then, adjust the food count with the formula:
new food count = old food count + food grown per day - ( food consumed per person per day * team size )

After the calculation, update the food count using SetFoodCount(int).
*/
void Program::AdjustFood()
{
	int foodCount = GetFoodCount();
	foodCount = foodCount + GetFoodGrown_PerDay() - (GetFoodConsumed_PerPersonPerDay() * GetTeamSize());
	SetFoodCount(foodCount);
}

/*
AdjustWaste()
Inputs: None
Outputs: None
This function deals with the following functions:
- GetWasteCount()		- GetWasteCreated_PerPersonPerDay()
- GetTeamSize()			- GetCleanup_PerPersonPerDay()

Create a temporary variable and assign it the value of GetWasteCount().

Calculate the new waste count with the formula:
new waste count = old waste count + (waste created per person per day * team size) - (cleanup per person per day * team size)

After the calculation, update the waste count using SetWasteCount(int).
*/
void Program::AdjustWaste()
{
	int wasteCount = GetWasteCount();
	wasteCount = wasteCount + (GetWasteCreated_PerPersonPerDay() * GetTeamSize()) - (GetCleanup_PerPersonPerDay() * GetTeamSize());
	SetWasteCount(wasteCount);
}

/*
AdjustOxygen()
Inputs: None
Outputs: None
This function deals with the following functions:
- GetOxygenCount()		- GetOxygenCreated_PerDay()
- GetTeamSize()			- GetOxygenUsed_PerPersonPerDay()

Create a temporary variable and assign it the value of GetOxygenCount().

Calculate the new oxygen count with the formula:
new oxygen count = old oxygen count + oxygen created per day - (oxygen used per person per day * team size)

After the calculation, update the oxygen count using SetOxygenCount(int).
*/
void Program::AdjustOxygen()
{
	int oxygenCount = GetOxygenCount();
	oxygenCount = oxygenCount + GetOxygenCreated_PerDay() - (GetOxygenUsed_PerPersonPerDay() * GetTeamSize());
	SetOxygenCount(oxygenCount);
}

/*
RunSimulation()
Inputs: None
Outputs: None
The simulation runs through each day, adjusting values to see if
the astronauts can survive for the set amount of days.
Follow the comments below for the steps.
*/
void Program::RunSimulation()
{
	int day = 1;
	SetOxygenCount(100);
	SetWasteCount(0);

	bool missionSuccess = true;

	while ((day < GetMissionLength()) && (missionSuccess == true))
	{
		AdjustFood();
		AdjustWaste();
		AdjustOxygen();

		cout << "\n****SIMULATION DAY: " << day << " ****\n";
		cout << "-------------------------\n";
		cout << "Food Grown: " << GetFoodGrown_PerDay() << endl;
		cout << "Waste Cleaned: " << " - " << GetCleanup_PerPersonPerDay() << " x " << GetTeamSize() << endl;
		cout << "Oxygen Created: " << GetOxygenCreated_PerDay() << endl;
		cout << "Food Consumed: " << " - " << GetFoodConsumed_PerPersonPerDay() << " x " << GetTeamSize() << endl;
		cout << "Waste Created: " << " + " << GetWasteCreated_PerPersonPerDay() << " x " << GetTeamSize() << endl;
		cout << "Oxygen Consumed: " << " - " << GetOxygenUsed_PerPersonPerDay() << " x " << GetTeamSize() << endl;
		cout << "-----CURRENT AMOUNTS-----\n";
		cout << "     FOOD COUNT: " << GetFoodCount() << endl;
		cout << "     WASTE COUNT: " << GetWasteCount() << endl;
		cout << "     OXYGEN COUNT: " << GetOxygenCount() << endl;

		if (GetFoodCount() < 0)
		{
			cout << "\nTEAM " << GetTeamName() << " HAS RUN OUT OF FOOD!\n";
			missionSuccess = false;
		}

		else if (GetWasteCount() > 20)
		{
			cout << "\nTEAM " << GetTeamName() << " HAS DROWNED IN A SEA OF TRASH!\n";
			missionSuccess = false;
		}

		else if (GetOxygenCount() < 0)
		{
			cout << "\nTEAM " << GetTeamName() << " HAS RUN OUT OF OXYGEN!\n";
			missionSuccess = false;
		}

		else
		{
			day += 1;
		}
	}

	cout << endl << "RESULTS FOR TEAM " << GetTeamName() << endl;

	if (missionSuccess == false)
	{
		cout << "MISSION FAILURE!\n";
	}
	else
	{
		cout << "MISSION SUCCESS!\n";
	}
	cout << endl;
}


/* Utility Functions **********************************************/

/*
GetValidInput(int, int)
Inputs: min (int), max (int)
Outputs: int
This function takes in a minimum and maximum value that
can be entered by the user.

First, prompt the user for input with a cout statement.
Create a variable (int) to store their decision,
and get the user's input with cin.

Then, create a while loop that will keep asking the user
to re-enter their selection, WHILE the input is invalid.

Invalid input is if it is < min or > max.

After the while loop (once the input is valid), return
the variable that is storing the user's choice.
*/
int Program::GetValidInput(int min, int max)
{
	int choice;
	cout << "Enter a choice: ";
	cin >> choice;

	while (choice < min || choice > max)
	{
		cout << "Invalid choice.  Please choose something between " << min << " and " << max << endl;
		cout << "Enter choice: ";
		cin >> choice;
	}
	return choice;
}


/*
DO NOT MODIFY BELOW
*/

/* Setter Functions **********************************************/

void Program::SetFoodGrown_PerDay(int value)
{
	foodGrown_PerDay = value;
}

void Program::SetCleanup_PerPersonPerDay(int value)
{
	cleanup_PerPersonPerDay = value;
}

void Program::SetTeamSize(int value)
{
	teamSize = value;
}

void Program::SetMissionLength(int value)
{
	missionLengthInDays = value;
}

void Program::SetTeamName(string value)
{
	teamName = value;
}

void Program::SetFoodCount(int value)
{
	countFood = value;
}

void Program::SetWasteCount(int value)
{
	countWaste = value;
}

void Program::SetOxygenCount(int value)
{
	countOxygen = value;
}


/* Getter Functions **********************************************/

int Program::GetFoodGrown_PerDay()
{
	return foodGrown_PerDay;
}

int Program::GetCleanup_PerPersonPerDay()
{
	return cleanup_PerPersonPerDay;
}

int Program::GetTeamSize()
{
	return teamSize;
}

int Program::GetMissionLength()
{
	return missionLengthInDays;
}

string Program::GetTeamName()
{
	return teamName;
}

int Program::GetFoodConsumed_PerPersonPerDay()
{
	return foodConsumed_PerPersonPerDay;
}

int Program::GetWasteCreated_PerPersonPerDay()
{
	return wasteCreated_PerPersonPerDay;
}

int Program::GetOxygenUsed_PerPersonPerDay()
{
	return oxygenUsed_PerPersonPerDay;
}

int Program::GetOxygenCreated_PerDay()
{
	return oxygenCreated_PerDay;
}

int Program::GetFoodCount()
{
	return countFood;
}

int Program::GetWasteCount()
{
	return countWaste;
}

int Program::GetOxygenCount()
{
	return countOxygen;
}
/*
DON'T MODIFY THIS FILE
*/

#ifndef _HP1_FUNCTIONS	// Don't allow duplicates
#define _HP1_FUNCTIONS	// Don't allow duplicates

#include <iostream>
#include <string>
using namespace std; 

class Program
{
public:
	Program()
	{
		foodGrown_PerDay = 0;
		cleanup_PerPersonPerDay = 0;
		teamName = "unset";
		teamSize = 0;
		missionLengthInDays = 0;
	}

	void DisplayMenu();
	void SetParameters();
	void ViewParameters();
	void RunSimulation();

	void AdjustFood();
	void AdjustWaste();
	void AdjustOxygen();

	int GetValidInput(int min, int max);

	void SetFoodGrown_PerDay(int value);
	void SetCleanup_PerPersonPerDay(int value);
	void SetTeamSize(int value);
	void SetMissionLength(int value);
	void SetTeamName(string value);

	void SetFoodCount(int value);
	void SetWasteCount(int value);
	void SetOxygenCount(int value);

	int GetFoodGrown_PerDay();
	int GetCleanup_PerPersonPerDay();
	int GetTeamSize();
	int GetMissionLength();
	string GetTeamName();

	int GetFoodConsumed_PerPersonPerDay();
	int GetWasteCreated_PerPersonPerDay();
	int GetOxygenUsed_PerPersonPerDay();
	int GetOxygenCreated_PerDay();

	int GetFoodCount();
	int GetWasteCount();
	int GetOxygenCount();

private:
	// Constant variables for rate of consumption / creation
	const int foodConsumed_PerPersonPerDay = 2;
	const int wasteCreated_PerPersonPerDay = 3;
	const int oxygenUsed_PerPersonPerDay = 2;
	const int oxygenCreated_PerDay = 5;

	// Modifiable variables
	int foodGrown_PerDay;
	int cleanup_PerPersonPerDay;

	// Variables to keep track of current levels
	int countFood;
	int countWaste;
	int countOxygen;

	// Additional mission parameters
	int teamSize;
	int missionLengthInDays;
	string teamName;
};

#endif
/*
MODIFY THIS FILE
*/

#include "hp4_program.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;


//! Initializes the program state.
/**
    - Seed the random number generator:       srand( time( NULL ) );
    - Set the two pointer variables to nullptr; m_locationList and m_team.
    - Set the m_week variable to 0.
    - Call the Setup() function.
*/
Program::Program()
{
	srand (time(NULL));
	m_locationList = nullptr;
	m_team = nullptr;
	m_week = 0;
	Setup();
}

//! Cleans up the program.
/**
    - Call the Cleanup() function.
*/
Program::~Program()
{
	Cleanup();
}

//! Calls functions needed for program setup, and then calls Main().
/**
    - Call SetupDynamicArrays()
    - Call LoadLocations()
    - Call LoadPeople()
    - Call Main()
*/
void Program::Setup()
{
	SetupDynamicArrays();
	LoadLocations();
	LoadPeople();
	Main();
}

//! Cleans up the dynamic memory.
/**
    Safely free the memory allocated by m_team and m_locationList.
*/
void Program::Cleanup()
{
	delete[] m_team;
	delete[] m_locationList;
}

//! Main game loop.
/**
    With the game loop...
        - Increment the week by 1
        - Call DisplayWeekStats()
        - Call UpdateTeam()
        - Call ScavengePhase()
        - Call ZombiePhase()
        - if everyone is dead (call IsEveryoneDead())...
            - done with game loop
        - Call RoundPause()

    - Once the game is over, call DisplaySummary().
*/
void Program::Main()
{
	bool done = false;
	while (!done)
	{
		m_week++;
		DisplayWeekStats();
		UpdateTeam();
		ScavengePhase();
		ZombiePhase();
		if (IsEveryoneDead() == true) {
			done = true;
		}
		else{
			RoundPause();
		}
	} 
	DisplaySummary();
}

//! Display the base's stats and the current week.
/**
    Display the current week, as well as the current ammo and food held by the base.
*/
void Program::DisplayWeekStats()
{
	cout << setfill('-') << setw(80) << "-" << endl;
	cout << setfill('-') << setw(37) << "-";
	cout << " WEEK " << m_week;
	cout << setfill('-') << setw(35) << "-" << endl << endl;
	cout << "BASE STATS" << endl;
	cout << m_base.GetFood() << " unit(s) of food\t" << m_base.GetAmmo() << " unit(s) of ammo" << endl << endl;
}

//! Update the team's hunger and health.
/**
    For each team member:
        - Call their Update() function
        - Look at the person's GetHunger() value, and request that amount of food from the base via TakeFood().
        - Have person Eat() that food.
        - Display that person's stats afterwards.
*/
void Program::UpdateTeam()
{
	cout << "TEAM MEMBER STATS" << endl;
	for (int i = 0; i < m_teamCount; i++) {
		m_team[i].Update();
		m_team[i].Eat(m_base.TakeFood(m_team[i].GetHunger()));
		m_team[i].DisplayStats();
	}
}

//! Get player to choose scavenging locations and update base and team stats.
/**
    - Display a list of all the available locations.
    - Ask the user which 3 locations to scavenge at, get their input.
    - Do input validation to make sure they have selected 3 valid indices.
    - Calculate the total amount of ammo salvaged from all 3 locations.
    - Calculate the total amount of food salvaged from all 3 locations.
    - Display the results - amount of food and ammo scavenged (total of each.)
    - Add that amount of ammo and food back to the base.
*/
void Program::ScavengePhase()
{
	cout << endl;
	bool done = false;
	while (!done)
	{
		cout << "SELECT 3 LOCATIONS TO SCAVENGE" << endl;
		for (int i = 0; i < m_locationCount; i++) {
			cout << i << ".  " << m_locationList[i].GetName() << endl;
		}
		cout << "\n >> ";
		int scav_loc1, scav_loc2, scav_loc3;
		cin >> scav_loc1 >> scav_loc2 >> scav_loc3;
		if ((scav_loc1 < 0 || scav_loc1 >= m_locationCount) || (scav_loc2 < 0 || scav_loc2 >= m_locationCount) || (scav_loc3 < 0 || scav_loc3 >= m_locationCount)) {
			cout << "INPUT INVALID" << endl;
			continue;
		}
		int scav_ammo, scav_food;
		scav_ammo = m_locationList[scav_loc1].GetAmmo() + m_locationList[scav_loc2].GetAmmo() + m_locationList[scav_loc3].GetAmmo();
		scav_food = m_locationList[scav_loc1].GetFood() + m_locationList[scav_loc2].GetFood() + m_locationList[scav_loc3].GetFood();
		cout << endl;
		cout << "RESULTS" << endl;
		cout << scav_ammo << " unit(s) of ammo scavenged" << endl;
		cout << scav_food << " unit(s) of food scavenged" << endl;
		m_base.AddAmmo(scav_ammo);
		m_base.AddFood(scav_food);
		done = true;
	}
}

//! Check for zombie attack, and adjust team health and base stats.
/**
    - Generate a random number between 0 and 3.
    - If the random number is 0, then zombie attack:
        - Randomly select the zombie amount, between 1 and 3.
        - Calculate the total zombie health: 10 x the zombie count.
        - Display a message about the zombie attack, and how many zombies there are.
        - Determine if the base has enough ammo to fend off the zombies.
        - If there is not enough ammo:
            - Display a message that the base is out of ammo.
            - Subtract the amount of ammo the base has from the total zombie health.
            - Base ammo is now 0.
            - Zombies get a chance to attack a person. Randomly select a team member to attack.
            - Display a message of who the zombies attacked.
            - Call that team member's Hurt() function, with a random amount of damage between 10 and 20.
        - If there is enough ammo:
            - Subtract the total zombie health from the ammo count.
            - Display a message that the zombies have been killed, and how much ammo was used (equivalent to total zombie health).
*/
void Program::ZombiePhase()
{
	int zombie_attack = rand() % 4;
	if (zombie_attack == 0) {
		int num_zombies = (1 + (rand() % 3));
		int total_zombie_health = num_zombies * 10;
		cout << endl;
		cout << "ZOMBIE ATTACK!" << endl;
		cout << num_zombies << " zombie(s) attack" << endl;
		if (m_base.GetAmmo() < total_zombie_health) {
			total_zombie_health = total_zombie_health - m_base.GetAmmo();
			m_base.SetAmmo(0);
			cout << "Ran out of ammo!" << endl;
			int random_attack_victim = rand() % (m_teamCount + 1);
			cout << "The zombie(s) have attacked " << m_team[random_attack_victim].GetName() << " !" << endl;
			int random_zombie_dmg = (10 + (rand() % 11));
			m_team[random_attack_victim].Hurt(random_zombie_dmg);
		}
		else{
			m_base.SubtractAmmo(total_zombie_health);
			cout << "Zombie(s) killed " << total_zombie_health << " unit(s) of ammo used." << endl;
		}
	}
}

//! Check if the entire team is dead. If everyone is dead, return true. Otherwise, return false.
/**
    Determine if everybody on the team is dead. If at least one person lives, then this will return false.
    If everybody is dead, return true.

    If everyone is dead, display a message that everyone is dead.

    @return <bool>      true if everyone is dead; false if at least one person is alive.
*/
bool Program::IsEveryoneDead()
{
	for (int i = 0; i < m_teamCount; i++) {
		if (m_team[i].IsDead() == true) {
			cout << "The whole team has died!" << endl;
			return true;
		}
	}
	return false;
}

//! Display the game summary.
/**
    Display the amount of weeks that the team survived.
*/
void Program::DisplaySummary()
{
	cout << "The team survived " << m_week << " weeks!" << endl;
}

//! Ask the user for input before continuing the program execution.
/**
    Ask the user to enter a value before continuing.
    (Can just be a dummy cin into a variable that doesn't do anything.)
*/
void Program::RoundPause()
{ 
	cout << "Continue (y/n): ";
	string choice;
	cin >> choice;
	if (choice == "n") {
		DisplaySummary();
		cout << " Then everyone mysteriously died...";
		cin.get();
		cin.get();
		exit(1);
	}
}


//! Load location information from the locations.txt file.
/**
    Create an ifstream object and open the locations.txt file.

    Create three temporary variables: name (string), ammo (int), food (int).
    Also create a counter variable i (int) and initialize it to 0.

    Create a while loop, while the counter i is less than the location count m_locationCount...
        - Retrieve name, ammo, and food from the input file
        - Setup location #i via its Setup() function.
        - Increment the counter variable i.

    Close the input file when done.
*/
void Program::LoadLocations()
{
	ifstream fin;
	fin.open("locations.txt");
	string name;
	int ammo, food, i = 0;
	while (i < m_locationCount)
	{
		fin >> name;
		fin >> ammo;
		fin >> food;
		m_locationList[i].Setup(name, ammo, food);
		i++;
	}
	fin.close();
}

//! Load a list of names from the names.txt file and randomly assign names to the team.
/**
    Load names:
        - Create an array of strings that will store names that are loaded in. The array size should be 207.
        - Create a counter variable i, initialize it to 0.
        - Create an input file stream, and open names.txt
        - Use a while loop to load data from the input file to the names array
            e.g., while ( input >> names[i] )
        - Within the while loop, increment i by 1.
        - Close the input file once done.

    Assign names to team:
        - For each team member, use the Setup() function.
        - Pass in a random name to the Setup function to assign the person a random name.
*/
void Program::LoadPeople()
{
	string names[207];
	int i = 0; 
	int x = 0;
	ifstream fin;
	fin.open("names.txt");
	if (fin.fail()) {
		cout << "failed to open";
		exit(1);
	}
	while (fin >> names[i])
	{
		i++;
	}
	for (x; x < m_teamCount; x++) {
		int index = rand() % 208;
		m_team[x].Setup(names[index]);
	}
	fin.close();
}

//! Ask the user how many locations and team members are available, and allocate memory for the dynamic arrays.
/**
    Ask the player how many locations and how many team members to have.

    Max location size is 10. Utilize a while loop to validate that the user has entered
    an amount between 0 and 10.

    Team count has to be 1 or more, use a while loop to validate that the user has entered
    an amount greater than 1.

    Afterward, use the m_locationList and m_team pointers to create
    dynamic arrays with the sizes given.
*/
void Program::SetupDynamicArrays()
{
	do
	{
		float user_choice;
		cout << "How many locations (max 10)? ";
		cin >> user_choice;
		m_locationCount = floor(user_choice + .5);
	} while (m_locationCount > 10 || m_locationCount < 2);

	do
	{
		float user_choice;
		cout << "How many people on the team? ";
		cin >> user_choice;
		m_teamCount = floor(user_choice + .5);
	} while (m_teamCount > 199 ||m_teamCount < 1);

	m_locationList = new Location[m_locationCount];
	m_team = new Person[m_teamCount];
}

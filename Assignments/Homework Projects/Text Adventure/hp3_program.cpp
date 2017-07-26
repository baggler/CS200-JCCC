/*
MODIFY THIS FILE
*/

#include "hp3_program.hpp"

#include <iostream>
using namespace std;


/* Setup() - 	Create the list of locations
 *              Allocate needed memory
 * */
void Program::Setup()
{
	locationList = new Location[6];

	locationList[0].name = "You have discovered 'The Altar of Infinite Wisdom'!";
	locationList[0].description = "Floating above the altar is the 'Crystal Skull of Dunn'.  \nIt is believed that the skull holds the secrets of the universe, becareful with that kind of power!";
	
	locationList[1].name = "You have discovered an ancient city!";
	locationList[1].description = "Here lies the 'Lost City of Angkor'. \nYou can move:  *east";
	locationList[1].ptrToEast = &locationList[2];
	locationList[1].ptrToNorth = nullptr;
	locationList[1].ptrToSouth = nullptr;
	locationList[1].ptrToWest = nullptr;

	locationList[2].name = "You have entered 'The Hall of Sacrifice'!";
	locationList[2].description = "The walls of this ancient hall are stained sacrificial blood. \nYou can move:  *west or *south";
	locationList[2].ptrToWest = &locationList[1];
	locationList[2].ptrToSouth = &locationList[4];
	locationList[2].ptrToEast = nullptr;
	locationList[2].ptrToNorth = nullptr;

	locationList[3].name = "This appears to be the legendary 'Temple of Angkor Wat'";
	locationList[3].description = "The god Vishnu, Protector of The World, stands atop this megalithic temple. \nYou can move:  *north, *west, or *south.";
	locationList[3].ptrToNorth = &locationList[0];
	locationList[3].ptrToWest = &locationList[2];
	locationList[3].ptrToSouth = &locationList[5];
	locationList[3].ptrToEast = nullptr;

	locationList[4].name = "Ancient carvings on wall indicate this is the tome of Suryavarman II";
	locationList[4].description = "The ashes of the blood thirsty king Suryavarman II lay here. \nYou can move:  *east or *north.";
	locationList[4].ptrToNorth = &locationList[2];
	locationList[4].ptrToEast = &locationList[5];
	locationList[4].ptrToSouth = nullptr;
	locationList[4].ptrToWest = nullptr;

	locationList[5].name = "You have stumbled up the 'Temple of Bayon'";
	locationList[5].description = "Here lies the holy capital city of Angkor Thom. \nYou can move:  *west or *north.";
	locationList[5].ptrToNorth = &locationList[3];
	locationList[5].ptrToWest = &locationList[4];
	locationList[5].ptrToEast = nullptr;
	locationList[5].ptrToSouth = nullptr;


	ptrEndLocation = &locationList[0];
	ptrCurrentLocation = &locationList[1];

}



/* Cleanup() - 	Clean up memory allocated
 * */
void Program::Cleanup()
{
	
	if (locationList != nullptr){
		delete[] locationList;
	}
}



/* Main() - Main program loop
 * */
void Program::Main()
{
	bool done = false;
	string choice;
	while (!done)
	{		
		DisplayCurrentLocation();
		if (ptrEndLocation == ptrCurrentLocation)
		{
			cout << endl;
			cout << "Congrats on finding the crystal skull!  Goodluck, BYE BYE NOW!" << endl;
			break;
		}
		else {
			choice = GetUserInput();
		}

		if (choice == "n" && ptrCurrentLocation->ptrToNorth != nullptr){
			ptrCurrentLocation = ptrCurrentLocation->ptrToNorth;
		}

		else if (choice == "e" && ptrCurrentLocation->ptrToEast != nullptr) {
			ptrCurrentLocation = ptrCurrentLocation->ptrToEast;
		}

		else if (choice == "w" && ptrCurrentLocation->ptrToWest != nullptr) {
			ptrCurrentLocation = ptrCurrentLocation->ptrToWest;
		}

		else if (choice == "s" && ptrCurrentLocation->ptrToSouth != nullptr) {
			ptrCurrentLocation = ptrCurrentLocation->ptrToSouth;
		}

		else if (choice == "q" || choice == "Q") {
			cout << "Exiting Text Adventure, press enter to close the game";
			done = true;
		}

		else {
			cout << endl << "Invalid move or key stroke" << endl;
		}
		}
	cin.get();
	cin.get();
	}



/* DisplayCurrentLocation() - Use the current location
 *              pointer to display the location's name
 *              and description, as well as which
 *              directions the player can move next.
 * */
void Program::DisplayCurrentLocation()
{
	cout << ptrCurrentLocation->name << endl;
	cout << ptrCurrentLocation->description << endl;

}



/* GetUserInput() - Display the list of options to the
 *                  user, then get their input and return
 *                  their choice.
 * */
string Program::GetUserInput()
{
	string choice;
	cout << endl;
	cout << "OPTIONS: (n)orth, (e)ast, (s)outh, (w)est, (q)uit: ";
	cin >> choice;
	cout << endl;
	return choice;
}



/************************************/
/* Don't modify *********************/
/************************************/

Program::Program()
{
	
    locationList = nullptr;
    ptrCurrentLocation = nullptr;
    Setup();
}

Program::~Program()
{
    Cleanup();
}

//Room takes care of all the Rooms made

///////////////////////////////////////////////////////////////
//TODO:
//-> Create Doors and door connections
//	- Likely each door has it's own number 1-x etc.
//	- Door numbers stem from the original like a tree?
//		- For example if we would make path 1 branch out to 1-x and path 2 branch out to 2-x?
//		- At some point doors have to meet at the final room which would be the boss room so (how would numbering work?)
//-> Create Door Textures Plus Boss Door Texture?
///////////////////////////////////////////////////////////////

using namespace std;
#include "Room.hpp"

///////////////////////////////////////////////////////////////
/* Private Functions */
void Room::initVariables()
{
	//
}

void Room::initRooms()
{
	//
}

void Room::updateRooms()
{
	//
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
/* Functions */
void Room::init()
{
	this->initVariables();
	this->initRooms();
}

void Room::update()
{
	this->updateRooms();
}
///////////////////////////////////////////////////////////////

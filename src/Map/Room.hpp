#ifndef ROOM_HPP
#define ROOM_HPP

class Room
{
	enum RoomList
	{
		SpawnRoom = 0
	};

private:
	//Variables

	//Room Textures
	vector<sf::Texture> RoomTextures;
	sf::Texture RoomTexture;

	//Private Functions
	void initVariables();
	void initRooms();
	void updateRooms();

public:
	//Variables

	//Room
	vector<sf::RectangleShape> Rooms;
	sf::RectangleShape Room;

	//Functions
	void init();
	void update();
};

#endif
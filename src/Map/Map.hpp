#ifndef MAP_HPP
#define MAP_HPP

class Map
{
private:
	//Variables

	//Map Textures
	vector<sf::Texture> MapTextures;
	sf::Texture MapTexture;

	//Private Functions
	void initVariables();
	void initMaps();
	void updateMaps();

public:
	//Variables

	//Map
	vector<sf::RectangleShape> Maps;
	sf::RectangleShape Map;

	//Functions
	void init();
	void update();
};

#endif
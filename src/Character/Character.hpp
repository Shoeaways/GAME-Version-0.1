#ifndef CHARACTER_HPP
#define CHARACTER_HPP

using namespace std;
#include <vector>

/* Class acts as Character Class */

class Character
{
	enum CharacterTextureList
	{
		TestCharacter = 0
	};

private:
	//Variables

	//Character Data
	//Stats
	int CurrentHealthPoints;
	int HealthPoints;
	int AttackDamage;
	int AbilityPower;
	int CurrentStaMANA;
	int StaMANA;
	int StaMANAregen;
	int Speed;
	int Defense;

	//Class, Experience, Skills
	//TODO: Add something about Skills
	int Level;
	int LevelCap;
	int Experience;
	int ExperienceTillNextLevel;
	string Class;

	//Character Texture
	vector<sf::Texture> CharacterTextures;
	sf::Texture CharacterTexture;

	//Private Functions
	void initVariables();
	void initCharacters();
	void updateCharacters();

public:
	//Variables
	float x;
	float y;
	int MovingUp;
	int MovingDown;
	int MovingLeft;
	int MovingRight;
	int CurrentCharacter;

	//Character
	vector<sf::Sprite> Characters;
	sf::Sprite Character;

	//Functions
	void init();
	void update();
};

#endif
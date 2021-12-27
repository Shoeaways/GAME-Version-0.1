#ifndef ENEMIES_HPP
#define ENEMIES_HPP

using namespace std;
#include <vector>

/* Class acts as Enemy Class */

class Enemy
{
	enum EnemyTextureList
	{
		//
	};

private:
	//Variables

	//Enemy Data
	int CurrentHealthPoints;
	int HealthPoints;
	int AttackDamage;
	int AbilityPower;
	int CurrentStaMANA;
	int StaMANA;
	int StaMANAregen;
	int Speed;
	int Defense;
	//TODO: More Data and what not

	//Enemy Texture
	vector<sf::Texture> EnemyTextures;
	sf::Texture EnemyTexture;

	//Private Functions
	void initVariables();
	void initEnemies();
	void updateEnemies();
	//TODO: Spawn Enemies
public:
	//Variables

	//Enemies
	vector<sf::Sprite> Enemies;
	sf::Sprite Enemy;

	//Accessors
	//TODO: Some sort of boolean function (flag) to find if current enemies or # of dungeon bosses != 0 or some certain condition

	//Functions
	void init();
	void update();
};

#endif
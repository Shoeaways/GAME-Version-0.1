#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

using namespace std;
#include "Audio/Audio.hpp"
#include "Character/Character.hpp"
#include "Enemies/Enemies.hpp"
#include "Map/Map.hpp"
#include "Widget/Widget.hpp"
#include <cmath>
#include <direct.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>

/*
	Class acts as the game engine
	Wrapper Class
*/

class Game
{
private:
	//Variables
	int seed;
	int i;
	Audio audio;
	Widget widget;
	Character character;

	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	//Mouse positions
	sf::Vector2i mousePosition;
	sf::Vector2f mousePosView;

	//Game logic
	int score;

	//Private functions
	void initVariables();
	void initConfig();
	void initWindow(int Width, int Height, int vsync, string Display);

	void updateConfig();

public:
	//Variables
	int currentScene;

	//Constructor / Destructors
	/* Only neccessary in this header file since the destructor deletes the entire window */
	Game();
	virtual ~Game();

	//Accessors
	bool Running() const;
	void CurrentScene();

	//Config Values
	//TODO: Add any neccessary or additional configs
	int MasterVolume;
	int SFXVolume;
	int MusicVolume;
	int EffectsVolume;
	bool muteWhenUnfocused = true;
	string DisplayMode;
	int ResolutionWidth;
	int ResolutionHeight;
	//int Brightness;
	int VSync;
	string TextureLevel;

	//Keybinds

	//Functions
	void eventPoll();
	void updateMousePosition();
	void update();

	void renderScene();
	void renderWidgets();
	void renderRoom();
	void renderCharacters();
	void renderEnemies();
	void renderMap();
	void render();
};

#endif
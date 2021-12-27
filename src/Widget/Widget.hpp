#ifndef WIDGET_HPP
#define WIDGET_HPP

using namespace std;
#include "Audio/Audio.hpp"
#include <iostream>
#include <vector>

/* Class containing all objects and functions related to Widgets */

class Widget
{
	enum widgetList
	{
		play = 0,
		settings = 1,
		quit = 2,
		newGame = 3,
		loadGame = 4,
		back = 5,
	};
	enum widgetTexureList
	{
		play_widget = 0,
		play_widget_pressed = 1,
		play_widget_hovered = 2,
		settings_widget = 3,
		settings_widget_pressed = 4,
		settings_widget_hovered = 5,
		quit_widget = 6,
		quit_widget_pressed = 7,
		quit_widget_hovered = 8,
		newGame_widget = 9,
		newGame_widget_pressed = 10,
		newGame_widget_hovered = 11,
		loadGame_widget = 12,
		loadGame_widget_pressed = 13,
		loadGame_widget_hovered = 14,
		back_widget = 15,
		back_widget_pressed = 16,
		back_widget_hovered = 17
	};

	enum sceneList
	{
		menuScene = 0,
		playScene = 1,
		settingsScene = 2,
		blackroundScene = 3
	};
	enum sceneTextureList
	{
		menuSceneTexture = 0,
		blackroundSceneTexture = 1
	};

private:
	//Variables
	int i;
	int videoWidth;
	int videoHeight;
	int mousePosX;
	int mousePosY;
	Audio widgetaudio;

	//Widget Textures
	vector<sf::Texture> widgetTextures;
	sf::Texture widgetTexture;

	//Scene Textures
	vector<sf::Texture> sceneTextures;
	sf::Texture sceneTexture;

	//Cursor Texture
	sf::Texture cursorTexture;

	//Functions
	void initVariables();
	void initScene();
	void initWidgets();
	void initCursor();

	//void updateMousePositions();
	//void updateVideoSize();
	void updateScene();
	void updateWidgets();

public:
	//Variables
	vector<int> AtoB;
	int numWidgets;
	int currScene;
	int changeSceneTo;
	bool quitting_game = false;
	bool checkWidgetPressed = false;
	bool checkWidgetReleased = false;
	bool hoveringOverWidget = false;
	bool hoveringOverWidgetAudio = false;
	bool clickingWidgetAudio = false;

	//Scenes
	vector<sf::RectangleShape> scenes;
	sf::RectangleShape scene;

	//Widgets /* For now it's just rectangle shapes but if you want custom ones, probably use sprites */
	vector<sf::RectangleShape> widgets;
	sf::RectangleShape widget;

	//Cursor
	sf::Sprite cursor;

	//Functions
	void defaultTextures();
	void init(int Height, int Width);
	void updateCursor(int x, int y);
	void update(int Height, int Width, int PosX, int PosY);
};

#endif
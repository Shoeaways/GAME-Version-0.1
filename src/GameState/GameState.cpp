//GameState function to constantly:
//	- Read inputs
//  - Update the game based on inputs
//  - Render the game after
//  - Repeat till closed
//TODO:
//-> Create Save file creater and loader
//-> Design a brightness factor
//-> Create keybinds config portion
//-> Design simple widgets
//		- Settings /* Leave this for last */
//			- General
//			- Graphics
//			- Audio
//			- Controls
//
//-> Detail the Character.cpp and .hpp file
//-> Detail the Enemies.cpp and .hpp file after
//-> Add Bosses to Enemies class or something

using namespace std;
#include "GameState.hpp"
#include "Platform/Platform.hpp"

///////////////////////////////////////////////////////////////
//Private functions
void Game::initVariables()
{
	srand(time(NULL));
	this->window = nullptr;

	i = 0;

	//Game Logic
	this->score = 0;
}

void Game::initConfig()
{
	fstream configFile("Config/config.ini");

	if (configFile.fail())
	{
		cout << "Open file failed" << endl;
		mkdir("Config");
		ofstream createNewconfigFile("Config/config.ini");
		fstream configFile("Config/config.ini");

		MasterVolume = 100;
		createNewconfigFile << "MasterVolume = 100" << endl;
		SFXVolume = 100;
		createNewconfigFile << "SFXVolume = 100" << endl;
		MusicVolume = 100;
		createNewconfigFile << "MusicVolume = 100" << endl;
		EffectsVolume = 100;
		createNewconfigFile << "EffectsVolume = 100" << endl;
		muteWhenUnfocused = true;
		createNewconfigFile << "muteWhenUnfocused = true" << endl;

		DisplayMode = "Windowed";
		createNewconfigFile << "DisplayMode = Windowed" << endl;
		ResolutionWidth = 1280;
		createNewconfigFile << "ResolutionWidth = 1280" << endl;
		ResolutionHeight = 720;
		createNewconfigFile << "ResolutionHeight = 720" << endl;

		VSync = 0;
		createNewconfigFile << "VSync = 0" << endl;

		TextureLevel = "Low";
		createNewconfigFile << "TextureLevel = Low" << endl
							<< endl;

		createNewconfigFile.close();
	}
	else
	{
		string readString;
		string valueString;
		unsigned int x;

		//MasterVolume
		getline(configFile, readString);
		x = readString.find("=");
		valueString = readString.substr(x + 2);
		MasterVolume = stoi(valueString);

		//SFXVolume
		getline(configFile, readString);
		x = readString.find("=");
		valueString = readString.substr(12);
		SFXVolume = stoi(valueString);

		//MusicVolume
		getline(configFile, readString);
		x = readString.find("=");
		valueString = readString.substr(x + 2);
		MusicVolume = stoi(valueString);

		//EffectsVolume
		getline(configFile, readString);
		x = readString.find("=");
		valueString = readString.substr(x + 2);
		EffectsVolume = stoi(valueString);

		//muteWhenUnfocused
		getline(configFile, readString);
		x = readString.find("=");
		valueString = readString.substr(x + 2);
		if (valueString == "false")
		{
			muteWhenUnfocused = false;
		}
		else
		{
			muteWhenUnfocused = true;
		}

		//DisplayMode
		getline(configFile, readString);
		x = readString.find("=");
		valueString = readString.substr(x + 2);
		DisplayMode = valueString;

		//ResolutionWidth
		getline(configFile, readString);
		x = readString.find("=");
		valueString = readString.substr(x + 2);
		ResolutionWidth = stoi(valueString);

		//ResolutionHeight
		getline(configFile, readString);
		x = readString.find("=");
		valueString = readString.substr(x + 2);
		ResolutionHeight = stoi(valueString);

		//VSync
		getline(configFile, readString);
		x = readString.find("=");
		valueString = readString.substr(x + 2);
		VSync = stoi(valueString);

		//TextureLevel
		getline(configFile, readString);
		x = readString.find("=");
		valueString = readString.substr(x + 2);
		TextureLevel = valueString;

#if defined(_DEBUG)
		cout << "Config Settings: " << endl
			 << "MasterVolume: " << MasterVolume << endl
			 << "SFXVolume: " << SFXVolume << endl
			 << "MusicVolume: " << MusicVolume << endl
			 << "EffectsVolume: " << EffectsVolume << endl
			 << "DisplayMode: " << DisplayMode << endl
			 << "ResolutionWidth: " << ResolutionWidth << endl
			 << "ResolutionHeight: " << ResolutionHeight << endl
			 << "VSync: " << VSync << endl
			 << "TextureLevel: " << TextureLevel << endl
			 << endl;
#endif

#if defined(_DEBUG)

#endif

		configFile.close();
	}
}

void Game::initWindow(int Width, int Height, int vsync, string Display)
{
	if (Display == "Windowed")
	{
		this->videoMode.width = Width;
		this->videoMode.height = Height;
		this->window = new sf::RenderWindow(this->videoMode, "Gayme Version: Alpha 0.1", sf::Style::Titlebar | sf::Style::Close);
	}
	else if (Display == "Fullscreen")
	{
		//Sets the window to the monitor size so that it doesn't screw with the stuff behind
		this->videoMode.width = videoMode.getDesktopMode().width;
		this->videoMode.height = videoMode.getDesktopMode().height;
		this->videoMode.bitsPerPixel = 32;
		this->window = new sf::RenderWindow(this->videoMode, "Gayme Version: Alpha 0.1", sf::Style::Fullscreen);
	}

	if (vsync == 0)
	{
		this->window->setVerticalSyncEnabled(false);
	}
	else
	{
		this->window->setVerticalSyncEnabled(true);
	}

	this->window->setFramerateLimit(144);
	this->window->setMouseCursorVisible(false);
}

void Game::updateConfig()
{
	//
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
//Construtors /Destructors
Game::Game()
{
	this->initVariables();
	this->initConfig();
	this->initWindow(ResolutionWidth, ResolutionHeight, VSync, DisplayMode);
	widget.init((videoMode.height * 1.f), (videoMode.width * 1.f));
	audio.init(MasterVolume, SFXVolume, MusicVolume, EffectsVolume);
	character.init();
}

Game::~Game()
{
	delete this->window;
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
//Accessors
bool Game::Running() const
{
	return this->window->isOpen();
}

void Game::CurrentScene()
{
	currentScene = widget.currScene;
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
//Functions
void Game::eventPoll()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::LostFocus:
				if (muteWhenUnfocused == true)
				{
					audio.MuteAllSounds();
				}
				break;
			case sf::Event::GainedFocus:
				audio.UnmuteAllSounds();
				break;
			case sf::Event::MouseButtonPressed:
				if (this->event.mouseButton.button == sf::Mouse::Left)
				{
					widget.checkWidgetPressed = true;
					break;
				}
				else
				{
					break;
				}
			case sf::Event::MouseButtonReleased:
				if (this->event.mouseButton.button == sf::Mouse::Left)
				{
					widget.checkWidgetReleased = true;
					break;
				}
				else
				{
					break;
				}
			case sf::Event::KeyPressed:
				if (this->event.key.code == sf::Keyboard::Escape)
				{
					this->window->close();
					break;
				}
				/* Checks for movement and sets the integer to 1 */
				if (this->event.key.code == sf::Keyboard::W)
				{
					character.MovingUp = 1;
				}
				if (this->event.key.code == sf::Keyboard::A)
				{
					character.MovingLeft = 1;
				}
				if (this->event.key.code == sf::Keyboard::S)
				{
					character.MovingDown = 1;
				}
				if (this->event.key.code == sf::Keyboard::D)
				{
					character.MovingRight = 1;
				}
				break;
			case sf::Event::KeyReleased:
				if (this->event.key.code == sf::Keyboard::W)
				{
					character.MovingUp = 0;
				}
				if (this->event.key.code == sf::Keyboard::A)
				{
					character.MovingLeft = 0;
				}
				if (this->event.key.code == sf::Keyboard::S)
				{
					character.MovingDown = 0;
				}
				if (this->event.key.code == sf::Keyboard::D)
				{
					character.MovingRight = 0;
				}
				break;
			default:
				break;
		}
	}
}

void Game::updateMousePosition()
{
	this->mousePosition = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosition);
	widget.updateCursor(this->mousePosition.x, this->mousePosition.y);
	/* Shows mouse position in console */
	//cout << mousePosView.x << " " << mousePosView.y << endl;
}

void Game::update()
{
	this->eventPoll();
	this->updateMousePosition();
	character.update();
	widget.update((videoMode.height * 1.f), (videoMode.width * 1.f), mousePosition.x, mousePosition.y);
	if (widget.quitting_game == true)
	{
		this->window->close();
	}
	if (widget.hoveringOverWidgetAudio == true)
	{
		audio.playSFXHover();
		widget.hoveringOverWidgetAudio = false;
	}
	else if (widget.clickingWidgetAudio == true)
	{
		audio.playSFXClick();
		widget.clickingWidgetAudio = false;
	}
	this->CurrentScene();
	this->audio.update(currentScene);
}

void Game::renderScene()
{
	this->window->draw(widget.scenes[widget.currScene]);
}

void Game::renderWidgets()
{
	while (widget.numWidgets != 0)
	{
		this->window->draw(widget.widgets[widget.AtoB[i]]);
		++i;
		widget.numWidgets -= 1;
	}
	i = 0;
}

void Game::renderRoom()
{
	//
}

void Game::renderCharacters()
{
	this->window->draw(character.Characters[character.CurrentCharacter]);
}

void Game::renderEnemies()
{
	//
}

void Game::renderMap()
{
	//
}

/* The importance of rendering goes from bottom to top 	*/
/* I.E. we render UI last so that we don't have sprites */
/* overlapping our interface							*/
void Game::render()
{
	//Clear Old Frame
	this->window->clear(sf::Color::White);

	//Draw Scene
	this->renderScene();

	//Draw Objects
	this->renderCharacters();
	//this->renderEnemies();
	//this->window->draw(sprite);

	//Draw UI here (Rendering last puts the object over other items)
	this->renderWidgets();

	this->window->draw(widget.cursor);

	//Display New Frame
	this->window->display();
}
///////////////////////////////////////////////////////////////
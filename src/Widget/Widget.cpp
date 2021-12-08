//Widget takes care of all widget related objects and functions
//TODO:

using namespace std;
#include "Widget.hpp"

///////////////////////////////////////////////////////////////
/* Private Functions */
void Widget::initVariables()
{
	i = 0;
	AtoB = { 0 };
	currScene = 0;
	changeSceneTo = 0;
}

void Widget::initScene()
{
	this->sceneTexture.loadFromFile("content/images/backgrounds/menuBackground.jpg");
	this->sceneTextures.push_back(this->sceneTexture);
	this->scene.setSize({ videoWidth * 1.f, videoHeight * 1.f });
	this->scenes.push_back(this->scene);
	this->scenes.push_back(this->scene);
	this->scenes.push_back(this->scene);

	this->sceneTexture.loadFromFile("content/images/backgrounds/blackround.jpg");
	this->sceneTextures.push_back(this->sceneTexture);
	this->scenes.push_back(this->scene);

	this->scenes[menuScene].setTexture(&this->sceneTextures[menuSceneTexture]);
	this->scenes[playScene].setTexture(&this->sceneTextures[menuSceneTexture]);
	this->scenes[settingsScene].setTexture(&this->sceneTextures[menuSceneTexture]);
	this->scenes[blackroundScene].setTexture(&this->sceneTextures[blackroundSceneTexture]);
}

void Widget::initWidgets()
{
	/* Initializing Play widget */
	this->widgetTexture.loadFromFile("content/images/widgets/play_widget.png");
	this->widgetTextures.push_back(this->widgetTexture);
	this->widgetTexture.loadFromFile("content/images/widgets/play_widget_pressed.png");
	this->widgetTextures.push_back(this->widgetTexture);
	this->widgetTexture.loadFromFile("content/images/widgets/play_widget_hovered.png");
	this->widgetTextures.push_back(this->widgetTexture);
	this->widget.setSize({ (videoWidth / 1.f), (videoHeight / 2.f) });
	this->widget.setScale({ 0.25, 0.25 });
	this->widget.setPosition({ (videoWidth / 2.f) - (this->widget.getSize().x) / 8, (videoHeight / 4.f) - (this->widget.getSize().y) / 8 });
	this->widgets.push_back(this->widget);

	/* Initializing Settings widget */
	this->widgetTexture.loadFromFile("content/images/widgets/settings_widget.png");
	this->widgetTextures.push_back(this->widgetTexture);
	this->widgetTexture.loadFromFile("content/images/widgets/settings_widget_pressed.png");
	this->widgetTextures.push_back(this->widgetTexture);
	this->widgetTexture.loadFromFile("content/images/widgets/settings_widget_hovered.png");
	this->widgetTextures.push_back(this->widgetTexture);
	this->widget.setSize({ (videoWidth / 1.f), (videoHeight / 2.f) });
	this->widget.setScale({ 0.25, 0.25 });
	this->widget.setPosition({ (videoWidth / 2.f) - (this->widget.getSize().x) / 8, (videoHeight / 2.5f) - (this->widget.getSize().y) / 8 });
	this->widgets.push_back(this->widget);

	/* Initializing Quit widget */
	this->widgetTexture.loadFromFile("content/images/widgets/quit_widget.png");
	this->widgetTextures.push_back(this->widgetTexture);
	this->widgetTexture.loadFromFile("content/images/widgets/quit_widget_pressed.png");
	this->widgetTextures.push_back(this->widgetTexture);
	this->widgetTexture.loadFromFile("content/images/widgets/quit_widget_hovered.png");
	this->widgetTextures.push_back(this->widgetTexture);
	this->widget.setSize({ (videoWidth / 1.f), (videoHeight / 2.f) });
	this->widget.setScale({ 0.25, 0.25 });
	this->widget.setPosition({ (videoWidth / 2.f) - (this->widget.getSize().x) / 8, (videoHeight / 1.5f) - (this->widget.getSize().y) / 8 });
	this->widgets.push_back(this->widget);

	/* Initializing newGame and loadGame */
	this->widgetTexture.loadFromFile("content/images/widgets/newGame_widget.png");
	this->widgetTextures.push_back(this->widgetTexture);
	this->widgetTexture.loadFromFile("content/images/widgets/newGame_widget_pressed.png");
	this->widgetTextures.push_back(this->widgetTexture);
	this->widgetTexture.loadFromFile("content/images/widgets/newGame_widget_hovered.png");
	this->widgetTextures.push_back(this->widgetTexture);
	this->widget.setSize({ (videoWidth / 1.f), (videoHeight / 2.f) });
	this->widget.setScale({ 0.39, 0.25 });
	this->widget.setPosition({ (videoWidth / 4.25f) - (this->widget.getSize().x) / (2 * (1 / 0.39f)), (videoHeight / 6.f) - (this->widget.getSize().y) / (2 * (1 / 0.39f)) });
	this->widgets.push_back(this->widget);

	this->widgetTexture.loadFromFile("content/images/widgets/loadGame_widget.png");
	this->widgetTextures.push_back(this->widgetTexture);
	this->widgetTexture.loadFromFile("content/images/widgets/loadGame_widget_pressed.png");
	this->widgetTextures.push_back(this->widgetTexture);
	this->widgetTexture.loadFromFile("content/images/widgets/loadGame_widget_hovered.png");
	this->widgetTextures.push_back(this->widgetTexture);
	this->widget.setSize({ (videoWidth / 1.f), (videoHeight / 2.f) });
	this->widget.setScale({ 0.39, 0.25 });
	this->widget.setPosition({ (videoWidth / 4.25f) - (this->widget.getSize().x) / (2 * (1 / 0.39f)), (videoHeight / 3.f) - (this->widget.getSize().y) / (2 * (1 / 0.39f)) });
	this->widgets.push_back(this->widget);

	/* Initializing Back widget */
	this->widgetTexture.loadFromFile("content/images/widgets/back_widget.png");
	this->widgetTextures.push_back(this->widgetTexture);
	this->widgetTexture.loadFromFile("content/images/widgets/back_widget_pressed.png");
	this->widgetTextures.push_back(this->widgetTexture);
	this->widgetTexture.loadFromFile("content/images/widgets/back_widget_hovered.png");
	this->widgetTextures.push_back(this->widgetTexture);
	this->widget.setSize({ (videoWidth / 1.f), (videoHeight / 2.f) });
	this->widget.setScale({ 0.25, 0.25 });
	this->widget.setPosition({ (videoWidth / 1.2f) - (this->widget.getSize().x) / 8, (videoHeight / 1.15f) - (this->widget.getSize().y) / 8 });
	this->widgets.push_back(this->widget);

	this->widgets[play].setTexture(&this->widgetTextures[play_widget]);
	this->widgets[settings].setTexture(&this->widgetTextures[settings_widget]);
	this->widgets[quit].setTexture(&this->widgetTextures[quit_widget]);
	this->widgets[newGame].setTexture(&this->widgetTextures[newGame_widget]);
	this->widgets[loadGame].setTexture(&this->widgetTextures[loadGame_widget]);
	this->widgets[back].setTexture(&this->widgetTextures[back_widget]);
}

void Widget::initCursor()
{
	this->cursorTexture.loadFromFile("content/images/cursor/Cursor.png");
	this->cursor.setOrigin({ 115, 115 });
	this->cursor.setScale({ 0.11, 0.11 });
	this->cursor.setPosition({ 0, 0 });
	this->cursor.setTexture(this->cursorTexture);
}

void Widget::updateScene()
{
	if (currScene != changeSceneTo)
	{
		//cout << "changeScene not in line with currScene!" << endl;
	}
	else
	{
		switch (currScene)
		{
			case (0):
				numWidgets = 3;
				AtoB = { 0, 1, 2 };
				break;
			case (1):
				numWidgets = 3;
				AtoB = { 3, 4, 5 };
				break;
			case (2):
				numWidgets = 1;
				AtoB = { 5 };
				break;
			case (3):
				numWidgets = 0;
				AtoB = {};
			default:
				//This default should never run
				break;
		}
	}
}

void Widget::updateWidgets()
{
	{
		/* Menu Scene */
		if (currScene == 0)
		{
			if (this->hoveringOverWidget == false)
			{
				if ((mousePosX >= (videoWidth * 0.375)) && (mousePosX <= (videoWidth * 0.625)) && (mousePosY >= (videoHeight * 0.1875)) && (mousePosY <= (videoHeight * 0.3125)))
				{
					this->hoveringOverWidget = true;
					this->hoveringOverWidgetAudio = true;
					this->widgets[play].setTexture(&this->widgetTextures[play_widget_hovered]);
				}
				else if ((mousePosX >= (videoWidth * 0.375)) && (mousePosX <= (videoWidth * 0.625)) && (mousePosY >= (videoHeight * 0.335)) && (mousePosY <= (videoHeight * 0.46)))
				{
					this->hoveringOverWidget = true;
					this->hoveringOverWidgetAudio = true;
					this->widgets[settings].setTexture(&this->widgetTextures[settings_widget_hovered]);
				}
				else if ((mousePosX >= (videoWidth * 0.375)) && (mousePosX <= (videoWidth * 0.625)) && (mousePosY >= (videoHeight * 0.60417)) && (mousePosY <= (videoHeight * 0.72639)))
				{
					this->hoveringOverWidget = true;
					this->hoveringOverWidgetAudio = true;
					this->widgets[quit].setTexture(&this->widgetTextures[quit_widget_hovered]);
				}
				else
				{
					this->defaultTextures();
				}
			}
			else if (this->hoveringOverWidget == true)
			{
				if ((mousePosX >= (videoWidth * 0.375)) && (mousePosX <= (videoWidth * 0.625)) && (mousePosY >= (videoHeight * 0.1875)) && (mousePosY <= (videoHeight * 0.3125)))
				{
					this->widgets[play].setTexture(&this->widgetTextures[play_widget_hovered]);
				}
				else if ((mousePosX >= (videoWidth * 0.375)) && (mousePosX <= (videoWidth * 0.625)) && (mousePosY >= (videoHeight * 0.335)) && (mousePosY <= (videoHeight * 0.46)))
				{
					this->widgets[settings].setTexture(&this->widgetTextures[settings_widget_hovered]);
				}
				else if ((mousePosX >= (videoWidth * 0.375)) && (mousePosX <= (videoWidth * 0.625)) && (mousePosY >= (videoHeight * 0.60417)) && (mousePosY <= (videoHeight * 0.72639)))
				{
					this->widgets[quit].setTexture(&this->widgetTextures[quit_widget_hovered]);
				}
				else
				{
					this->defaultTextures();
					this->hoveringOverWidget = false;
				}
			}
			if (checkWidgetPressed == true)
			{
				/* Checking if Play widget is pressed */
				if ((mousePosX >= (videoWidth * 0.375)) && (mousePosX <= (videoWidth * 0.625)) && (mousePosY >= (videoHeight * 0.1875)) && (mousePosY <= (videoHeight * 0.3125)))
				{
					//cout << "Holding" << endl;
					changeSceneTo = 1;
					this->widgets[play].setTexture(&this->widgetTextures[play_widget_pressed]);
				}
				/* Checking if Settings widget is pressed */
				if ((mousePosX >= (videoWidth * 0.375)) && (mousePosX <= (videoWidth * 0.625)) && (mousePosY >= (videoHeight * 0.3375)) && (mousePosY <= (videoHeight * 0.4597)))
				{
					//cout << "Holding" << endl;
					changeSceneTo = 2;
					this->widgets[settings].setTexture(&this->widgetTextures[settings_widget_pressed]);
				}
				/* Checking if Quit widget is pressed */
				if ((mousePosX >= (videoWidth * 0.375)) && (mousePosX <= (videoWidth * 0.625)) && (mousePosY >= (videoHeight * 0.60417)) && (mousePosY <= (videoHeight * 0.72639)))
				{
					//cout << "Holding" << endl;
					quitting_game = true;
					this->widgets[quit].setTexture(&this->widgetTextures[quit_widget_pressed]);
				}
			}
			if ((checkWidgetReleased == true) && (checkWidgetPressed == true))
			{
				if ((mousePosX <= videoWidth) & (mousePosY <= videoHeight))
				{
					if (changeSceneTo != currScene)
					{
						currScene = changeSceneTo;
						updateScene();
					}
					this->clickingWidgetAudio = true;
					//cout << "clicked!" << endl;
				}
				else
				{
					cout << "not clicking!" << endl;
				}
				checkWidgetPressed = false;
				checkWidgetReleased = false;
			}
			else
			{
				checkWidgetReleased = false;
			}
		}
		/* New and Load Scene */
		if (currScene == 1)
		{
			if (this->hoveringOverWidget == false)
			{
				if ((mousePosX >= (videoWidth * 0.040)) && (mousePosX <= (videoWidth * 0.430)) && (mousePosY >= (videoHeight * 0.0667)) && (mousePosY <= (videoHeight * 0.193)))
				{
					this->hoveringOverWidget = true;
					this->hoveringOverWidgetAudio = true;
					this->widgets[newGame].setTexture(&this->widgetTextures[newGame_widget_hovered]);
				}
				else if ((mousePosX >= (videoWidth * 0.040)) && (mousePosX <= (videoWidth * 0.430)) && (mousePosY >= (videoHeight * 0.235)) && (mousePosY <= (videoHeight * 0.360)))
				{
					this->hoveringOverWidget = true;
					this->hoveringOverWidgetAudio = true;
					this->widgets[loadGame].setTexture(&this->widgetTextures[loadGame_widget_hovered]);
				}
				else if ((mousePosX >= (videoWidth * 0.708)) && (mousePosX <= (videoWidth * 0.958)) && (mousePosY >= (videoHeight * 0.807)) && (mousePosY <= (videoHeight * 0.931)))
				{
					this->hoveringOverWidget = true;
					this->hoveringOverWidgetAudio = true;
					this->widgets[back].setTexture(&this->widgetTextures[back_widget_hovered]);
				}
				else
				{
					this->defaultTextures();
				}
			}
			else if (this->hoveringOverWidget == true)
			{
				if ((mousePosX >= (videoWidth * 0.040)) && (mousePosX <= (videoWidth * 0.430)) && (mousePosY >= (videoHeight * 0.0667)) && (mousePosY <= (videoHeight * 0.193)))
				{
					this->widgets[newGame].setTexture(&this->widgetTextures[newGame_widget_hovered]);
				}
				else if ((mousePosX >= (videoWidth * 0.040)) && (mousePosX <= (videoWidth * 0.430)) && (mousePosY >= (videoHeight * 0.235)) && (mousePosY <= (videoHeight * 0.360)))
				{
					this->widgets[loadGame].setTexture(&this->widgetTextures[loadGame_widget_hovered]);
				}
				else if ((mousePosX >= (videoWidth * 0.708)) && (mousePosX <= (videoWidth * 0.958)) && (mousePosY >= (videoHeight * 0.807)) && (mousePosY <= (videoHeight * 0.931)))
				{
					this->widgets[back].setTexture(&this->widgetTextures[back_widget_hovered]);
				}
				else
				{
					this->defaultTextures();
					this->hoveringOverWidget = false;
				}
			}
			if (checkWidgetPressed == true)
			{
				/* Checking if newGame widget is pressed */
				if ((mousePosX >= (videoWidth * 0.040)) && (mousePosX <= (videoWidth * 0.430)) && (mousePosY >= (videoHeight * 0.0667)) && (mousePosY <= (videoHeight * 0.193)))
				{
					changeSceneTo = 3;
					this->widgets[newGame].setTexture(&this->widgetTextures[newGame_widget_pressed]);
				}
				/* Checking if loadGame widget is pressed */
				if ((mousePosX >= (videoWidth * 0.040)) && (mousePosX <= (videoWidth * 0.430)) && (mousePosY >= (videoHeight * 0.235)) && (mousePosY <= (videoHeight * 0.360)))
				{
					//cout << "Holding" << endl;
					this->widgets[loadGame].setTexture(&this->widgetTextures[loadGame_widget_pressed]);
				}
				/* Checking if back widget is pressed */
				if ((mousePosX >= (videoWidth * 0.708)) && (mousePosX <= (videoWidth * 0.958)) && (mousePosY >= (videoHeight * 0.807)) && (mousePosY <= (videoHeight * 0.931)))
				{
					//cout << "Holding" << endl;
					changeSceneTo = 0;
					this->widgets[back].setTexture(&this->widgetTextures[back_widget_pressed]);
				}
			}
			if ((checkWidgetReleased == true) && (checkWidgetPressed == true))
			{
				if ((mousePosX <= videoWidth) & (mousePosY <= videoHeight))
				{
					if (changeSceneTo != currScene)
					{
						currScene = changeSceneTo;
						updateScene();
					}
					this->clickingWidgetAudio = true;
					//cout << "clicked!" << endl;
				}
				else
				{
					cout << "not clicking!" << endl;
				}
				checkWidgetPressed = false;
				checkWidgetReleased = false;
			}
			else
			{
				checkWidgetReleased = false;
			}
		}
		if (currScene == 2)
		{
			if (this->hoveringOverWidget == false)
			{
				if ((mousePosX >= (videoWidth * 0.708)) && (mousePosX <= (videoWidth * 0.958)) && (mousePosY >= (videoHeight * 0.807)) && (mousePosY <= (videoHeight * 0.931)))
				{
					this->hoveringOverWidget = true;
					this->hoveringOverWidgetAudio = true;
					this->widgets[back].setTexture(&this->widgetTextures[back_widget_hovered]);
				}
				else
				{
					this->defaultTextures();
				}
			}
			else if (this->hoveringOverWidget == true)
			{
				if ((mousePosX >= (videoWidth * 0.708)) && (mousePosX <= (videoWidth * 0.958)) && (mousePosY >= (videoHeight * 0.807)) && (mousePosY <= (videoHeight * 0.931)))
				{
					this->widgets[back].setTexture(&this->widgetTextures[back_widget_hovered]);
				}
				else
				{
					this->defaultTextures();
					this->hoveringOverWidget = false;
				}
			}
			if (checkWidgetPressed == true)
			{
				/* Checking if back widget is pressed */
				if ((mousePosX >= (videoWidth * 0.708)) && (mousePosX <= (videoWidth * 0.958)) && (mousePosY >= (videoHeight * 0.807)) && (mousePosY <= (videoHeight * 0.931)))
				{
					//cout << "Holding" << endl;
					changeSceneTo = 0;
					this->widgets[back].setTexture(&this->widgetTextures[back_widget_pressed]);
				}
			}
			if ((checkWidgetReleased == true) && (checkWidgetPressed == true))
			{
				if ((mousePosX <= videoWidth) & (mousePosY <= videoHeight))
				{
					if (changeSceneTo != currScene)
					{
						currScene = changeSceneTo;
						updateScene();
					}
					this->clickingWidgetAudio = true;
					//cout << "clicked!" << endl;
				}
				else
				{
					cout << "not clicking!" << endl;
				}
				checkWidgetPressed = false;
				checkWidgetReleased = false;
			}
			else
			{
				checkWidgetReleased = false;
			}
		}
	}
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
/* Functions */
void Widget::defaultTextures()
{
	this->widgets[play].setTexture(&this->widgetTextures[play_widget]);
	this->widgets[settings].setTexture(&this->widgetTextures[settings_widget]);
	this->widgets[quit].setTexture(&this->widgetTextures[quit_widget]);
	this->widgets[newGame].setTexture(&this->widgetTextures[newGame_widget]);
	this->widgets[loadGame].setTexture(&this->widgetTextures[loadGame_widget]);
	this->widgets[back].setTexture(&this->widgetTextures[back_widget]);
}

void Widget::init(int Height, int Width)
{
	videoHeight = Height;
	videoWidth = Width;
	this->initVariables();
	this->initScene();
	this->initWidgets();
	this->initCursor();
}

void Widget::updateCursor(int x, int y)
{
	this->cursor.setPosition(x * 1.f, y * 1.f);
}

void Widget::update(int Height, int Width, int PosX, int PosY)
{
	videoHeight = Height;
	videoWidth = Width;
	mousePosX = PosX;
	mousePosY = PosY;
	this->updateScene();
	this->updateWidgets();
}
///////////////////////////////////////////////////////////////
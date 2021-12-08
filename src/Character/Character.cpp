//Character will create and keep track of our enemies
//
//TODO: IDK, like everything...
//->

#include "Character.hpp"

///////////////////////////////////////////////////////////////
//Private Functions
void Character::initVariables()
{
	x = 500.f;
	y = 300.f;
	MovingDown = 0;
	MovingUp = 0;
	MovingLeft = 0;
	MovingRight = 0;
	CurrentCharacter = 0;
}

void Character::initCharacters()
{
	/* Creating the Test Character */
	this->CharacterTexture.loadFromFile("content/Characters/TestCharacter.png");
	this->CharacterTextures.push_back(this->CharacterTexture);
	this->Character.scale(0.1f, 0.1f);
	this->Character.setPosition(x, y);
	this->Characters.push_back(this->Character);

	this->Characters[TestCharacter].setTexture(this->CharacterTextures[TestCharacter]);
}

void Character::updateCharacters()
{
	if (MovingUp == 1)
	{
		if (MovingDown == 1)
		{
			//Do nothing
		}
		else
		{
			y -= 5;
		}
	}
	else if (MovingDown == 1)
	{
		y += 5;
	}

	if (MovingLeft == 1)
	{
		if (MovingRight == 1)
		{
			//Do Nothing
		}
		else
		{
			x -= 5;
		}
	}
	else if (MovingRight == 1)
	{
		x += 5;
	}

	this->Characters[CurrentCharacter].setPosition(x, y);
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
//Public Functions
void Character::init()
{
	this->initVariables();
	this->initCharacters();
}

void Character::update()
{
	this->updateCharacters();
}
///////////////////////////////////////////////////////////////
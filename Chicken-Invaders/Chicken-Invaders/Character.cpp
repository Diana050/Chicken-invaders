#include "Character.h"

void Character::initVariables()
{
	this->movementSpeed = 50.f;
	this->attackCooldownMax = 5.f;
	this->attackCooldown = this->attackCooldownMax;
}

void Character::initTexture()
{
	if (!this->texture.loadFromFile("Texture/Ship.png"))
	{
		std::cout << "Sunt poza si nu ma vad";
	}
}

void Character::initSprite()
{
	this->sprite.setTexture(this->texture);

	this->sprite.setPosition(900.f, 950.f);

	this->sprite.scale(0.4f, 0.4f);
}

void Character::border()
{
	auto vprov = this->sprite.getPosition();
	if (this->sprite.getPosition().x < 0) vprov.x = 0;
	if (this->sprite.getPosition().x > 1920 - 100) vprov.x = 1920 - 100;
	if (this->sprite.getPosition().y < 0) vprov.y = 0;
	if (this->sprite.getPosition().y > 1080 - 100) vprov.y = 1080 - 100;

	this->sprite.setPosition(vprov);
}

Character::Character()
{
	state = 0;
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Character::~Character()
{
}



const sf::Vector2f& Character::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Character::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Character::move(const float dirX, const float dirY)
{
	
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
	border();
}

void Character::changeSprite()
{
	switch (state/2)
	{
	case 0:
		if (!this->texture.loadFromFile("Texture/Ship.png"))
		{
			std::cout << "Sunt poza si nu ma vad";
		}
		break;

	case 1:
		if (!this->texture.loadFromFile("Texture/explosion1.png"))
		{
			std::cout << "Sunt poza si nu ma vad";
		}
		break;

	case 2:
		if (!this->texture.loadFromFile("Texture/explosion2.png"))
		{
			std::cout << "Sunt poza si nu ma vad";
		}
		break;

	case 3:
		if (!this->texture.loadFromFile("Texture/explosion3.png"))
		{
			std::cout << "Sunt poza si nu ma vad";
		}
		break;

	case 4:
		if (!this->texture.loadFromFile("Texture/explosion4.png"))
		{
			std::cout << "Sunt poza si nu ma vad";
		}
		break;

	case 5:
		if (!this->texture.loadFromFile("Texture/explosion5.png"))
		{
			std::cout << "Sunt poza si nu ma vad";
		}
		break;

	default:
		if (!this->texture.loadFromFile("Texture/MT.png"))//TODO de schimbat resursa intr-un sprite gol
		{
			std::cout << "Sunt poza si nu ma vad";
		}
		break;
	}

	state++; //progresia prin explozie si trecerea reconstruirea navei dupa explozie
	if (state > 10)
	{
		state = 0;
		if (!this->texture.loadFromFile("Texture/Ship.png"))
		{
			std::cout << "Sunt poza si nu ma vad";
		}
		this->sprite.setPosition(900.f, 950.f);
	}
}

const bool Character::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f; 
		return true;
	}
	return false;
}

int Character::getState()
{
	return state;
}

void Character::startBOOM()
{
	this->state = 1;
}


void Character::update()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 3.f;
	}

	if (state != 0) changeSprite();
}

void Character::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}



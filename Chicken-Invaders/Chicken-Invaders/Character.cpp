#include "Character.h"

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

Character::Character()
{
	this->movementSpeed = 50.f;

	this->initTexture();
	this->initSprite();
}

Character::~Character()
{
}

void Character::move(const float dirX, const float dirY)
{
	
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

/*void Character::moveByMouse(sf::Vector2i pos)
{
	auto p = sf::Vector2f(pos);
	this->sprite.setPosition(p);
}*/

void Character::update()
{

}

void Character::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

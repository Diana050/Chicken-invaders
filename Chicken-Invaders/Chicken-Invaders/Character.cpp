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

Character::Character()
{
	
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

void Character::move(const float dirX, const float dirY)
{
	
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
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

/*void Character::moveByMouse(sf::Vector2i pos)
{
	auto p = sf::Vector2f(pos);
	this->sprite.setPosition(p);
}*/

void Character::update()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 3.f;
	}
}

void Character::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

#include "Enemy.h"

void Enemy::initTexture()
{
	if (!this->texture.loadFromFile("Texture/Chicken1.png"))
	{
		std::cout << "Sunt poza si nu ma vad";
	}
}

void Enemy::initSprite()
{
	this->sprite.setTexture(this->texture);

	this->sprite.setPosition(100.f, 950.f);

	this->sprite.scale(0.15f, 0.15f);
}

/*void Enemy::initShape()
{
	this->shape.setRadius(rand()%20 +20);
	this->shape.setPointCount(rand() %20  + 3);
	this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));

}*/

void Enemy::intiVariables()
{
	 this->type  = 0;
	 this->speed = 15.f;
	 this->hpMax = rand() % 3 + 1; //inamici generati cu viata random de la 1 pana la 3
	 this->hp = hpMax; 
	 this->damage  =1;
	 this->points  =5;
}

Enemy::Enemy( float pos_x, float pos_y)
{
	//this->initShape();
	this->initTexture();
	this->initSprite();
	this->intiVariables();
	this->sprite.setPosition(pos_x, pos_y);
	
}

Enemy::~Enemy()
{
}



const  sf::FloatRect Enemy::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

bool Enemy::isDedAfterHit(int dmg)
{
	hp= hp - dmg;
	if (hp <= 0)return true;
	else return false;
}

bool Enemy::droppin()
{
	
	int advantage = 10 - 2 * hpMax; //sansa mai mare de drop cu cat e inamicul mai puternic
	int rando = rand() % advantage;
	if (rando == 1) return true;
	else return false;
	
	//return true;
}

sf::Vector2f Enemy::getPos()
{
	return this->sprite.getPosition();
}

void Enemy::update(float addSpeed)
{
	this->sprite.move(0.f, this->speed+addSpeed);
}

void Enemy::render(sf::RenderTarget * target)
{
	target->draw(this->sprite);
}



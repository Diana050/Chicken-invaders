#include "PowerUp.h"

void PowerUp::initShape()
{
	this->shape.setRadius(10);
	this->shape.setPointCount(20);
	if(type==0) this->shape.setFillColor(sf::Color::Red);
	else this->shape.setFillColor(sf::Color::Green);
}

void PowerUp::intiVariables()
{
	this->type = rand()%2;
	this->speed = 15.f;
	this->points = 5;
}

PowerUp::PowerUp(sf::Vector2f pos)
{
	this->intiVariables();
	this->initShape();
	this->shape.setPosition(pos);

}

PowerUp::~PowerUp()
{
}

const  sf::FloatRect PowerUp::getBounds() const
{
	return this->shape.getGlobalBounds();
}

int PowerUp::getType()
{
	return type;
}

void PowerUp::update(float addSpeed)
{
	this->shape.move(0.f, this->speed + addSpeed);
}

void PowerUp::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
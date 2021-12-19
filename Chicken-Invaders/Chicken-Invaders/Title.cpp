#include "Title.h"

void Title::initTexture()
{
	if (!this->texture.loadFromFile("Texture/ChickenInvadersLogo.png"))
	{
		std::cout << "Sunt poza si nu ma vad";
	}
}

void Title::initSprite()
{
	this->sprite.setTexture(this->texture);

	this->sprite.scale(0.6f, 0.6f);

	this->sprite.setPosition(620.f, 50.f);
}

Title::Title()
{
	this->initTexture();
	this->initSprite();
}

Title::~Title()
{
}

void Title::update()
{

}

void Title::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
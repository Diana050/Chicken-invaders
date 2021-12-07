#include "Rulesground.h"
#include <iostream>
Rulesground::Rulesground()
{
}

Rulesground::~Rulesground()
{
}

void Rulesground::draw(sf::RenderWindow* window)
{
	/*sf::RectangleShape rect(sf::Vector2f(1920, 1080));
	rect.setPosition(sf::Vector2f(0, 0));
	rect.setFillColor(sf::Color::Blue);
	window->draw(rect);*/

	sf::RectangleShape background;
	background.setSize(sf::Vector2f(1920, 1080));
	sf::Texture Menuetexture;
	Menuetexture.loadFromFile("Texture/Playground.jpg");
	background.setTexture(&Menuetexture);
	background.setFillColor(sf::Color(255, 255, 255, 128));
	window->draw(background);

	sf::Font font;
	if (!font.loadFromFile("Fonts/arial.ttf"))
	{
		std::cout << "Ia fontul de unde nu-i";
	}
	sf::Text text;
	text.setString(" movement keys : up arrow, down arrow, left arrow, right arrow \n or you can use the mouse \n shooting keys : space or  mouse left click \n earn points by shooting the chickens and try not to loose you lives \n by loosing your lives means to bumb into a chicken");
	text.setFillColor(sf::Color::Green);
	text.setFont(font);
	text.setPosition(540, 420);

	window->draw(text);

	}
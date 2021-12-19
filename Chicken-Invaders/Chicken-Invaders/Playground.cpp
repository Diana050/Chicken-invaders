#include "Playground.h"
#include <iostream>

Playground::Playground()
{
}

Playground::~Playground()
{
}

void Playground::draw(sf::RenderWindow* window)
{
	/*f::RectangleShape rect(sf::Vector2f(1920, 1080));
	rect.setPosition(sf::Vector2f(0, 0));
	rect.setFillColor(sf::Color::Cyan);
	window->draw(rect);*/

	sf::RectangleShape background;
	background.setSize(sf::Vector2f(1920, 1080));
	sf::Texture Menuetexture;
	Menuetexture.loadFromFile("Texture/Playground.jpg");
	background.setTexture(&Menuetexture);
	background.setFillColor(sf::Color(255, 255, 255, 128));
	window->draw(background);

	/*/sf::Font font;
	if (!font.loadFromFile("Fonts/arial.ttf"))
	{
		std::cout << "Ia fontul de unde nu-i";
	}
	sf::Text text;
	text.setString("Game on");
	text.setFillColor(sf::Color::Green);
	text.setFont(font);
	text.setCharacterSize(50);
	text.setPosition(50, 100);

	window->draw(text);*/

}

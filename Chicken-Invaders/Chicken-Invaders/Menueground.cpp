#include "Menueground.h"
#include <iostream>

Menueground::Menueground()
{
}

Menueground::~Menueground()
{
}
void Menueground::draw(sf::RenderWindow* window)
{

	sf::RectangleShape background;
	background.setSize(sf::Vector2f(1920, 1080));
	sf::Texture Menuetexture;
	Menuetexture.loadFromFile("Texture/Menueground.jpg");
	background.setTexture(&Menuetexture);
	background.setFillColor(sf::Color(255, 255, 255, 128));
	window->draw(background);

	/*sf::Font font;
	if (!font.loadFromFile("Fonts/arial.ttf"))
	{
		std::cout << "Ia fontul de unde nu-i";
	}
	sf::Text text;
	text.setString("");
	text.setFillColor(sf::Color::Green);
	text.setFont(font);
	text.setCharacterSize(50);
	text.setPosition(50, 100);

	window->draw(text);*/

}
#include "GameOver.h"
#include <iostream>
GameOver::GameOver()
{
}

GameOver::~GameOver()
{
}

void GameOver::draw(sf::RenderWindow* window, int score)
{

	sf::RectangleShape background;
	background.setSize(sf::Vector2f(1920, 1080));
	background.setFillColor(sf::Color(0, 0, 0, 128));
	window->draw(background);

	sf::Font font;
	if (!font.loadFromFile("Fonts/arial.ttf"))
	{
		std::cout << "Ia fontul de unde nu-i";
	}
	sf::Text text;
	text.setString("Game Over");
	text.setFillColor(sf::Color::White);
	text.setFont(font);
	text.setCharacterSize(50);
	text.setPosition(540, 420);

	window->draw(text);

}
#include "HighScores.h"
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include <iostream>
#include <fstream>

void HighScores::addNew(std::string name, int score)
{
	int whereToPutIt = 9;

	for (int i = whereToPutIt; i >= 0; i--)
	{
		if (score > hsScores[i])
		{
			whereToPutIt=i;
		}
	} 

	moveDown(whereToPutIt);

	hsScores[whereToPutIt] = score;
	hsNames[whereToPutIt] = name;
	numberOfScores++;

	writeFIle();
}

void HighScores::moveDown(int pos)
{
	for (int i = 8; i > pos; i--) 
	{
		hsScores[i] = hsScores[i - 1];
		hsNames[i] = hsNames[i - 1];
	}
}

void HighScores::readFile()
{
	std::ifstream in("Highscores.txt");
	while (in >> hsScores[numberOfScores])
	{
		in >> hsNames[numberOfScores];
		numberOfScores++;
	}
	in.close();
}

void HighScores::writeFIle()
{
	std::ofstream out("Highscores.txt");
	if (out.is_open())
	{
		for (int i = 0; i < numberOfScores; i++)
		{
			out << hsScores[i] << " " << hsNames[i] << "\n";
		}
		out.close();
	}
	else std::cout << "unable to open out";
}

HighScores::HighScores()
{
	readFile();
}

HighScores::~HighScores()
{
}
bool HighScores::isItHigh(int score)
{
	if (score > hsScores[9]) return true;
	else return false;
}
void HighScores::draw(sf::RenderWindow* window)
{

	sf::RectangleShape background;
	background.setSize(sf::Vector2f(1920, 1080));
	sf::Texture Menuetexture;
	Menuetexture.loadFromFile("Texture/Menueground.jpg");
	background.setTexture(&Menuetexture);
	background.setFillColor(sf::Color(255, 255, 255, 128));
	window->draw(background);

	sf::Font font;
	if (!font.loadFromFile("Fonts/arial.ttf"))
	{
		std::cout << "Ia fontul de unde nu-i";
	}

	sf::Text text;
	text.setString("Highscores");
	text.setFillColor(sf::Color::White);
	text.setFont(font);
	text.setPosition(740, 90);

	window->draw(text);

	for (int i = 0; i < numberOfScores; i++)
	{
		text.setString(std::to_string(i + 1) + " " + hsNames[i]);
		text.setPosition(700, 140 + 50 * i);
		window->draw(text);

		text.setString(std::to_string(hsScores[i]));
		text.setPosition(950, 140 + 50 * i);
		window->draw(text);
	}

}

void HighScores::drawGameOver(sf::RenderWindow* window, int score)
{

}

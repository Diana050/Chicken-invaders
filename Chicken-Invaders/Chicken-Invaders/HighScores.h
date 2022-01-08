#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include "Button.h"

class HighScores
{

private:
	int hsScores[10] = { 0 };
	std::string hsNames[10] = { "-" };
	int numberOfScores = 0;
	void moveDown(int pos);
	void readFile();
	void writeFIle();

	
public:
	
	
	HighScores();
	virtual ~HighScores();

	//functions
	void addNew(std::string name, int score);
	bool isItHigh(int score);
	std::string getName();
	void draw(sf::RenderWindow* window);
	void drawGameOver(sf::RenderWindow* window, int score);
};
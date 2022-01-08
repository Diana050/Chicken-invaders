#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include "Button.h"

class GameOver
{

private:

public:
	GameOver();
	virtual ~GameOver();

	//functions

	bool isItHigh();
	std::string getName();
	void draw(sf::RenderWindow* window, int score);
};


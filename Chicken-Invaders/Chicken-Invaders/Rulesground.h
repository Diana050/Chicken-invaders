#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include "Button.h"

class Rulesground
{

private:

public:
	Rulesground();
	virtual ~Rulesground();

	//functions

	void draw(sf::RenderWindow* window);
};


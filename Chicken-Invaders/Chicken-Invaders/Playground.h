#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include "Button.h"

class Playground
{

private:

public:
	Playground();
	virtual ~Playground();

	//functions
	
	void draw(sf::RenderWindow* window);
};


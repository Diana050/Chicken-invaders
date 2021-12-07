#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include "Button.h"

class Menueground
{

private:

public:
	Menueground();
	virtual ~Menueground();

	//functions

	void draw(sf::RenderWindow* window);
};
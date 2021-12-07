#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include "Button.h"
#include "Playground.h"
#include "Rulesground.h"
#include "Menueground.h"

class Game
{

private:
	sf::RenderWindow* window; //pointer to make it dynamic
	Button* butStart= new Button(sf::Vector2f(350, 350), 150, 50);
	Button* butRules = new Button(sf::Vector2f(350, 450), 150, 50);
	Button* butExit = new Button(sf::Vector2f(350, 550), 150, 50);
	Button* butBack = new Button(sf::Vector2f(850,620), 150, 50);
	int windowstate = 0;
	Playground* PG = new Playground;
	Rulesground* RG = new Rulesground;
	Menueground* MG = new Menueground;

	//private functions
	void initWindow();

public:
	Game();
	virtual ~Game();

	//functions
	void run();
	void update();
	void render();
	

};


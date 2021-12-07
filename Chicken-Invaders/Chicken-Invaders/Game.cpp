#include "Game.h"
#include "Button.h"
#include <iostream>


//private functions
void Game::initWindow()
{
	this->window = new  sf::RenderWindow(sf::VideoMode(1920,1080), "Chicken Invaders", sf::Style::Fullscreen);
	window->setActive();
}


//comnstructir &destructor
Game::Game()
{
	this->initWindow(); 
}

Game::~Game()
{
	delete this->window;
}

//functions
void Game::run()
{
	
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
	
}

void Game::update()
{
	sf::Event ev;
	while (this->window->pollEvent(ev))
	{
		
		if (ev.Event::KeyPressed && ev.Event::key.code  == sf::Keyboard::F4)
			this->window->close(); 

		auto mousePos = sf::Mouse::getPosition(*window); //auto inseamna ca tipul de variabila e atribuit automat in functie de ce primeste

		butStart->isHoverd(mousePos);
		butRules->isHoverd(mousePos);
		butExit->isHoverd(mousePos);
		butBack->isHoverd(mousePos);
		if (ev.Event::type == sf::Event::MouseButtonPressed)
		{
			std::cout << "Buton de mouse apasat \n";
			if (ev.Event::mouseButton.button == sf::Mouse::Left)
			{
				if (!windowstate)
				{
					
					if (butStart->isPressed(mousePos)) windowstate = 1;
					if (butRules->isPressed(mousePos)) windowstate = 2;
					if (butExit->isPressed(mousePos)) this->window->close();

				}	
				if (windowstate == 2)
				{
					auto mousePos = sf::Mouse::getPosition(*window);
					if (butBack->isPressed(mousePos)) windowstate = 0;
				}


			}
		}
	}
}

void Game::render()
{
	this->window->clear();

	//draw all the things 
	if (!windowstate)
	{
		MG->draw(window);
		butStart->draw(window);
		sf::Font font;
		if (!font.loadFromFile("Fonts/arial.ttf"))
		{
			std::cout << "Ia fontul de unde nu-i";
		}
		sf::Text text;
		text.setString("Play");
		text.setFillColor(sf::Color::Green);
		text.setFont(font);
		text.setPosition(350, 350);
		window->draw(text);

		butRules->draw(window);
		sf::Font font1;
		if (!font1.loadFromFile("Fonts/arial.ttf"))
		{
			std::cout << "Ia fontul de unde nu-i";
		}
		sf::Text text1;
		text1.setString("Rules");
		text1.setFillColor(sf::Color::Green);
		text1.setFont(font1);
		text1.setPosition(350, 450);
		window->draw(text1);

		butExit->draw(window);
		sf::Font font2;
		if (!font2.loadFromFile("Fonts/arial.ttf"))
		{
			std::cout << "Ia fontul de unde nu-i";
		}
		sf::Text text2;
		text2.setString("Exit");
		text2.setFillColor(sf::Color::Green);
		text2.setFont(font2);
		text2.setPosition(350, 550);
		window->draw(text2);
	}
	else
	{
		if(windowstate==1) PG->draw(window);
		else 
		{
			if (windowstate == 2)
			{
				RG->draw(window);
				butBack->draw(window);
				sf::Font font3;
				if (!font3.loadFromFile("Fonts/arial.ttf"))
				{
					std::cout << "Ia fontul de unde nu-i";
				}
				sf::Text text3;
				text3.setString("Back");
				text3.setFillColor(sf::Color::Green);
				text3.setFont(font3);
				text3.setPosition(890, 625);
				window->draw(text3);
			}
		}
			
	}
		

	this->window->display();
}

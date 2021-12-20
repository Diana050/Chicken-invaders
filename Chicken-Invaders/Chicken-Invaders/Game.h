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
#include "Character.h"
#include "Title.h"
#include "Bullet.h"
#include "Enemy.h"
#include<map>;

class Game
{

private:
	//window
	sf::RenderWindow* window; //pointer to make it dynamic

	//resource
	std::map<std::string, sf::Texture*> texture;
	std::vector<Bullet*> bullet;

	//buttons
	Button* butStart= new Button(sf::Vector2f(350, 350), 150, 50);
	Button* butRules = new Button(sf::Vector2f(350, 450), 150, 50);
	Button* butExit = new Button(sf::Vector2f(350, 550), 150, 50);
	Button* butBack = new Button(sf::Vector2f(850,620), 150, 50);
	int windowstate = 0;
	Playground* PG = new Playground;
	Rulesground* RG = new Rulesground;
	Menueground* MG = new Menueground;
	
	//character
	Character* character;
	
	//title
	Title* title;

	//enemy
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;
	Enemy* enemy;

	//sf::Vector2i lastMousePos = sf::Mouse::getPosition(*window);

	//private functions
	void initWindow();
	void initTexture();
	//void initChickenTexture();
	void initCharacter();
	void initTitle();
	void initEnemy();
	

public:
	Game();
	virtual ~Game();

	//functions
	void run();
	
	void update();
	void render();

	

};


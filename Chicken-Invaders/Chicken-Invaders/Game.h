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
#include "HighScores.h"
#include "PowerUp.h"
#include<map>;

class Game
{

private:
	//window
	sf::RenderWindow* window; //pointer to make it dynamic

	//resource
	std::map<std::string, sf::Texture*> texture;
	std::vector<Bullet*> bullet;
	std::vector<PowerUp*> powerUps;

	//buttons
	Button* butStart= new Button(sf::Vector2f(865, 385), 190, 65);
	Button* butRules = new Button(sf::Vector2f(865, 485), 190, 65);
	Button* butExit = new Button(sf::Vector2f(865, 585), 190, 65);
	Button* butBack = new Button(sf::Vector2f(865,685), 190, 65);
	Button* butHighscores = new Button(sf::Vector2f(865, 685), 190, 65);
	int windowstate = 0;
	Playground* PG = new Playground;
	Rulesground* RG = new Rulesground;
	Menueground* MG = new Menueground;
	HighScores* HS = new HighScores;
	
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
	int score = 0;
	int lives = 3;
	int damage = 1;

	//private functions
	void initWindow();
	void initTexture();
	//void initChickenTexture();
	void initCharacter();
	void initTitle();
	void initEnemy();
	void calcSpeed();
	

public:
	Game();
	virtual ~Game();

	//functions
	void run();
	
	void update();
	void render();

	

};


#ifndef ENEMY_H
#define ENEMY_H

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include<iostream>

class Enemy
{
private:
	sf::CircleShape shape;

	int type;
	float speed;
	int hp;
	int hpMAx;
	int damage;
	int points;

	void initShape();
	void intiVariables();

public:
	Enemy( float pos_x, float pos_y);
	virtual ~Enemy();

	//accessor
	const sf::FloatRect getBounds() const;

	void update();
	void render(sf::RenderTarget* target);
};

#endif 

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
	sf::Sprite sprite;
	sf::Texture texture;

	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;

	void initShape();
	void initTexture();
	void initSprite();
	void intiVariables();

public:
	Enemy( float pos_x, float pos_y);
	virtual ~Enemy();

	//accessor
	const sf::FloatRect getBounds() const;

	bool isDedAfterHit(int dmg);
	bool droppin();
	sf::Vector2f getPos();
	void update(float addSpeed);
	void render(sf::RenderTarget* target);
};

#endif 

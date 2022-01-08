#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include<iostream>


class Character
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;
	float attackCooldown;
	float attackCooldownMax;
	int state;

	//private functions
	void initVariables();
	void initTexture();
	void initSprite();
	void border();

public:
	Character();
	virtual ~Character();

	//accessor
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;

	//functions
	void move(const float dirX, const float dirY);
	void changeSprite();
	const bool canAttack();
	int getState();
	void startBOOM();

	//void moveByMouse(sf::Vector2i pos);

	void update();
	void render(sf::RenderTarget& target);
	 
};


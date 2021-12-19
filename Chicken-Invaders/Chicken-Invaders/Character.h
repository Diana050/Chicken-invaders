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

	//private functions
	void initVariables();
	void initTexture();
	void initSprite();

public:
	Character();
	virtual ~Character();

	//accessor
	const sf::Vector2f& getPos() const;

	//functions
	void move(const float dirX, const float dirY);

	const bool canAttack();

	//void moveByMouse(sf::Vector2i pos);

	void update();
	void render(sf::RenderTarget& target);
	 
};


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

	//private functions
	void initTexture();
	void initSprite();

public:
	Character();
	virtual ~Character();

	//functions
	void move(const float dirX, const float dirY);
	//void moveByMouse(sf::Vector2i pos);

	void update();
	void render(sf::RenderTarget& target);
	 
};


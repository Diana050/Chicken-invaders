#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include<iostream>


class Title
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	void initTexture();
	void initSprite();

public:
	Title();
	virtual ~Title();

	void update();
	void render(sf::RenderTarget& target);

};
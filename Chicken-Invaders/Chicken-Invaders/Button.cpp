#include "Button.h"
#include <iostream>

Button::Button(const sf::Vector2f& pos, const float& wd, const float& ht, const sf::Color& clr)
{
	this->pos = pos;
	width = wd;
	height = ht;
	color = clr;
}

void Button::draw(sf::RenderWindow* window)
{
	sf::RectangleShape rect(sf::Vector2f(width, height));
	rect.setPosition(pos);
	rect.setFillColor(color);
	window->draw(rect);
	
}

bool Button::isPressed(sf::Vector2i mousePos)
{
	if (mousePos.x >= pos.x && mousePos.x < pos.x + width && mousePos.y >= pos.y && mousePos.y < pos.y + height) {
		
		std::cout << "AM FOST APASAT!!!!";
		return true;
	}
	return false;
}

bool Button::isHoverd(sf::Vector2i mousePos)
{
	if (mousePos.x >= pos.x && mousePos.x < pos.x + width && mousePos.y >= pos.y && mousePos.y < pos.y + height) {

		setColor(sf::Color::Blue);
	}
	else
		setColor(sf::Color::Cyan);
	return false;
}

void Button::setFontSize(const float& fs)
{
	fontSize = int(fs);
}

void Button::setLabel(const std::string& lb)
{
	label = lb;
}

void Button::setColor(const sf::Color& clr) 
{
	color = clr;
}



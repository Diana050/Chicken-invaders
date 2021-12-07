#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>


class Button
{
protected:
    sf::Vector2f pos;
    float width, height;
    std::string label;
    int fontSize;
    sf::Color color;

public:
    Button(const sf::Vector2f& pos, const float& wd, const float& ht, const sf::Color& clr = sf::Color::Cyan);
    void setFontSize(const float& fs);
    void setLabel(const std::string& lb);
    void setColor(const sf::Color& clr);
    void draw(sf::RenderWindow* window);
    bool isPressed(sf::Vector2i mousePos);
    bool isHoverd(sf::Vector2i mousePos);
};
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include<iostream>

class PowerUp
{
private:
	sf::CircleShape shape;

	int type;
	float speed;
	int points;

	void initShape();
	void intiVariables();

public:
	PowerUp(sf::Vector2f pos);
	virtual ~PowerUp();

	//accessor
	const sf::FloatRect getBounds() const;

	int getType();
	void update(float addSpeed);
	void render(sf::RenderTarget* target);
};


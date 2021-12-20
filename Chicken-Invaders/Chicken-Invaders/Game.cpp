#include "Game.h"
#include "Button.h"
#include <iostream>


//private functions
void Game::initWindow()
{
	this->window = new  sf::RenderWindow(sf::VideoMode(1920,1080), "Chicken Invaders", sf::Style::Fullscreen);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
	window->setActive();
}

void Game::initTexture()
{
	this->texture["BULLET"] = new sf::Texture();
	this->texture["BULLET"]->loadFromFile("Texture/Bullet1.png");
}

/*void Game::initChickenTexture()
{
	this->texture["ENEMY"] = new sf::Texture();
	this->texture["ENEMY"]->loadFromFile("Texture/Chicken1.png");
	
}*/



void Game::initCharacter()
{
	this->character = new Character();
	
}


void Game::initEnemy()
{
	//this->enemy = new Enemy(20.f, 20.f);
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
}


void Game::initTitle()
{
	this->title = new Title();
}

//constructor & destructor
Game::Game()
{
	this->initWindow(); 
	this->initTexture();
	this->initCharacter();
	this->initTitle();
	this->initEnemy();
}


Game::~Game()
{
	delete this->window;

	//delete texture
	for (auto &i : this->texture)
	{
		delete i.second;
	}

	//delete bullets
	for (auto* i : this->bullet)
	{
		delete i;
	}

	//delete enemies
	for (auto* i : this->enemies)
	{
		delete i;
	}

	delete this->character;
	delete this->title;
}



//functions
void Game::run()
{
	
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
	
}

void Game::update()
{
	sf::Event ev;
	while (this->window->pollEvent(ev))
	{
		
		if (ev.Event::KeyPressed && ev.Event::key.code  == sf::Keyboard::F4)
			this->window->close(); 

		auto mousePos = sf::Mouse::getPosition(*window); //auto inseamna ca tipul de variabila e atribuit automat in functie de ce primeste

		butStart->isHoverd(mousePos);
		butRules->isHoverd(mousePos);
		butExit->isHoverd(mousePos);
		butBack->isHoverd(mousePos);
		if (ev.Event::type == sf::Event::MouseButtonPressed)
		{
			std::cout << "Buton de mouse apasat \n";
			if (ev.Event::mouseButton.button == sf::Mouse::Left)
			{
				if (!windowstate)
				{
					
					if (butStart->isPressed(mousePos)) windowstate = 1;
					if (butRules->isPressed(mousePos)) windowstate = 2;
					if (butExit->isPressed(mousePos)) this->window->close();

				}	
				if (windowstate == 2)
				{
					auto mousePos = sf::Mouse::getPosition(*window);
					if (butBack->isPressed(mousePos)) windowstate = 0;
				}


			}
		}
	}
	if (windowstate == 1)
	{
	/*auto mousePos = sf::Mouse::getPosition(*window);
	move character
	if (lastMousePos == mousePos)
	{*/

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->character->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->character->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->character->move(0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->character->move(1.f, 0.f);

		
	/*else
	{
		this->character->moveByMouse(mousePos);
	}
	lastMousePos = mousePos;
	}*/

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->character->canAttack())
	{
		this->bullet.push_back(new Bullet(this->texture["BULLET"],this->character->getPos().x + this->character->getBounds().width/2.f , this->character->getPos().y, 0.f, -1.f,50.f));
	}
	
	unsigned counter = 0;
	for (auto* bullets : this->bullet)
	{
		bullets->update();

		//bulet is on top of the screen
		if (bullets->getBounds().top + bullets->getBounds().height < 0.f)
		{
			//delete bullet
			delete this->bullet.at(counter);
			this->bullet.erase(this->bullet.begin() + counter);
			--counter;


		}
		++counter;
	}
	
	this->character->update();

	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(rand() % this->window->getSize().x-20.f, -100.f));
		this->spawnTimer = 0.f; 
	}
	for (int i = 0; i < this->enemies.size();i++)
	{
		bool enemy_removed = false;
		this->enemies[i]->update();
		

		for (size_t k = 0; k < this->bullet.size() && !enemy_removed; k++)
		{
			if (this->bullet[k]->getBounds().intersects(this->enemies[i]->getBounds()))
			{
				this->bullet.erase(this->bullet.begin() + k);
				this->enemies.erase(this->enemies.begin() + i);
				enemy_removed = true;
			}
		}

		//remove enemye at the bottom of the screen
		if (!enemy_removed)
		{

		if (this->enemies[i]->getBounds().top > this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
			enemy_removed = true;
		}
		}
	}
	
	}
}



void Game::render()
{
	this->window->clear();

	//draw all the things 
	if (!windowstate)
	{
		MG->draw(window);
		this->title->render(*this->window);
		butStart->draw(window);
		sf::Font font;
		if (!font.loadFromFile("Fonts/arial.ttf"))
		{
			std::cout << "Ia fontul de unde nu-i";
		}
		sf::Text text;
		text.setString("Play");
		text.setFillColor(sf::Color(78,72,79));
		text.setFont(font);
		text.setPosition(350, 350);
		window->draw(text);

		butRules->draw(window);
		sf::Font font1;
		if (!font1.loadFromFile("Fonts/arial.ttf"))
		{
			std::cout << "Ia fontul de unde nu-i";
		}
		sf::Text text1;
		text1.setString("Rules");
		text1.setFillColor(sf::Color(78, 72, 79));
		text1.setFont(font1);
		text1.setPosition(350, 450);
		window->draw(text1);

		butExit->draw(window);
		sf::Font font2;
		if (!font2.loadFromFile("Fonts/arial.ttf"))
		{
			std::cout << "Ia fontul de unde nu-i";
		}
		sf::Text text2;
		text2.setString("Exit");
		text2.setFillColor(sf::Color(78, 72, 79));
		text2.setFont(font2);
		text2.setPosition(350, 550);
		window->draw(text2);
	}
	else
	{
		if (windowstate == 1) 
		{
			PG->draw(window);
			this->character->render(*this->window);

			for (auto* bullets:this->bullet)
			{
				bullets->render(this->window);
			}
			for (auto*enemy : this->enemies)
			{
				enemy->render(this->window);
			}
			
		}
		else 
		{
			if (windowstate == 2)
			{
				RG->draw(window);
				butBack->draw(window);
				sf::Font font3;
				if (!font3.loadFromFile("Fonts/arial.ttf"))
				{
					std::cout << "Ia fontul de unde nu-i";
				}
				sf::Text text3;
				text3.setString("Back");
				text3.setFillColor(sf::Color(78, 72, 79));
				text3.setFont(font3);
				text3.setPosition(890, 625);
				window->draw(text3);
			}
		}
			
	}
		

	this->window->display();
}

#include "Game.h"
#include "Button.h"
#include <iostream>


//private functions
void Game::initWindow()
{
	this->window = new  sf::RenderWindow(sf::VideoMode(1920,1080), "Chicken Invaders", sf::Style::Fullscreen);
	this->window->setFramerateLimit(60);//////a fost 144
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

void Game::calcSpeed()
{

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
	if (windowstate == 0)
	{
		while (this->window->pollEvent(ev))
		{
			auto mousePos = sf::Mouse::getPosition(*window); //auto inseamna ca tipul de variabila e atribuit automat in functie de ce primeste

			butStart->isHoverd(mousePos);
			butRules->isHoverd(mousePos);
			butExit->isHoverd(mousePos);
			butHighscores->isHoverd(mousePos);
			if (ev.Event::type == sf::Event::MouseButtonPressed)
			{
				std::cout << "Buton de mouse apasat \n";
				if (ev.Event::mouseButton.button == sf::Mouse::Left)
				{
					if (!windowstate)
					{

						if (butStart->isPressed(mousePos)) windowstate = 1;
						if (butRules->isPressed(mousePos)) windowstate = 2;
						if (butHighscores->isPressed(mousePos)) windowstate = 3;
						if (butExit->isPressed(mousePos)) this->window->close();

					}
				}
			}
		}
	}

	if ((windowstate == 2 || windowstate == 3))
	{
		while (this->window->pollEvent(ev))
		{
			if (ev.Event::KeyPressed && ev.Event::key.code == sf::Keyboard::F4) this->window->close();


			{
				auto mousePos = sf::Mouse::getPosition(*window);
				butBack->isHoverd(mousePos);
				if (ev.Event::type == sf::Event::MouseButtonPressed && ev.Event::mouseButton.button == sf::Mouse::Left)
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
	if (this->spawnTimer >= this->spawnTimerMax - (float)score/10)//TODO modifica acel 10 (cu cat e mai mic numarul cu atat creste viteze mai mult)
	{
		this->enemies.push_back(new Enemy(rand() % this->window->getSize().x-20.f, -100.f));//generare inamici
		this->spawnTimer = 0.f; 
	}
	for (int i = 0; i < this->enemies.size();i++)
	{
		bool enemy_removed = false;
		this->enemies[i]->update((float)score/1);//TODO change later to 5 BLABLABLABLABLABLABLABLABLABLABLABLABLABLABLABLABLABLABLABLABLABLABLABLA

		for (size_t k = 0; k < this->bullet.size() && !enemy_removed; k++)
		{
			if (this->bullet[k]->getBounds().intersects(this->enemies[i]->getBounds()))
			{
				this->bullet.erase(this->bullet.begin() + k);

				if (enemies[i]->isDedAfterHit(damage))
				{		
					if (this->enemies[i]->droppin())
					{
						this->powerUps.push_back(new PowerUp(enemies[i]->getPos()));
					}
					this->enemies.erase(this->enemies.begin() + i);
					i--;
					enemy_removed = true;
					score++; //plusam scorul la fiecare kill
				}
			}
		}

		if (i >= 0 && i < enemies.size())
		{
			if (this->character->getBounds().intersects(this->enemies[i]->getBounds()) && character->getState() == 0)//aici crapa de la vector :')
			{
				this->enemies.erase(this->enemies.begin() + i);
				lives--;
				damage = 1;
				this->enemies.erase(this->enemies.begin() + i);
				enemy_removed = true;

				character->startBOOM();
				if (lives <= 0)
				{//cod pentru terminarea jocului
					windowstate = 4;
				}
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
	for (int i = 0; i < this->powerUps.size(); i++)
	{
		this->powerUps[i]->update((float)score / 1);
		if (this->character->getBounds().intersects(this->powerUps[i]->getBounds()) && character->getState() == 0)//aici crapa de la vector :')
		{
			if (this->powerUps[i]->getType() == 1) damage++;
			else lives++;
			this->powerUps.erase(this->powerUps.begin() + i);
		}
	}
	
	}
}



void Game::render()
{
	this->window->clear();
	static sf::Text  playerText;
	static std::string playerInput;
	sf::Text text;
	sf::Font font;
	sf::RectangleShape background;


	switch (windowstate)
	{
	case 0:
		MG->draw(window);
		this->title->render(*this->window);
		butStart->draw(window);
		//sf::Font font;
		if (!font.loadFromFile("Fonts/arial.ttf"))
		{
			std::cout << "Ia fontul de unde nu-i";
		}
		//sf::Text text;
		text.setString("Play");
		text.setFillColor(sf::Color(78, 72, 79));
		text.setFont(font);
		text.setPosition(925, 395);
		window->draw(text);

		butRules->draw(window);
		//sf::Font font;
		if (!font.loadFromFile("Fonts/arial.ttf"))
		{
			std::cout << "Ia fontul de unde nu-i";
		}
		//sf::Text text;
		text.setString("Rules");
		text.setFillColor(sf::Color(78, 72, 79));
		text.setFont(font);
		text.setPosition(915, 495);
		window->draw(text);

		butExit->draw(window);
		//sf::Font font2;
		if (!font.loadFromFile("Fonts/arial.ttf"))
		{
			std::cout << "Ia fontul de unde nu-i";
		}
		//sf::Text text2;
		text.setString("Exit");
		text.setFillColor(sf::Color(78, 72, 79));
		text.setFont(font);
		text.setPosition(925, 595);
		window->draw(text);


		butHighscores->draw(window);
		//sf::Font font3;
		if (!font.loadFromFile("Fonts/arial.ttf"))
		{
			std::cout << "Ia fontul de unde nu-i";
		}
		//sf::Text text3;
		text.setString("Highscores");
		text.setFillColor(sf::Color(78, 72, 79));
		text.setFont(font);
		text.setPosition(890, 695);
		window->draw(text);

		break;

	case 1:

		PG->draw(window);
		this->character->render(*this->window);

		//sf::Font font;
		if (!font.loadFromFile("Fonts/arial.ttf"))
		{
			std::cout << "Ia fontul de unde nu-i";
		}
		//sf::Text text;
		text.setString("Score " + std::to_string(score) + "\n" + "Lives " + std::to_string(lives) + "\n " + "Damage "+ std::to_string(damage)); // afisam scorul (trebuie to_string pentru ca nu merge concatenat un int la un text, aparent ¯\_(?)_/¯ )
		text.setFillColor(sf::Color(189,38,38));
		text.setFont(font);
		text.setPosition(0, 0);

		window->draw(text);

		for (auto* bullets : this->bullet)
		{
			bullets->render(this->window);
		}
		for (auto* enemy : this->enemies)
		{
			enemy->render(this->window);
		}
		for (auto* powerup : this->powerUps)
		{
			powerup->render(this->window);
		}
		break;

	case 2:
		RG->draw(window);
		butBack->draw(window);
		//sf::Font font;
		if (!font.loadFromFile("Fonts/arial.ttf"))
		{
			std::cout << "Ia fontul de unde nu-i";
		}
		//sf::Text text;
		text.setString("Back");
		text.setFillColor(sf::Color(78, 72, 79));
		text.setFont(font);
		text.setPosition(925, 695);
		window->draw(text);

		break;

	case 3:
		HS->draw(window);
		butBack->draw(window);


		//sf::Font font; 
		if (!font.loadFromFile("Fonts/arial.ttf"))
		{
			std::cout << "Ia fontul de unde nu-i";
		}
		//sf::Text text;
		text.setString("Back");
		text.setFillColor(sf::Color(78, 72, 79));
		text.setFont(font);
		text.setPosition(925, 695);
		window->draw(text);

		break;

	case 4:
		//HS->drawGameOver(window, score);


		background.setSize(sf::Vector2f(1920, 1080));
		background.setFillColor(sf::Color(0, 0, 0, 128));
		window->draw(background);

		//sf::Font font;
		if (!font.loadFromFile("Fonts/arial.ttf"))
		{
			std::cout << "Ia fontul de unde nu-i";
		}
		//sf::Text text;
		text.setString("Game Over \n \n Your final score is: \n          " + std::to_string(score));
		text.setFillColor(sf::Color::White);
		text.setFont(font);
		text.setCharacterSize(50);
		text.setPosition(540, 420);

		window->draw(text);

		if (HS->isItHigh(score)) {
			text.setString("You have obtaind a place in the hall of fame, enter your name");
			text.setPosition(450, 650);

			window->draw(text);



			sf::Event event;

			playerText.setFillColor(sf::Color::White);
			playerText.setFont(font);
			playerText.setPosition(540, 1000);



			if (window->pollEvent(event))
			{

				if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::F4)
					this->window->close();
				else if (event.type == sf::Event::Closed)
					window->close();

				//std::cout << "a" << std::endl;
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128)
					{
						std::cout << static_cast<char>(event.text.unicode) << std::endl;

						if (event.text.unicode == '\b')
						{
							if(playerInput.size()>0) playerInput.erase(playerInput.size() - 1, 1);		
						}
						else playerInput += event.text.unicode;
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					//wplayerInput.erase(playerInput.size() - 1, 1);//stergem enterul care se pune pe string
					//std::cout << playerInput;

					windowstate = 3;

					HS->addNew(playerInput, score);
				}

				playerText.setString(playerInput);

			}



			window->draw(playerText);

			//window->display();
		}

	default:
		//windowstate = 0;
		break;

	}


	this->window->display();
}
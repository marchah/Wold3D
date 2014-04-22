#include "WindowSFML.hh"
#include "ABlock.hh"

WindowSFML::WindowSFML(int height, int width, const std::string& nameWindow)
: AWindow(height, width)
{
	this->window_ = new sf::RenderWindow(sf::VideoMode(height, width), nameWindow);
	this->algo_ = new AlgoRayCasting();
}

WindowSFML::~WindowSFML()
{
	delete this->window_;
	delete this->algo_;
}

#include <iostream>

void WindowSFML::run(Scene *scene)
{
	sf::Event event;
	sf::Time time;

	this->drawFloor();
	this->drawCeil();
	this->algo_->calcul(*this, *scene);
	this->display();

	this->clock_.restart();
	while (this->window_->pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				this->window_->close();
				std::cout << "close" << std::endl;
				break;

			case sf::Event::KeyPressed:
				time = this->clock_.getElapsedTime();
				this->clock_.restart();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					scene->getPlayer()->moveUp(*scene->getMap(), time.asSeconds());
					this->drawFloor();
					this->algo_->calcul(*this, *scene);
					this->display();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					scene->getPlayer()->moveDown(*scene->getMap(), time.asSeconds());
					this->drawFloor();
					this->algo_->calcul(*this, *scene);
					this->display();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					scene->getPlayer()->moveRight(*scene->getMap(), time.asSeconds());
					this->drawFloor();
					this->algo_->calcul(*this, *scene);
					this->display();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					scene->getPlayer()->moveLeft(*scene->getMap(), time.asSeconds());
					this->drawFloor();
					this->algo_->calcul(*this, *scene);
					this->display();
				}
				break;

			case sf::Event::Resized:
				/*this->height_ = event.size.height;
				this->width_ = event.size.width;

				this->drawFloor();
				this->drawCeil();
				this->algo_->calcul(*this, map, player);
				this->display();
			    std::cout << "new width: " << event.size.width << std::endl;
				std::cout << "new height: " << event.size.height << std::endl;*/
				break;

			default:
				break;
		}
	}
}

bool  WindowSFML::windowIsOpen() const
{
	return this->window_->isOpen();
}

void WindowSFML::drawLine(float posX, float drawStart, float drawEnd, const IWindow::Color &color) const
{
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(posX, drawStart)),
		sf::Vertex(sf::Vector2f(posX, drawEnd))
	};
	sf::Color sfmlColor(color.red, color.green, color.blue);
	line[0].color = sfmlColor;
	line[1].color = sfmlColor;
	this->window_->draw(line, 2, sf::Lines);
}

void WindowSFML::drawFloor() const
{
	sf::RectangleShape floor(sf::Vector2f(this->height_, this->width_ / 2));
	floor.setFillColor(sf::Color(100, 250, 50));
	floor.setPosition(0, this->width_ / 2);
	this->window_->draw(floor);
}

void WindowSFML::drawCeil() const
{
	sf::RectangleShape floor(sf::Vector2f(this->height_, this->width_ / 2));
	floor.setFillColor(sf::Color(255, 0, 0));
	this->window_->draw(floor);
}

void WindowSFML::display() const
{
	this->window_->display();
}
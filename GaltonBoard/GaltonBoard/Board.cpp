#include "Board.h"


void Board::initVariables()
{
	srand(time(NULL));

	// Сетка
	int vertX = (this->window->getSize().x / TILESIZE) * 2 + 2;
	int vertY = (this->window->getSize().y / TILESIZE) * 2 + 2;
	this->mesh = new sf::Vertex[vertX * vertY];
	this->meshSize = vertX + vertY;

	for (int i = 0; i < vertX; i += 2)
	{
		this->mesh[i].position = sf::Vector2f(i * TILESIZE / 2.f, 0.f);
		this->mesh[i+1].position = sf::Vector2f(i * TILESIZE / 2.f, this->window->getSize().y);
		this->mesh[i].color = sf::Color(65, 238, 142, 255);
		this->mesh[i + 1].color = sf::Color(94, 219, 219, 255);
	}
	for (int i = 0; i < vertY; i += 2)
	{
		this->mesh[vertX + i].position = sf::Vector2f(0.f, i * TILESIZE / 2.f);
		this->mesh[vertX + i + 1].position = sf::Vector2f(this->window->getSize().x, i * TILESIZE / 2.f);
		this->mesh[vertX + i].color = sf::Color(65 + (94 - 65) / vertY * (i + 1), 238 + (219 - 238) / vertY * (i + 1), 142 + (219 - 142) / vertY * (i + 1), 255);
		this->mesh[vertX + i + 1].color = sf::Color(65 + (94 - 65) / vertY * (i + 1), 238 + (219 - 238) / vertY * (i + 1), 142 + (219 - 142) / vertY * (i + 1), 255);
	}
	
	this->mapWidth = 29;
	
	// Штифты
	this->circle = new sf::CircleShape(20.f);
	this->circle->setFillColor(sf::Color::Magenta);
	this->circle->setPosition(0.f, 0.f);
	this->circle->setOrigin(sf::Vector2f(20.f, 20.f));

	// Колбы
	this->line.setPosition(sf::Vector2f(0.f, 0.f));
	
	this->line.setFillColor(sf::Color::Blue);
	this->line.setOutlineThickness(1.f);
	this->line.setOutlineColor(sf::Color::Yellow);

	for (int i = 0; i < map.size() / this->mapWidth; i++)
	{
		for (int j = 0; j < this->mapWidth; j++)
		{
			if (this->map[i * this->mapWidth + j] == 2) {
				this->line.setPosition(sf::Vector2f(
					j * TILESIZE + TILESIZE / 2.f,
					i * TILESIZE + TILESIZE / 2.f
				));
				this->line.setSize(sf::Vector2f(15.f, TILESIZE));
				this->line.setOrigin(sf::Vector2f(7.5f, TILESIZE / 2.f));

				this->lines.push_back(this->line);
			}
			if (this->map[i * this->mapWidth + j] == 3) {
				this->line.setPosition(sf::Vector2f(
					j * TILESIZE + TILESIZE / 2.f,
					i * TILESIZE
				));
				this->line.setSize(sf::Vector2f(TILESIZE, 15.f));
				this->line.setOrigin(sf::Vector2f(TILESIZE / 2.f, 0.f));

				this->lines.push_back(this->line);
			}
			if (this->map[i * this->mapWidth + j] == 4)
			{
				sf::RectangleShape shape;
				shape.setPosition(sf::Vector2f(
					j * TILESIZE,
					i * TILESIZE + TILESIZE
				));
				
				shape.setSize(sf::Vector2f(TILESIZE, 0.f));
				shape.setFillColor(sf::Color::Yellow);

				this->columns.push_back(shape);
			}
		}
	}
}

void Board::initMap()
{
	this->map = {
		0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0,
		0, 0, 0, 0, 2, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 2, 0, 0, 0, 0,
		0, 0, 0, 0, 2, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 2, 0, 0, 0, 0,
		0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0, 0, 0,
		0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0, 0, 0,
		0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0, 0, 0,
		0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0, 0, 0,
		0, 0, 0, 0, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 0, 0, 0, 0,
		0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0,
	};
}

void Board::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "GaltonBoard", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

//Constructor/destructor
Board::Board()
{

	this->initWindow();
	this->initMap();
	this->initVariables();
}

Board::~Board()
{
	delete this->window;
	delete this->mesh;
}

//Functions
void Board::updateEvents()
{
	while (this->window->pollEvent(this->sfEvents))
	{
		if (this->sfEvents.type == sf::Event::Closed)
			this->window->close();
	}
}

void Board::updateInput()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{

		Ball* ball = new Ball(14 * TILESIZE , 0 * TILESIZE, 16.f);
		this->balls.push_back(ball);
	}
		
}

void Board::updateBalls()
{
	std::list<Ball*>::const_iterator itr = balls.cbegin();

	while (itr != balls.cend())
	{
		if ((*itr)->isRouteDone())
		{
			sf::Vector2u ballPos = (*itr)->getTilePos();
			if (ballPos.y < 15)
			{
				if (this->map[this->mapWidth * (ballPos.y + 1) + ballPos.x] == 1)
				{
					int rnd = rand() % 2;
					switch (rnd)
					{
					case 0:
						(*itr)->setRouteTarget(ballPos.x + 1, ballPos.y + 1);
						break;
					case 1:
						(*itr)->setRouteTarget(ballPos.x - 1, ballPos.y + 1);
						break;
					}
				}
				else
				{
					(*itr)->setRouteTarget(ballPos.x, ballPos.y + 1);
				}
				(*itr)->update();
				++itr;
			}
			else
			{
				for (auto& i : this->columns)
				{
					if (i.getPosition().x / TILESIZE == ballPos.x)
					{
						i.setSize(sf::Vector2f(TILESIZE, i.getSize().y - 1.f));
					}
				}
				delete* itr;
				itr = balls.erase(itr);
			}
		}
		else
		{
			(*itr)->update();
			++itr;
		}
	}
}

void Board::update()
{
	this->updateEvents();
	
	this->updateInput();

	this->updateBalls();
}

void Board::renderMesh()
{
	/*
		Рисует сетку
	*/
	this->window->draw(this->mesh, this->meshSize, sf::Lines);
}

void Board::renderMap()
{
	/*
		Рисует статические объекты на карте
	*/
	// Штифты
	for (int i = 0; i < map.size() / this->mapWidth; i++)
	{
		for (int j = 0; j < this->mapWidth; j++)
		{
			if (this->map[i * this->mapWidth + j] == 1) {
				this->circle->setPosition(sf::Vector2f(
					j * TILESIZE + TILESIZE / 2.f,
					i * TILESIZE + TILESIZE / 2.f
				));
				this->window->draw(*this->circle);
			}
		}
	}

	// Линии
	for (auto& i : this->lines)
	{
		this->window->draw(i);
	}
}

void Board::render()
{
	this->window->clear();

	this->renderMesh(); //Сетка
	this->renderMap();

	for (auto* i : this->balls)
	{
		i->render(*this->window);
	}

	for (auto& i : this->columns)
	{
		this->window->draw(i);
	}
	

	this->window->display();
}

void Board::run()
{
	while (this->window->isOpen()) // Главный цикл
	{
		this->update();
		this->render();
	}
}

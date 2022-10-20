#include "Core.h"

void Core::initVariables()
{
	srand(time(NULL));
	this->videoMode = sf::VideoMode(1280, 720);
	this->tileSize = 32;
}

void Core::initWindow()
{
	this->window = new sf::RenderWindow(this->videoMode, "SquareCreation", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(120);
}


void Core::initToolBar()
{
	this->toolbar.setPosition(sf::Vector2f(1000.f, 0.f));
	this->toolbar.setSize(sf::Vector2f(280.f, 720.f));
	this->toolbar.setOutlineThickness(2.f);
	this->toolbar.setFillColor(sf::Color::Color(31, 31, 31, 255));
	this->toolbar.setOutlineColor(sf::Color::Color(61, 61, 61, 255));

}

void Core::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Chewy-Regular.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void Core::initMesh()
{
	this->mesh = new Mesh(0.f,0.f, static_cast<float>(this->window->getSize().x), static_cast<float>(this->window->getSize().y), this->tileSize);
}

void Core::initPoints()
{
	for (int i = 0; i < 10; i++)
	{
		this->addRandomPoint();
	}	
}

void Core::initButtons()
{
	this->buttons["RANDOMIZE"] = new gui::Button(
		1015, 200.f, 120.f, 40.f,
		&this->font, "Randomize", 24,
		sf::Color(180, 180, 180, 200), sf::Color(250, 250, 250, 255), sf::Color(150, 150, 150, 50),
		sf::Color(61, 61, 61, 255), sf::Color(61, 61, 61, 255), sf::Color(61, 61, 30, 255)
	);
	this->buttons["RANDOMIZE"]->setBorder(sf::Color::Color(158, 158, 158, 255), 2.f);

	this->buttons["CLEAR"] = new gui::Button(
		1150, 200.f, 120.f, 40.f,
		&this->font, "Clear", 24,
		sf::Color(180, 180, 180, 200), sf::Color(250, 250, 250, 255), sf::Color(150, 150, 150, 50),
		sf::Color(61, 61, 61, 255), sf::Color(61, 61, 61, 255), sf::Color(61, 61, 30, 255)
	);
	this->buttons["CLEAR"]->setBorder(sf::Color::Color(158, 158, 158, 255), 2.f);

	this->buttons["REMOVE2"] = new gui::Button(
		1015, 100.f, 55.f, 40.f,
		&this->font, "-2", 24,
		sf::Color(180, 180, 180, 200), sf::Color(250, 250, 250, 255), sf::Color(150, 150, 150, 50),
		sf::Color(61, 61, 61, 255), sf::Color(61, 61, 61, 255), sf::Color(61, 61, 30, 255)
	);
	this->buttons["REMOVE2"]->setBorder(sf::Color::Color(158, 158, 158, 255), 2.f);

	this->buttons["REMOVE1"] = new gui::Button(
		1080, 100.f, 55.f, 40.f,
		&this->font, "-1", 24,
		sf::Color(180, 180, 180, 200), sf::Color(250, 250, 250, 255), sf::Color(150, 150, 150, 50),
		sf::Color(61, 61, 61, 255), sf::Color(61, 61, 61, 255), sf::Color(61, 61, 30, 255)
	);
	this->buttons["REMOVE1"]->setBorder(sf::Color::Color(158, 158, 158, 255), 2.f);

	this->buttons["ADD1"] = new gui::Button(
		1145, 100.f, 55.f, 40.f,
		&this->font, "+1", 24,
		sf::Color(180, 180, 180, 200), sf::Color(250, 250, 250, 255), sf::Color(150, 150, 150, 50),
		sf::Color(61, 61, 61, 255), sf::Color(61, 61, 61, 255), sf::Color(61, 61, 30, 255)
	);
	this->buttons["ADD1"]->setBorder(sf::Color::Color(158, 158, 158, 255), 2.f);

	this->buttons["ADD2"] = new gui::Button(
		1210, 100.f, 55.f, 40.f,
		&this->font, "+2", 24,
		sf::Color(180, 180, 180, 200), sf::Color(250, 250, 250, 255), sf::Color(150, 150, 150, 50),
		sf::Color(61, 61, 61, 255), sf::Color(61, 61, 61, 255), sf::Color(61, 61, 30, 255)
	);
	this->buttons["ADD2"]->setBorder(sf::Color::Color(158, 158, 158, 255), 2.f);

	this->buttons["ADD_POINT"] = new gui::Button(
		1145.f, 300.f, 120.f, 40.f,
		&this->font, "Add pont", 24,
		sf::Color(180, 180, 180, 200), sf::Color(250, 250, 250, 255), sf::Color(150, 150, 150, 50),
		sf::Color(61, 61, 61, 255), sf::Color(61, 61, 61, 255), sf::Color(61, 61, 30, 255)
	);
	this->buttons["ADD_POINT"]->setBorder(sf::Color::Color(158, 158, 158, 255), 2.f);

	this->buttons["CALC_RECT"] = new gui::Button(
		1015.f, 350.f, 250.f, 40.f,
		&this->font, "Calculate rectangles", 24,
		sf::Color(180, 180, 180, 200), sf::Color(250, 250, 250, 255), sf::Color(150, 150, 150, 50),
		sf::Color(61, 61, 61, 255), sf::Color(61, 61, 61, 255), sf::Color(61, 61, 30, 255)
	);
	this->buttons["CALC_RECT"]->setBorder(sf::Color::Color(158, 158, 158, 255), 2.f);
}

void Core::initFields()
{
	this->inputFields["X1"] = new gui::InputField(
		1015, 300.f, 55.f, 40.f, 2,
		&this->font, "x1", 24,
		sf::Color::White,
		sf::Color::Color(61, 61, 61, 255),
		sf::Color::Transparent, sf::Color::Color(158, 158, 158, 255), sf::Color::Color(255, 255, 255, 255)
	);

	this->inputFields["Y1"] = new gui::InputField(
		1080, 300.f, 55.f, 40.f, 2,
		&this->font, "y1", 24,
		sf::Color::White,
		sf::Color::Color(61, 61, 61, 255),
		sf::Color::Transparent, sf::Color::Color(158, 158, 158, 255), sf::Color::Color(255, 255, 255, 255)
	);
}

void Core::initText()
{
	this->text.setPosition(sf::Vector2f(1015.f, 500.f));
	this->text.setCharacterSize(16);
	this->text.setFont(this->font);
	this->text.setFillColor(sf::Color::White);
	this->text.setString("");
}



Core::Core()
{
	this->initVariables();
	this->initWindow();
	this->initFonts();
	this->initMesh();
	this->initPoints();
	this->initToolBar();
	this->initButtons();
	this->initFields();
	this->initText();
}

Core::~Core()
{

	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}

	delete this->window;
}

bool Core::addPoint(sf::Vector2f position)
{
	for (auto* i : this->points)
	{
		if (i->getPosition() == position)
			return false;
	}
	this->points.push_back(new Point(position, this->tileSize));
	return true;
}

void Core::addRandomPoint()
{
	while (!this->addPoint(sf::Vector2f(rand() % (1000 / this->tileSize), rand() % (720 / this->tileSize))));
}


void Core::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}

void Core::updateSfmlEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
			this->window->close();
		if (this->ev.type == sf::Event::KeyPressed)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				this->window->close();
	}
}

void Core::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Core::updateButtons()
{
	for (auto& i : this->buttons)
	{
		i.second->update(this->mousePosWindow);
	}

	if (this->buttons["REMOVE2"]->isReleased()) {
		delete this->points[this->points.size() - 1];
		this->points.pop_back();
		delete this->points[this->points.size() - 1];
		this->points.pop_back();
	}

	if (this->buttons["REMOVE1"]->isReleased()) {
		delete this->points[this->points.size() - 1];
		this->points.pop_back();
	}

	if (this->buttons["ADD1"]->isReleased()) {
		this->addRandomPoint();
	}

	if (this->buttons["ADD2"]->isReleased()) {
		for (int i = 0; i < 2; i++)
		{
			this->addRandomPoint();
		}
		
		
	}

	if (this->buttons["RANDOMIZE"]->isReleased()) {
		for (auto* i : this->points)
		{
			i->setPosition(sf::Vector2f(rand() % (1000 / this->tileSize), rand() % (720 / this->tileSize)));
		}
	}

	if (this->buttons["CLEAR"]->isReleased()) {
		for (auto* i : this->points)
		{
			delete i;
		}
		this->points.clear();
	}

	if (this->buttons["ADD_POINT"]->isReleased())
	{
		if (this->inputFields["X1"]->getText() != "" && this->inputFields["Y1"]->getText() != "")
			this->addPoint(sf::Vector2f(std::stof(this->inputFields["X1"]->getText()), std::stof(this->inputFields["Y1"]->getText())));
	}

	if (this->buttons["CALC_RECT"]->isReleased())
	{
		for (auto& i : this->squares)
		{
			delete i;
		}
		this->squares.clear();

		if (this->points.size() >= 4)
			for (int a = 0; a < this->points.size(); a++)
			{
				//std::cout << "Calculating: " << a << "/" << this->points.size() << "\n";
				for (int b = 0; b < points.size(); b++)
				{
					if (this->points[a]->getPosition().y == this->points[b]->getPosition().y && 
						this->points[a]->getPosition().x < this->points[b]->getPosition().x)
					{
						int distance = this->points[b]->getPosition().x - this->points[a]->getPosition().x;

						for (int c = 0; c < this->points.size(); c++)
						{
							if (this->points[b]->getPosition().x == this->points[c]->getPosition().x &&
								this->points[b]->getPosition().y < this->points[c]->getPosition().y &&
								this->points[c]->getPosition().y - this->points[b]->getPosition().y == distance)
							{
								for (int d = 0; d < this->points.size(); d++)
								{
									if (this->points[c]->getPosition().y == this->points[d]->getPosition().y &&
										this->points[d]->getPosition().x < this->points[c]->getPosition().x &&
										this->points[c]->getPosition().x - this->points[d]->getPosition().x == distance)
									{
										this->squares.push_back(new Square(
											this->points[a]->getPosition().x,
											this->points[a]->getPosition().y,
											this->points[c]->getPosition().x,
											this->points[c]->getPosition().y,
											this->tileSize));
										std::cout << "A {" << this->points[a]->getPosition().x << "," << this->points[a]->getPosition().y << "}\n";
										std::cout << "B {" << this->points[b]->getPosition().x << "," << this->points[b]->getPosition().y << "}\n";
										std::cout << "C {" << this->points[c]->getPosition().x << "," << this->points[c]->getPosition().y << "}\n";
										std::cout << "D {" << this->points[d]->getPosition().x << "," << this->points[d]->getPosition().y << "}\n";
									}
								}
							}

						}
							
					}
					
				}
					
			}
				
	}

}

void Core::updateFields()
{
	for (auto& i : this->inputFields)
	{
		i.second->update(this->mousePosWindow, this->ev, this->dt, &this->inputFields);
	}
}


void Core::updateText()
{
	std::stringstream ss;
			

	ss << "Points: " << this->points.size() << "\n"
		<< "Squares: " << this->squares.size() << "\n"
		<< "MousePosition: " << this->mousePosWindow.x / this->tileSize << "  |  " << this->mousePosWindow.y / this->tileSize << "\n";

	this->text.setString(ss.str());
}

void Core::update()
{
	this->updateSfmlEvents();
	this->updateMousePositions();

	this->updateButtons();

	this->updateFields();

	this->updateText();
}

void Core::renderPoints()
{
	for (auto* i : this->points)
	{
		i->render(*this->window);
	}
}

void Core::renderSquares()
{
	for (auto& i : this->squares)
	{
		i->render(*this->window);
	}
}

void Core::renderToolbar()
{
	this->window->draw(this->toolbar);

	for (auto& i : this->buttons)
	{
		i.second->render(*this->window);
	}

	for (auto& i : this->inputFields)
	{
		i.second->render(*this->window);
	}

	this->window->draw(this->text);
}

void Core::render()
{
	this->window->clear(sf::Color::Color(178,178,178,255));

	this->mesh->render(*this->window);

	this->renderSquares();

	this->renderPoints();

	this->renderToolbar();

	this->window->display();
}

void Core::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}

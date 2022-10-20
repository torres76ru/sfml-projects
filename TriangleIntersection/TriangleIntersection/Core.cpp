#include "Core.h"

void Core::initVariables()
{
	srand(time(NULL));
	this->videoMode = sf::VideoMode(1280, 720);
}

void Core::initWindow()
{
	this->window = new sf::RenderWindow(this->videoMode, "TriangleIntetsection", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(120);
}

void Core::initTriangles()
{
	for (int i = 0; i < 3; i++)
	{
		this->triangles.push_back(new Triangle(
			sf::Vector2f(rand() % 1000, rand() % 720),
			sf::Vector2f(rand() % 1000, rand() % 720),
			sf::Vector2f(rand() % 1000, rand() % 720),
			sf::Color::Blue
		));
	}
}

void Core::initToolBar()
{
	this->toolbar.setPosition(sf::Vector2f(1000.f, 0.f));
	this->toolbar.setSize(sf::Vector2f(280.f, 720.f));
	this->toolbar.setOutlineThickness(2.f);
	this->toolbar.setFillColor(sf::Color::Color(31,31,31,255));
	this->toolbar.setOutlineColor(sf::Color::Color(61, 61, 61, 255));

}

void Core::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Chewy-Regular.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
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

	this->buttons["ADD_TRIANGLE"] = new gui::Button(
		1015, 400.f, 250.f, 40.f,
		&this->font, "Add triangle", 24,
		sf::Color(180, 180, 180, 200), sf::Color(250, 250, 250, 255), sf::Color(150, 150, 150, 50),
		sf::Color(61, 61, 61, 255), sf::Color(61, 61, 61, 255), sf::Color(61, 61, 30, 255)
	);
	this->buttons["ADD_TRIANGLE"]->setBorder(sf::Color::Color(158, 158, 158, 255), 2.f);
}

void Core::initFields()
{
	this->inputFields["X1"] = new gui::InputField(
		1015.f, 300.f, 77.f, 40.f, 3,
		&this->font, "x1", 24,
		sf::Color::White,
		sf::Color::Color(61, 61, 61, 255),
		sf::Color::Transparent, sf::Color::Color(158, 158, 158, 255), sf::Color::Color(255, 255, 255, 255)
	);

	this->inputFields["Y1"] = new gui::InputField(
		1015.f, 350.f, 77.f, 40.f, 3,
		&this->font, "y1", 24,
		sf::Color::White,
		sf::Color::Color(61, 61, 61, 255),
		sf::Color::Transparent, sf::Color::Color(158, 158, 158, 255), sf::Color::Color(255, 255, 255, 255)
	);

	this->inputFields["X2"] = new gui::InputField(
		1102.f, 300.f, 77.f, 40.f, 3,
		&this->font, "x2", 24,
		sf::Color::White,
		sf::Color::Color(61, 61, 61, 255),
		sf::Color::Transparent, sf::Color::Color(158, 158, 158, 255), sf::Color::Color(255, 255, 255, 255)
	);

	this->inputFields["Y2"] = new gui::InputField(
		1102.f, 350.f, 77.f, 40.f, 3,
		&this->font, "y2", 24,
		sf::Color::White,
		sf::Color::Color(61, 61, 61, 255),
		sf::Color::Transparent, sf::Color::Color(158, 158, 158, 255), sf::Color::Color(255, 255, 255, 255)
	);

	this->inputFields["X3"] = new gui::InputField(
		1189.f, 300.f, 77.f, 40.f, 3,
		&this->font, "x3", 24,
		sf::Color::White,
		sf::Color::Color(61, 61, 61, 255),
		sf::Color::Transparent, sf::Color::Color(158, 158, 158, 255), sf::Color::Color(255, 255, 255, 255)
	);

	this->inputFields["Y3"] = new gui::InputField(
		1189.f, 350.f, 77.f, 40.f, 3,
		&this->font, "y3", 24,
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
	this->initTriangles();
	this->initFonts();
	this->initToolBar();
	this->initButtons();
	this->initFields();
	this->initText();
}

Core::~Core()
{
	this->clearTriangles();

	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}

	delete this->window;
}

void Core::clearTriangles()
{
	for (auto* i : this->triangles)
		delete i;

	this->triangles.clear();
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
	/* Позиция мыши */
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Core::updateButtons()
{
	/* Обновляет кнопки */
	
	for (auto& i : this->buttons)
	{
		i.second->update(this->mousePosWindow);
	}

	if (this->buttons["REMOVE2"]->isReleased()) {
		for (int i = 0; i < 2; i++)
		{
			if (this->triangles.size() != 0)
			{
				delete this->triangles[triangles.size() - 1];
				this->triangles.pop_back();
			}
				
		}
	}

	if (this->buttons["REMOVE1"]->isReleased()) {
		if (this->triangles.size() != 0)
		{
			delete this->triangles[triangles.size() - 1];
			this->triangles.pop_back();
		}
	}

	if (this->buttons["ADD1"]->isReleased()) {
		this->triangles.push_back(new Triangle(
			sf::Vector2f(rand() % 1000, rand() % 720),
			sf::Vector2f(rand() % 1000, rand() % 720),
			sf::Vector2f(rand() % 1000, rand() % 720),
			sf::Color::Blue
		));
	}

	if (this->buttons["ADD2"]->isReleased()) {
		for (int i = 0; i < 2; i++)
		{
			this->triangles.push_back(new Triangle(
				sf::Vector2f(rand() % 1000, rand() % 720),
				sf::Vector2f(rand() % 1000, rand() % 720),
				sf::Vector2f(rand() % 1000, rand() % 720),
				sf::Color::Blue
			));
		}
	}

	if (this->buttons["RANDOMIZE"]->isReleased()) {
		for (auto* i : this->triangles)
		{
			i->setCords(
				sf::Vector2f(rand() % 1000, rand() % 720),
				sf::Vector2f(rand() % 1000, rand() % 720),
				sf::Vector2f(rand() % 1000, rand() % 720)
			);
		}
	}

	if (this->buttons["CLEAR"]->isReleased()) {
		this->clearTriangles();
	}

	if (this->buttons["ADD_TRIANGLE"]->isReleased()) {
		bool f = true;
		for (auto& i : inputFields)
		{
			if (i.second->getText() == "")
				f = false;
			std::cout << i.second->getText() << "\n";
		}

		if (f)
			this->triangles.push_back(new Triangle(
				sf::Vector2f(stof(this->inputFields["X1"]->getText()), stof(this->inputFields["Y1"]->getText())),
				sf::Vector2f(stof(this->inputFields["X2"]->getText()), stof(this->inputFields["Y2"]->getText())),
				sf::Vector2f(stof(this->inputFields["X3"]->getText()), stof(this->inputFields["Y3"]->getText())),
				sf::Color::Blue
			)); 
	}
}

void Core::updateFields()
{
	for (auto& i : this->inputFields)
	{
		i.second->update(this->mousePosWindow, this->ev, this->dt, &this->inputFields);
	}
}

void Core::updateIntersections()
{
	/* Обновить пересечения */
	for (auto* i : triangles) // Устанавливает что нет пересечений
	{
		i->setIntersected(false);
	}

	if (triangles.size() != 0) 
		for (int i = 0; i < this->triangles.size() - 1; i++)
		{
			for (int j = i + 1; j < this->triangles.size(); j++)
			{
				this->triangles[i]->updateIntersections(*this->triangles[j]);
			}
		}
}

void Core::updateTriangles()
{
	for (auto* i : triangles)
	{
		i->update();
	}
}

void Core::updateText()
{
	std::stringstream ss;
	int countIntersected = 0;

	for (auto* i : triangles)
	{
		if (i->getIntersected())
			countIntersected += 1;
	}
	ss << "Triangles: " << this->triangles.size() << "\n"
		<< "Triangles intersected: " << countIntersected << "\n";

	for (auto* i : triangles)
	{
		if (i->getIntersected())
			ss << "A{" << i->getVertex()[0].position.x << "," << i->getVertex()[0].position.y << "},"
				<< "B{" << i->getVertex()[1].position.x << "," << i->getVertex()[1].position.y << "},"
				<< "C{" << i->getVertex()[2].position.x << "," << i->getVertex()[2].position.y << "}\n";
	}

	this->text.setString(ss.str());
}

void Core::update()
{
	this->updateSfmlEvents();

	this->updateMousePositions();
	
	this->updateButtons();

	this->updateFields();

	this->updateIntersections();

	this->updateTriangles();

	this->updateText();
}

void Core::renderTriangles()
{
	for (auto* i : triangles)
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
	this->window->clear(sf::Color::White);
	
	this->renderTriangles();
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

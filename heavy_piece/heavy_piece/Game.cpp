#include "Game.h"

//Initializations
void Game::initVariables()
{
	srand(time(NULL));

	this->dt = 0.f;
}

void Game::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Chicle-Regular.ttf"))
	{
		throw("ERROR::GAME::COULD NOT LOAD FONT");
	}
}

void Game::initWindow()
{
	this->settings.antialiasingLevel = 8.0;
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 960), "heavy_piece", sf::Style::Titlebar | sf::Style::Close, settings);
	this->window->setFramerateLimit(120);
}

void Game::initFooter()
{
	//Footer
	float footerHeight = 200;
	this->footer.setPosition(sf::Vector2f(0, this->window->getSize().y - footerHeight));
	this->footer.setSize(sf::Vector2f(this->window->getSize().x, footerHeight));
	this->footer.setFillColor(sf::Color::Color(200, 200, 200, 255));
	this->footer.setOutlineThickness(2.f);
	this->footer.setOutlineColor(sf::Color::Color(50, 50, 50, 255));
}

void Game::initPieces()
{
	for (int i = 0; i < 100; i++)
	{
		float weight = (rand() % 50 + 30) / 10.f;
		this->pieces.push_back(
			new Piece(
				rand() % static_cast<int>(this->window->getSize().x),
				rand() % static_cast<int>(this->window->getSize().y - 200),
				weight,
				weight
			)
		);
	}
}

void Game::initCircle()
{
	this->circle.setPosition(sf::Vector2f(400.f, 200.f));
	this->circle.setRadius(100.f);
	this->circle.setOutlineThickness(-2.f);
	this->circle.setOutlineColor(sf::Color::Color(122, 40, 40, 255));
	this->circle.setFillColor(sf::Color::Transparent);
	this->circle.setOrigin(100.f, 100.f);
}

void Game::initCross()
{

}

void Game::initButtons()
{
	this->buttons["RANDOM"] = new gui::Button(
		20.f, 860.f, 100.f, 50.f,
		&this->font, "Randomize", 16,
		sf::Color(250, 250, 250, 200), sf::Color(250, 250, 250, 255), sf::Color(150, 150, 150, 50),
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 200), sf::Color(30, 30, 30, 200)
	);

	this->buttons["RANDOM_PIECE"] = new gui::Button(
		140.f, 860.f, 100.f, 50.f,
		&this->font, "Random", 16,
		sf::Color(250, 250, 250, 200), sf::Color(250, 250, 250, 255), sf::Color(150, 150, 150, 50),
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 200), sf::Color(30, 30, 30, 200)
	);

	this->buttons["CLEAR"] = new gui::Button(
		260.f, 860.f, 100.f, 50.f,
		&this->font, "Clear", 16,
		sf::Color(250, 250, 250, 200), sf::Color(250, 250, 250, 255), sf::Color(150, 150, 150, 50),
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 200), sf::Color(30, 30, 30, 200)
	);

	this->buttons["ADD_PIECE"] = new gui::Button(
		1100.f, this->footer.getPosition().y + 100.f, 100.f, 30.f,
		&this->font, "Add", 16,
		sf::Color(250, 250, 250, 200), sf::Color(250, 250, 250, 255), sf::Color(150, 150, 150, 50),
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 200), sf::Color(30, 30, 30, 200)
	);
}

void Game::initTextFields()
{
	int x = this->footer.getPosition().x + 800.f;
	int y = this->footer.getPosition().y + 100.f;
	this->textFields["PIECE_X"] = new gui::TextBox(
		x, y, 70.f, 30.f, 4,
		&this->font, 16
	);
	this->textFields["PIECE_X"]->setLabel("x");

	this->textFields["PIECE_Y"] = new gui::TextBox(
		x + 100.f, y, 70.f, 30.f, 4,
		&this->font, 16
	);
	this->textFields["PIECE_Y"]->setLabel("y");

	this->textFields["PIECE_WEIGHT"] = new gui::TextBox(
		x + 200.f, y, 70.f, 30.f, 4,
		&this->font, 16
	);
	this->textFields["PIECE_WEIGHT"]->setLabel("weight");
}

void Game::initText()
{
	this->infoText.setFont(font);
	this->infoText.setCharacterSize(24);
	this->infoText.setFillColor(sf::Color::Black);
	this->infoText.setString("");
	this->infoText.setPosition(0.f, 0.f);
	
}

void Game::clearPieces()
{
	for (auto* i : pieces)
	{
		delete i;
	}
	this->pieces.clear();
}

const float Game::getCircleWeight()
{
	float weight = 0.f;
	this->targetRects.clear();
	for (auto* i : this->pieces)
	{
		if(this->circle.getRadius() > sqrtf(std::powf(i->getPosition().x - this->circle.getPosition().x, 2) + std::powf(i->getPosition().y - this->circle.getPosition().y, 2)))
		{
			sf::RectangleShape rect;
			rect.setPosition(i->getPosition());
			rect.setSize(sf::Vector2f((i->getWeight() + 2.f) * 2, (i->getWeight() + 2.f) * 2));
			rect.setOutlineColor(sf::Color::Red);
			rect.setOrigin(rect.getSize() / 2.f);
			rect.setOutlineThickness(-1.f);
			rect.setFillColor(sf::Color::Transparent);
			this->targetRects.push_back(rect);
			weight += i->getWeight();		
		}

	}

	return weight;
}

//Constructor/destructor
Game::Game()
{
	this->initVariables();
	this->initFonts();
	this->initWindow();
	this->initPieces();
	this->initCircle();
	this->initFooter();
	this->initButtons();
	this->initTextFields();
	this->initText();
}

Game::~Game()
{
	delete this->window;

	//Clear pieces
	this->clearPieces();

	//Clear buttons
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void Game::updateDt()
{
	/*Updates the dt variable with the time it takes to update and render one frame.*/

	this->dt = this->dtClock.restart().asSeconds();


}
void Game::updateFps()
{
	std::stringstream ss;
	ss << "FPS: " << static_cast<int>(1 / dt) << "\n";
	this->infoText.setString(ss.str());
}
void Game::updateMousePos()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

//Functions
void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
		if (this->sfEvent.type == sf::Event::KeyPressed)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				this->window->close();
	}
}



void Game::updateButtons()
{
	for (auto& i : this->buttons)
	{
		i.second->update(this->mousePosWindow);
	}
}

void Game::updateTextFields()
{
	for (auto& i : this->textFields)
	{
		i.second->update(this->mousePosWindow, this->sfEvent, this->dt);
	}
}

void Game::updateGameInput()
{
	if (this->buttons["RANDOM"]->isReleased())
	{	
		int countPieces = this->pieces.size();
		this->clearPieces();

		for (int i = 0; i < countPieces; i++)
		{
			float weight = (rand() % 50 + 30) / 10.f;
			this->pieces.push_back(
				new Piece(
					rand() % static_cast<int>(this->window->getSize().x),
					rand() % static_cast<int>(this->window->getSize().y - 200),
					weight,
					weight
				)
			);
		}
	}

	if (this->buttons["RANDOM_PIECE"]->isReleased())
	{
		float weight = (rand() % 50 + 30) / 10.f;
		this->pieces.push_back(
			new Piece(
				rand() % static_cast<int>(this->window->getSize().x),
				rand() % static_cast<int>(this->window->getSize().y - 200),
				weight,
				weight
			)
		);
	}

	if (this->buttons["CLEAR"]->isReleased())
	{
		this->clearPieces();
	}

	if (this->buttons["ADD_PIECE"]->isReleased())
	{
		if (this->textFields["PIECE_X"]->getText() != "" &&
			this->textFields["PIECE_Y"]->getText() != "" &&
			this->textFields["PIECE_WEIGHT"]->getText() != "")
		{
			this->pieces.push_back(
				new Piece(
					std::stof(this->textFields["PIECE_X"]->getText()),
					std::stof(this->textFields["PIECE_Y"]->getText()),
					std::stof(this->textFields["PIECE_WEIGHT"]->getText()),
					std::stof(this->textFields["PIECE_WEIGHT"]->getText())
				)
			);
			std::cout << "Added!\n";
		}
		
	}
}

void Game::updateCircle()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) // Передвижение кружка
	{
		if (this->circle.getRadius() > sqrtf(std::powf(this->mousePosWindow.x - this->circle.getPosition().x, 2) + std::powf(this->mousePosWindow.y - this->circle.getPosition().y, 2))
			&& this->mousePosWindow.x > 0.f 
			&& this->mousePosWindow.x < this->window->getSize().x
			&& this->mousePosWindow.y > 0.f 
			&& this->mousePosWindow.y < this->window->getSize().x - this->footer.getSize().y)
		{
			this->circle.setPosition(static_cast<sf::Vector2f>(this->mousePosWindow));
		}
	}
	std::stringstream ss;
	ss << "Circle weight: " << this->getCircleWeight() << "\n"
		<< "Cirlce count: " << this->pieces.size() << "\n";
	this->infoText.setString(this->infoText.getString() + ss.str());

}

void Game::update()
{
	this->updateFps();
	this->updateSFMLEvents();
	this->updateMousePos();
	this->updateButtons();
	this->updateTextFields();
	this->updateGameInput();
	this->updateCircle();
}

void Game::renderPieces()
{
	for (auto* i : this->pieces)
	{
		i->render(*this->window);
	}
}

void Game::renderCircle()
{
	this->window->draw(this->circle);
}

void Game::renderFooter()
{
	this->window->draw(this->footer);

	for (auto& i : this->buttons)
	{
		i.second->render(*this->window);
	}

	for (auto& i : this->textFields)
	{
		i.second->render(*this->window);
	}
}

void Game::render()
{
	this->window->clear(sf::Color::White);

	//Render stuff
	
	this->renderPieces();
	
	this->renderCircle();

	for (auto& i : this->targetRects)
	{
		this->window->draw(i);
	}

	this->renderFooter();
	

	//Fps
	this->window->draw(this->infoText);

	this->window->display();
}


void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}

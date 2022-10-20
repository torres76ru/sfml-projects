#pragma once
#include "Piece.h"
#include "Gui.h"

class Game
{
private:

	sf::ContextSettings settings;
	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Vector2i mousePosWindow;

	sf::Font font;

	sf::Clock dtClock;
	float dt;

	std::vector<Piece*> pieces;
	std::vector<sf::RectangleShape> targetRects;
	sf::CircleShape circle;


	sf::RectangleShape footer;
	std::map<std::string, gui::Button*> buttons;
	std::map<std::string, gui::TextBox*> textFields;

	sf::Text infoText;
	sf::Text circleWeight;


	void initVariables();
	void initFonts();
	void initWindow();
	void initPieces();
	void initCircle();
	void initCross();
	
	void initFooter();
	void initButtons();
	void initTextFields();

	void initText();


	//Functions
	void clearPieces();
	const float getCircleWeight();

	//Updates
	void updateDt();
	void updateFps();
	void updateSFMLEvents();
	void updateMousePos();
	void updateButtons();
	void updateTextFields();
	void updateGameInput();
	void updateCircle();
	void update();

	void renderPieces();
	void renderCircle();
	void renderFooter();
	void render();

public:
	Game();
	~Game();

	void run();
};


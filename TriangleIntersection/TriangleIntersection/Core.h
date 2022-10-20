#pragma once
#include "Triangle.h"
#include <ctime>
#include <map>

class Triangle;

class Core
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event ev;
	
	sf::Font font;

	sf::Clock dtClock;
	float dt;

	sf::Vector2i mousePosWindow;

	std::vector<Triangle*> triangles;

	std::map<std::string, gui::Button*> buttons;
	std::map<std::string, gui::InputField*> inputFields;

	sf::Text text;

	sf::RectangleShape toolbar;
	

	void initVariables();
	void initWindow();
	void initFonts();
	void initTriangles();
	void initToolBar();
	void initButtons();
	void initFields();
	void initText();
public:
	Core();
	~Core();

	void clearTriangles();

	void updateDt();
	void updateSfmlEvents();
	void updateMousePositions();
	void updateButtons();
	void updateFields();
	void updateIntersections();
	void updateTriangles();
	void updateText();
	void update();

	void renderTriangles();
	void renderToolbar();
	void render();

	void run();
};


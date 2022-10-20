#pragma once
#include "Gui.h"
#include "Point.h"
#include "Mesh.h"
#include "Square.h"
#include <ctime>
#include <map>
#include <sstream>


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

	int tileSize;

	Mesh* mesh;
	std::vector<Point*> points; // Вектор с точками
	std::vector<Square*> squares;

	std::map<std::string, gui::Button*> buttons;
	std::map<std::string, gui::InputField*> inputFields;

	sf::Text text;

	sf::RectangleShape toolbar;


	void initVariables();
	void initWindow();
	void initFonts();
	void initMesh();
	void initPoints();
	void initToolBar();
	void initButtons();
	void initFields();
	void initText();
public:
	Core();
	~Core();

	bool addPoint(sf::Vector2f position);
	void addRandomPoint();

	void updateDt();
	void updateSfmlEvents();
	void updateMousePositions();
	void updateButtons();
	void updateFields();
	void updateText();
	void update();

	void renderPoints();
	void renderSquares();
	void renderToolbar();
	void render();

	void run();
};


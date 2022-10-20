#pragma once

#include <vector>
#include <map>
#include <list>

#include "Ball.h"

class Board
{
private:
	sf::RenderWindow* window;
	sf::Event sfEvents;

	int mapWidth;
	std::vector<int> map;

	sf::Vertex* mesh;
	int meshSize;
	sf::CircleShape* circle;
	sf::RectangleShape line;

	std::vector<sf::RectangleShape> lines;

	std::vector<sf::RectangleShape> columns;
	std::list<Ball*> balls;

	void initVariables();
	void initMap();
	void initWindow();

public:
	Board();
	virtual ~Board();

	//Functions
	void updateEvents();
	void updateInput();
	void updateBalls();
	void update();

	void renderMesh();
	void renderMap();
	void render();

	void run();
};


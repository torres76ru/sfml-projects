#pragma once
#include "Gui.h"
#include <algorithm>

class Triangle
{
private:
	sf::VertexArray triangle;

	bool intersected;

public:
	Triangle(sf::Vector2f vertex1, sf::Vector2f vertex2, sf::Vector2f vertex3, sf::Color borderColor);
	~Triangle();

	//Accessors
	const sf::VertexArray getVertex() const;
	const bool getIntersected() const;

	//Mutators
	void setCords(sf::Vector2f vertex1, sf::Vector2f vertex2, sf::Vector2f vertex3);
	void setColor(sf::Color color);
	void setIntersected(bool intersected);

	//Functions
	void updateIntersections(Triangle& triangle);
	void update();
	void render(sf::RenderTarget& target);
};


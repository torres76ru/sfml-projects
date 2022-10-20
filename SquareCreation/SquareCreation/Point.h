#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Point
{
private:
	sf::RectangleShape shape;
	int tileSize;
public:
	Point(sf::Vector2f position, int& tileSize);
	~Point();

	//Accesors
	const sf::Vector2f getPosition() const;

	void setPosition(sf::Vector2f position);

	void render(sf::RenderTarget& target);
};
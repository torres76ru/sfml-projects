#pragma once
#include <vector>
#include <iostream>
#include <ctime>
#include <map>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
class Piece
{
private:
	sf::CircleShape shape;
	float weight;
public:
	Piece(float x, float y, float r, float weight);
	virtual ~Piece();

	//Accessors
	const float getWeight() { return this->weight; }
	const sf::Vector2f getPosition() { return this->shape.getPosition(); }

	//Functions
	void update();
	void render(sf::RenderTarget& target);

};


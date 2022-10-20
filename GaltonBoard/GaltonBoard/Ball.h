#pragma once

#include <SFML/Graphics.hpp>
#include <ctime>
#include <math.h>
#include <iostream>

const float TILESIZE = 64.f;

class Ball
{
private:
	sf::CircleShape shape;

	float posRouteTargetX, posRouteTargetY;
	float speed;
	sf::Vector2f velocity;
	sf::Vector2u tilePos;

public:
	Ball(float pos_x, float pos_y, float radius);
	virtual ~Ball();

	// Сеттеры
	void setRouteTarget(float x, float y);
	void setVelocity();

	// Геттеры
	sf::Vector2u getTilePos() { return this->tilePos; }

	//Функции
	bool isRouteDone();
	void moveToRouteTarget();

	void update();
	void render(sf::RenderTarget& target);
};


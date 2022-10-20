#include "Ball.h"

Ball::Ball(float pos_x, float pos_y, float radius)
{
	this->tilePos = sf::Vector2u(
		pos_x / TILESIZE,
		pos_y / TILESIZE
	);
	
	this->posRouteTargetX = pos_x + TILESIZE / 2.f;
	this->posRouteTargetY = pos_y + TILESIZE / 2.f;

	this->shape.setPosition(pos_x + TILESIZE / 2.f, pos_y + TILESIZE / 2.f);
	this->shape.setRadius(radius);
	this->shape.setOrigin(radius, radius);
	this->shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 255));

	this->speed = 5.f;
}

Ball::~Ball()
{

}

void Ball::setRouteTarget(float x, float y)
{
	this->posRouteTargetX = x * TILESIZE + TILESIZE / 2.f;
	this->posRouteTargetY = y * TILESIZE + TILESIZE / 2.f;
	
	this->setVelocity();
}

void Ball::setVelocity()
{
	float lengthOfVector = sqrtf(
		powf(this->posRouteTargetX - this->shape.getPosition().x, 2.f) +
		powf(this->posRouteTargetY - this->shape.getPosition().y, 2.f)
	);

	this->velocity = sf::Vector2f(
		this->posRouteTargetX - this->shape.getPosition().x,
		this->posRouteTargetY - this->shape.getPosition().y
	);
	this->velocity /= lengthOfVector;

	this->velocity *= this->speed;
}

bool Ball::isRouteDone()
{
	if (this->posRouteTargetX == this->shape.getPosition().x && this->posRouteTargetY == this->shape.getPosition().y)
		return true;
	return false;
}

void Ball::moveToRouteTarget()
{
	/*
		Передвигает объект вдоль маршрута
	*/
	if (this->isRouteDone() == false)
	{
		this->shape.move(this->velocity);


		if (abs(this->posRouteTargetX - this->shape.getPosition().x) <= abs(this->velocity.x)&&
			abs(this->posRouteTargetY - this->shape.getPosition().y) <= abs(this->velocity.y))
		{
			this->shape.setPosition(sf::Vector2f(this->posRouteTargetX, this->posRouteTargetY));
		}
	}
}

void Ball::update()
{
	
	this->moveToRouteTarget();

	this->tilePos = sf::Vector2u(
		this->shape.getPosition().x / TILESIZE,
		this->shape.getPosition().y / TILESIZE
	);
}

void Ball::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}

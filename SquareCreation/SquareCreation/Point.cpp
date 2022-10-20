#include "Point.h"

Point::Point(sf::Vector2f position, int& tileSize)
{
	this->tileSize = tileSize;

	this->shape.setPosition(position * static_cast<float>(this->tileSize));
	this->shape.setSize(static_cast<sf::Vector2f>(sf::Vector2i(this->tileSize, this->tileSize)));
	this->shape.setFillColor(sf::Color::Color(247, 215, 77));
	this->shape.setOutlineThickness(-2.f);
	this->shape.setOutlineColor(sf::Color::Color(158, 33, 66, 255));
}

Point::~Point()
{
}

const sf::Vector2f Point::getPosition() const
{
	return this->shape.getPosition() / static_cast<float>(this->tileSize);
}

void Point::setPosition(sf::Vector2f position)
{
	this->shape.setPosition(position * static_cast<float>(this->tileSize));
}

void Point::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}

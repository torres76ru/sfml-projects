#include "Square.h"

Square::Square(float x, float y, float width, float height, int& tileSize)
{
	this->tileSize = tileSize;
	this->shape.setPosition(x * static_cast<float>(this->tileSize) + 4.f, y * static_cast<float>(this->tileSize) + 4.f);
	this->shape.setOutlineThickness(-this->tileSize / 2);

	this->shape.setSize(sf::Vector2f(
		(width - x) * static_cast<float>(this->tileSize) + static_cast<float>(tileSize) - 8.f,
		(width - x) * static_cast<float>(this->tileSize) + static_cast<float>(tileSize) - 8.f
	));

	this->shape.setOutlineColor(sf::Color::Color(158, 33, 66, 255));
	this->shape.setFillColor(sf::Color::Transparent);
}

Square::~Square()
{
}

void Square::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}

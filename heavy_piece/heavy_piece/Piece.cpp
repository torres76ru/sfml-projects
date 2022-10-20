#include "Piece.h"

Piece::Piece(float x, float y, float r, float weight)
{
	this->shape.setPosition(x, y);
	this->shape.setRadius(r);
	this->shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 255));
	this->shape.setOrigin(r, r);
	this->weight = weight;
}

Piece::~Piece()
{
}

void Piece::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}

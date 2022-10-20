#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Square
{
private:
	sf::RectangleShape shape;

	int tileSize;
public:
	//�����������
	Square(float x, float y, float width, float height, int& tileSize);
	~Square();

	void render(sf::RenderTarget& target);
};


#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Mesh
{
private:
	sf::VertexArray mesh;
public:
	Mesh(float x_start, float y_start, float x_end, float y_end, int& tileSize);

	void render(sf::RenderTarget& target);
};


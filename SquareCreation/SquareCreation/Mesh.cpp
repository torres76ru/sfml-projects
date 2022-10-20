#include "Mesh.h"

Mesh::Mesh(float x_start, float y_start, float x_end, float y_end, int& tileSize)
{
	int vertex_x = static_cast<int>((x_end - x_start) / tileSize) * 2;
	int vertex_y = static_cast<int>((y_end - y_start) / tileSize) * 2;

	sf::Color color = sf::Color::Color(40, 40, 40, 255);

	this->mesh = sf::VertexArray(sf::Lines, vertex_x + vertex_y);

	for (int i = 0; i < vertex_x / 2; i++)
	{
		this->mesh[i * 2].position = sf::Vector2f(i * tileSize, y_start);
		this->mesh[i * 2].color = color;
		this->mesh[i * 2 + 1].position = sf::Vector2f(i * tileSize, y_end);
		this->mesh[i * 2 + 1].color = color;
	}

	for (int i = 0; i < vertex_y / 2; i++)
	{
		this->mesh[vertex_x + i * 2].position = sf::Vector2f(x_start, i * tileSize);
		this->mesh[vertex_x + i * 2].color = color;
		this->mesh[vertex_x + i * 2 + 1].position = sf::Vector2f(x_end, i * tileSize);
		this->mesh[vertex_x + i * 2 + 1].color = color;
	}
}

void Mesh::render(sf::RenderTarget& target)
{
	target.draw(this->mesh);
}

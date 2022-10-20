#include "Triangle.h"


const double EPS = 1E-9;

inline int det(int a, int b, int c, int d) {
    return a * d - b * c;
}

inline bool between(int a, int b, double c) {
    return std::min(a, b) <= c + EPS && c <= std::max(a, b) + EPS;
}

inline bool intersect_1(int a, int b, int c, int d) {
    if (a > b)  std::swap(a, b);
    if (c > d)  std::swap(c, d);
    return std::max(a, c) <= std::min(b, d);
}

bool intersect(sf::Vector2i a, sf::Vector2i b, sf::Vector2i c, sf::Vector2i d) {
    int A1 = a.y - b.y, B1 = b.x - a.x, C1 = -A1 * a.x - B1 * a.y;
    int A2 = c.y - d.y, B2 = d.x - c.x, C2 = -A2 * c.x - B2 * c.y;
    int zn = det(A1, B1, A2, B2);
    if (zn != 0) {
        double x = -det(C1, B1, C2, B2) * 1. / zn;
        double y = -det(A1, C1, A2, C2) * 1. / zn;
        return between(a.x, b.x, x) && between(a.y, b.y, y)
            && between(c.x, d.x, x) && between(c.y, d.y, y);
    }
    else
        return det(A1, C1, A2, C2) == 0 && det(B1, C1, B2, C2) == 0
        && intersect_1(a.x, b.x, c.x, d.x)
        && intersect_1(a.y, b.y, c.y, d.y);
}

Triangle::Triangle(sf::Vector2f vertex1, sf::Vector2f vertex2, sf::Vector2f vertex3, sf::Color borderColor)
{

    triangle = sf::VertexArray(sf::LineStrip, 4);
    triangle[0].position = vertex1;
    triangle[1].position = vertex2;
    triangle[2].position = vertex3;
    triangle[3].position = vertex1;

    triangle[0].color = borderColor;
    triangle[1].color = borderColor;
    triangle[2].color = borderColor;
    triangle[3].color = borderColor;

    this->intersected = false;
}

Triangle::~Triangle()
{

}

//Accessors
const sf::VertexArray Triangle::getVertex() const
{
    return this->triangle;
}

const bool Triangle::getIntersected() const
{
    return this->intersected;
}

void Triangle::setCords(sf::Vector2f vertex1, sf::Vector2f vertex2, sf::Vector2f vertex3)
{
    triangle[0].position = vertex1;
    triangle[1].position = vertex2;
    triangle[2].position = vertex3;
    triangle[3].position = vertex1;
}

//Mutators
void Triangle::setColor(sf::Color color)
{
    for (int i = 0; i < 4; i++)
    {
        triangle[i].color = color;
    }
}

void Triangle::setIntersected(bool intersected)
{
    this->intersected = intersected;
}

//Functions
void Triangle::updateIntersections(Triangle& triangle_)
{
    sf::VertexArray triangle_vertex = triangle_.getVertex();

    bool f = false;
    for (int i = 0; i < 3 && !f; i++)
    {
        for (int j = 0; j < 3 && !f; j++)
        {
            f = intersect(
                static_cast<sf::Vector2i>(this->triangle[i].position),
                static_cast<sf::Vector2i>(this->triangle[i + 1].position),
                static_cast<sf::Vector2i>(triangle_vertex[j].position),
                static_cast<sf::Vector2i>(triangle_vertex[j + 1].position)
            );
        }
    }

    if (f)
    {
        this->intersected = true;
        triangle_.setIntersected(true);
    }

}

void Triangle::update()
{
    if (this->intersected)
        this->setColor(sf::Color::Red);
    else
        this->setColor(sf::Color::Blue);
}

void Triangle::render(sf::RenderTarget& target)
{
    target.draw(triangle);
}



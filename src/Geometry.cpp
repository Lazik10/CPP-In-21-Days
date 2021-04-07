#include "Geometry.h"

Shape::Shape()
{
    std::cout << "Shape's constructor...\n";
}

Shape::~Shape()
{
    std::cout << "Shape's destructor...\n";
}

Shape::Shape(const Shape& shape)
{
    std::cout << "Shape's copy constructor...\n";
}

Shape* Shape::Clone() const
{
    std::cout << "Clone method creating new Shape object based on current object data members...\n"
        "also calling Shape constructor";
    return new Shape(*this);
}

void Shape::Draw() const
{
    std::cout << "Drawing shape...\n";
}

Rectangle::Rectangle()
{
    std::cout << "Rectangle's constructor...\n";
    _width = 5;
    _height = 10;
}

Rectangle::Rectangle(int width, int height):
    _width(width), _height(height) // Initialization part
{
    // Empty body of c_tor
}

Rectangle::~Rectangle()
{
    std::cout << "Rectangle's destructor...\n";
}

Rectangle::Rectangle(const Rectangle& rectangle) :
    Shape()
{
    std::cout << "Rectangle's copy constructor...\n";
}

Rectangle* Rectangle::Clone() const
{
    std::cout << "Clone method creating new Rectangle object based on current object data members...\n"
        "also calling Shape constructor";
    return new Rectangle(*this);
}

void Rectangle::Draw() const
{
    std::cout << "Drawing rectangle...\n";
    DrawRectangle(_width, _height);
}

void Rectangle::DrawRectangle(int width, int height) const
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

void Rectangle::DrawRectangle(int width, int height, bool actual) const
{
    int width_draw, height_draw;

    if (actual == true)
    {
        width_draw = _width;
        height_draw = _height;
    }
    else
    {
        width_draw = width;
        height_draw = height;
    }

    std::cout << "width is: " << width_draw << " and height is: " << height_draw << "\n";
    DrawRectangle(width_draw, height_draw);
}

Circle::Circle()
{
    m_radius = new float;
    *m_radius = 5.0f;
}

Circle::Circle(float radius)
{
    m_radius = new float;
    *m_radius = radius;
}

Circle::~Circle()
{
    m_radius = nullptr;
    delete m_radius;
}

Circle& Circle::operator++()
{
    (*m_radius)++;
    return *this;
}

Circle& Circle::operator++(int)
{
    ++(*m_radius);
    return *this;
}

Circle& Circle::operator=(const Circle circle)
{
    if (this == &circle)
        return *this;

    std::cout << "\nAddress of m_raidus is: " << m_radius << "\nand adress of circle is: " << &circle.m_radius;
    *m_radius = *circle.m_radius;
    return *this;
}

Square::Square()
{
    std::cout << "Square's constructor...\n";
}

Square::Square(int _width) :
    Rectangle(_width, _width)
{

}

Square::~Square()
{
    std::cout << "Square's destructor...\n";
}

void Square::Draw() const
{
    std::cout << "Drawing circle...\n";
}

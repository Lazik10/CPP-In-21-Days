#pragma once

#include <iostream>

class Shape
{
public:
    Shape();
    virtual ~Shape();

    Shape(const Shape& shape);
    virtual Shape* Clone() const;

    virtual void Draw() const;

private:

};

class Rectangle : public Shape
{
public:
	Rectangle();
	Rectangle(int width, int height);
	virtual ~Rectangle();

    Rectangle(const Rectangle& rectangle);
    Rectangle* Clone() const;

	// Overloaded member functions
	void Draw() const override;
	void DrawRectangle(int width, int height) const;
	void DrawRectangle(int width, int heigth, bool actual) const;

private:
	int _width;
	int _height;
};

class Square : public Rectangle
{
public:
    Square();
    Square(int _width);
    virtual ~Square();

    void Draw() const override;
private:

};

class Circle
{
public:
    Circle();
	Circle(float radius);
	~Circle();

	inline void SetRadius(float radius) { *m_radius = radius; };
	inline float GetRadius() { return *m_radius; };

	Circle& operator++();
	Circle& operator++(int);
	Circle& operator=(const Circle circle);

private:
	float* m_radius;
};

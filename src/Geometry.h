#pragma once

#include <iostream>

class Rectangle
{
public:
	Rectangle();
	Rectangle(int width, int height);
	~Rectangle();

	// Overloaded member functions
	void DrawRectangle() const;
	void DrawRectangle(int width, int height) const;
	void DrawRectangle(int width, int heigth, bool actual) const;

private:
	int _width;
	int _height;
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

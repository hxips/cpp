#pragma once
#include <iostream>
#include <cmath>
#include "point.h"


class Circle
{
private:
	Point mCenter;
	float mRadius;

public:
	void setRadius(float aradius);
	void setCenter(const Point& acenter);

	Circle(const Point& acenter, float aradius);
	Circle();
	Circle(const Circle& circle);

	Point& getCenter() const;
	float getRadius() const;

	float getArea();
	float getDistance(const Point& p) const;
	bool isColliding(const Circle& c);
	void move(const Point& p);
};
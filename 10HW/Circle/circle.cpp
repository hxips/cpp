#include <iostream>
#include <cmath>
#include "point.h"


void Circle::setRadius(float aradius)
{
	if (aradius <= 0)
		mRadius = 0;
	else
		mRadius = aradius;

	return;
}

void Circle::setCenter(const Point& acenter)
{
	mCenter = acenter;

	return;
}

Circle::Circle(const Point& acenter, float aradius)
{
	setRadius(aradius);
	setCenter(acenter);
}

Circle::Circle()
{
	mCenter = { 0, 0 };
	mRadius = 0;
}

Circle::Circle(const Circle& circle)
{
	mCenter = circle.mCenter;
	mRadius = circle.mRadius;
}

Point& Circle::getCenter() const
{
	return (Point&)mCenter;
}

float Circle::getRadius() const
{
	return mRadius;
}

float Circle::getArea()
{
	float res = 3.14 * mRadius * mRadius;

	return res;
}

float Circle::getDistance(const Point& p) const
{
	float center_point = mCenter.distance(p);

	return fabs(center_point - mRadius);
}

bool Circle::isColliding(const Circle& c)
{
	float d_centers = mCenter.distance(c);

	if (d_centers < mRadius || d_centers < c.mRadius)
		return (fabs(mRadius - c.mRadius) < d_centers);
	else
		return (mRadius + c.mRadius > d);
}

void Circle::move(const Point& p)
{
	mCenter = mCenter + p;

	return;
}
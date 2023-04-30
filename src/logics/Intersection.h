#pragma once
#include "Triangle.h"


class Intersection
{
private:
	std::vector<Point> CoordinateIntersection;
public:
	void SetIntersectionPoint(Point PolyPoint);
	std::vector<Point> GetCoordinatesIntersection() { return CoordinateIntersection; }
	void TriangleIntersectionContour(Intersection& IntersectionPoints, Triangle Figure1, Triangle Figure2);
	void PrintIntersectionPoints();
	~Intersection() {}
};

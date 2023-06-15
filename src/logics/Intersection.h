#pragma once
#include "Point.h"


class Intersection
{
private:
	std::vector<Point> CoordinateIntersection;
    int size;
public:
    Intersection(int sz,std::vector<Point> Points);
    bool IsIdenticalIntersection(Intersection Figure1, Intersection Figure2);
	void SetIntersectionPoint(Point PolyPoint);
	std::vector<Point> GetCoordinatesIntersection() { return CoordinateIntersection; }
    int GetSize(){ return size;}
	void FigureIntersectionContour(Intersection &IntersectionPoints, Intersection Figure1, Intersection Figure2);
	void PrintIntersectionPoints();
    void SetCoordinatesIntersection(std::vector<Point> Points);
    void SetSize(int size);
	~Intersection() {}
};
void FindPointsInsideFigure(Intersection& AllPoints, std::vector<Point> Figure1, std::vector<Point> Figure2);
int Orientation(Point p, Point q, Point r);
bool Compare(Point p, Point q);
int FindMinPoint(std::vector<Point>& points);
std::vector<Point> ConvexHull(std::vector<Point>& points);
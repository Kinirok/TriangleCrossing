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

int Orientation(Point p, Point q, Point r);
bool Compare(Point p, Point q);
int FindMinPoint(std::vector<Point>& points);
std::vector<Point> ConvexHull(std::vector<Point>& points);
bool IsInsideFigure(Point Point, Intersection Figure1);
bool IsVertex(Point Point, Intersection Figure);
void FindPointsInsideFigure(Intersection& AllPoints, Intersection Figure1, Intersection Figure2);

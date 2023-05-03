#pragma once
#include "Intersection.h"

class Line
{
private:
	double A;
	double B;
	double C;
	Point FirstPoint;
	Point SecondPoint;
public:
	Line(Point FirstPoint, Point SecondPoint);
	Line();
	double GetA() { return A; }
	double GetB() { return B; }
	double GetC() { return C; }
	void LinesTriangle(std::vector<Line>& LinesFigure, Triangle Figure);
	double DeterminantMatrix2x2(double A11, double A12, double A21, double A22);
	void IntersectionOfLines(Intersection& PolygonPoints, Line Eq1, Line Eq2);
};

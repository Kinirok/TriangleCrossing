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
	Point GetFirst() { return FirstPoint; }
	double GetA() { return A; }
	double GetB() { return B; }
	double GetC() { return C; }
	double GetXbyY(double y) { return (-this->GetB() * y - this->GetC()) / this->GetA(); }
	double GetYbyX(double x) { return (-this->GetA() * x - this->GetC()) / this->GetB(); }
	void LinesIntersection(std::vector<Line> &LinesFigure, Intersection Figure);
	double DeterminantMatrix2x2(double A11, double A12, double A21, double A22);
	void IntersectionOfLines(Intersection& PolygonPoints, Line Eq1, Line Eq2);
};

#include "Triangle.h"

//standart initialization
Triangle::Triangle()
{
	Point NullCoordinates;
	for (int i = 0; i < 3; i++)
	{
		CoordinateTriangle.push_back(NullCoordinates);
	}
}

//initialization using 3 point
Triangle::Triangle(Point Ver1, Point Ver2, Point Ver3)
{
	CoordinateTriangle.push_back(Ver1);
	CoordinateTriangle.push_back(Ver2);
	CoordinateTriangle.push_back(Ver3);
}


//check if Triangle are the same
bool Triangle::IsIdenticalTriangles(Triangle Figure1, Triangle Figure2) {
	for (int i = 0;i < 3;++i) {
		int j = 0;
		for (;j < 3;j++) {
			if (Figure1.CoordinateTriangle[i].GetX() == Figure2.CoordinateTriangle[j].GetX() and
				Figure1.CoordinateTriangle[i].GetY() == Figure2.CoordinateTriangle[j].GetY()) {
				break;
			}
		}
		if (j == 3) {
			return false;
		}
	}
	return true; // the same
}


//check if area of Triangle more than 0; in this case this is a Triangle
bool Triangle::IsTriangle() {
	double side1 = CoordinateTriangle[0].DistanceTo(CoordinateTriangle[1]);
	double side2 = CoordinateTriangle[1].DistanceTo(CoordinateTriangle[2]);
	double side3 = CoordinateTriangle[2].DistanceTo(CoordinateTriangle[0]);
	double s = (side1 + side2 + side3) / 2;
	double area = std::pow((s * (s - side1) * (s - side2) * (s - side3)), 0.5);
	if (area < 0.0000001) {
		return false;
	}
	return true;
}

void Triangle::PrintTriangle() {
	std::cout << "Triangle:" << std::endl;
	CoordinateTriangle[0].PrintPoint();
	CoordinateTriangle[1].PrintPoint();
	CoordinateTriangle[2].PrintPoint();
}
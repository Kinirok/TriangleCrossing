#pragma once
#include <iostream>
#include <vector>
class Point
{
private:
	double x, y;
public:
	Point() :x(0), y(0) {}
	Point(double XC, double YC) {
		x = XC;
		y = YC;
	};
	double GetX() { return x; }
	double GetY() { return y; }

	double DistanceTo(Point OtherPoint) {
		double dx = x - OtherPoint.x;
		double dy = y - OtherPoint.y;
		return std::pow((dx * dx + dy * dy),0.5);
	}
	void PrintPoint(){
		std::cout << "(" << x << ", " << y << ")" << std::endl;
	};



    ~Point() {}
};


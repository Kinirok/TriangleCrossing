#pragma once
#include "Point.h"



class Triangle {
private:
    std::vector<Point> CoordinateTriangle;
public:
    Triangle();
    Triangle(Point Ver1, Point Ver2, Point  Ver3);
    void PrintTriangle();
    bool IsIdenticalTriangles(Triangle Figure1, Triangle Figure2);
    bool IsTriangle();
    std::vector<Point> GetCoordinatesTriangle() { return CoordinateTriangle; }
    ~Triangle() {}
};
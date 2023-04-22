#include "Intersection.h"
#include "Line.h"



void Intersection::PrintIntersectionPoints(){
	std::cout << "Intersection " << std::endl;;
	for (int i =0 ; i < CoordinateIntersection.size(); i++){
		std::cout << "Point "<<i+1<<" ";
		CoordinateIntersection[i].PrintPoint();
	}
}

void Intersection::SetIntersectionPoint(Point IntersectionPoint){
	CoordinateIntersection.push_back(IntersectionPoint);
}


void Intersection::TriangleIntersectionContour(Intersection& IntersectionPoints, Triangle Figure1, Triangle Figure2){
	Line Lines;
	std::vector<Line> LinesFigure1, LinesFigure2;

	Lines.LinesTriangle(LinesFigure1, Figure1);
	Lines.LinesTriangle(LinesFigure2, Figure2);

	for (int i = 0; i < LinesFigure1.size(); i++)
	{
		for (int j = 0; j < LinesFigure2.size(); j++)
		{
			Lines.IntersectionOfLines(IntersectionPoints, LinesFigure1[i], LinesFigure2[j]);
		}
	}
}
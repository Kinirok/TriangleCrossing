#include "Line.h"

Line::Line(){
	A = 0;
	B = 0;
	C = 0;
	Point FirstPoint(0,0);
	Point SecondPoint(0, 0);
}


Line::Line(Point FirstPoint, Point SecondPoint) {
	A= FirstPoint.GetY() - SecondPoint.GetY();
	B = SecondPoint.GetX() - FirstPoint.GetX();
	C = FirstPoint.GetX() * SecondPoint.GetY() - SecondPoint.GetX() * FirstPoint.GetY();
	if (FirstPoint.GetX() < SecondPoint.GetX()){
		this->FirstPoint = FirstPoint;
		this->SecondPoint = SecondPoint;
	}
	else if (FirstPoint.GetX() == SecondPoint.GetX()){
		if (FirstPoint.GetY() < SecondPoint.GetY()){
			this->FirstPoint = FirstPoint;
			this->SecondPoint = SecondPoint;
		}
		else{
			this->FirstPoint = SecondPoint;
			this->SecondPoint = FirstPoint;
		}
	}
	else{
		this->FirstPoint = SecondPoint;
		this->SecondPoint = FirstPoint;
	}
}

void Line::LinesTriangle(std::vector<Line>& LinesFigure, Triangle Figure){
	Line Line1Figure(Figure.GetCoordinatesTriangle()[0], Figure.GetCoordinatesTriangle()[1]);
	Line Line2Figure(Figure.GetCoordinatesTriangle()[1], Figure.GetCoordinatesTriangle()[2]);
	Line Line3Figure(Figure.GetCoordinatesTriangle()[2], Figure.GetCoordinatesTriangle()[0]);

	LinesFigure.push_back(Line1Figure);
	LinesFigure.push_back(Line2Figure);
	LinesFigure.push_back(Line3Figure);
}



double Line::DeterminantMatrix2x2(double A11, double A12, double A21, double A22){
	return A11 * A22 - A12 * A21;
}

void Line::IntersectionOfLines(Intersection& PolygonPoints, Line Eq1, Line Eq2){
	//Kramer
	double Determinant = DeterminantMatrix2x2(Eq1.GetA(), Eq1.GetB(), Eq2.GetA(), Eq2.GetB());
	if (Determinant == 0){
		return;
	}

	double DeterminantX = DeterminantMatrix2x2(-Eq1.C, Eq1.B, -Eq2.C, Eq2.B);

	double DeterminantY = DeterminantMatrix2x2(Eq1.A, -Eq1.C, Eq2.A, -Eq2.C);

	Point PointIntersection(DeterminantX / Determinant, DeterminantY / Determinant);


	//where point locate
	if ((PointIntersection.GetX() < Eq1.FirstPoint.GetX() or PointIntersection.GetX() > Eq1.SecondPoint.GetX()) or (PointIntersection.GetX() < Eq2.FirstPoint.GetX() or PointIntersection.GetX() > Eq2.SecondPoint.GetX())){
		return;//the point is located behind or in front of the segments
	}
	if (PointIntersection.GetX() == Eq1.FirstPoint.GetX() && PointIntersection.GetX() == Eq1.SecondPoint.GetX()){//for the triangle line 1
		if (PointIntersection.GetY() < Eq1.FirstPoint.GetY() || PointIntersection.GetY() > Eq1.SecondPoint.GetY()){
			return;
		}
	}
	else if (PointIntersection.GetX() == Eq2.FirstPoint.GetX() and PointIntersection.GetX() == Eq2.SecondPoint.GetX()){//for the triangle line 2
		if (PointIntersection.GetY() < Eq2.FirstPoint.GetY() || PointIntersection.GetY() > Eq2.SecondPoint.GetY()){
			return;
		}
	}
	//if point one of vertex 
	if ((PointIntersection.GetX() == Eq1.FirstPoint.GetX() and PointIntersection.GetY() == Eq1.FirstPoint.GetY()) 
		or (PointIntersection.GetX() == Eq1.SecondPoint.GetX() and PointIntersection.GetY() == Eq1.SecondPoint.GetY())){
		//check if point already added
		for (int i = 0; i < PolygonPoints.GetCoordinatesIntersection().size(); i++){
			if (PolygonPoints.GetCoordinatesIntersection()[i].GetX() == PointIntersection.GetX() 
				and PolygonPoints.GetCoordinatesIntersection()[i].GetY() == PointIntersection.GetY()){
				return;//already added
			}
		}
	}
	PolygonPoints.SetIntersectionPoint(PointIntersection);
}
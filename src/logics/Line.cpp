#include "Line.h"

Line::Line() {
	this->A = 0;
	this->B = 0;
	this->C = 0;
	this->FirstPoint = Point(0, 0);
	this->SecondPoint = Point(0, 0);
}


Line::Line(Point FirstPoint, Point SecondPoint) {
	this->A = FirstPoint.GetY() - SecondPoint.GetY();
	this->B = SecondPoint.GetX() - FirstPoint.GetX();
	this->C = FirstPoint.GetX() * SecondPoint.GetY() - SecondPoint.GetX() * FirstPoint.GetY();
	if (FirstPoint.GetX() < SecondPoint.GetX()) {
		this->FirstPoint = FirstPoint;
		this->SecondPoint = SecondPoint;
	}
	else if (FirstPoint.GetX() == SecondPoint.GetX()) {
		if (FirstPoint.GetY() < SecondPoint.GetY()) {
			this->FirstPoint = FirstPoint;
			this->SecondPoint = SecondPoint;
		}
		else {
			this->FirstPoint = SecondPoint;
			this->SecondPoint = FirstPoint;
		}
	}
	else {
		this->FirstPoint = SecondPoint;
		this->SecondPoint = FirstPoint;
	}
}

void Line::LinesIntersection(std::vector<Line>& LinesFigure, Intersection Figure) {
	int size = Figure.GetSize();
	for (int i = 0; i < size - 1; i++) {
		Line LineIFigure(Figure.GetCoordinatesIntersection()[i], Figure.GetCoordinatesIntersection()[i + 1]);
		LinesFigure.push_back(LineIFigure);
	}

	Line LastLineFigure(Figure.GetCoordinatesIntersection()[size - 1], Figure.GetCoordinatesIntersection()[0]);
	LinesFigure.push_back(LastLineFigure);
}




double Line::DeterminantMatrix2x2(double A11, double A12, double A21, double A22) {
	return A11 * A22 - A12 * A21;
}

void Line::IntersectionOfLines(Intersection& PolygonPoints, Line Eq1, Line Eq2) {
	//Kramer

	double Determinant = DeterminantMatrix2x2(Eq1.GetA(), Eq1.GetB(), Eq2.GetA(), Eq2.GetB());
	if (Determinant == 0) {
		return;
	}

	double DeterminantX = DeterminantMatrix2x2(-Eq1.C, Eq1.B, -Eq2.C, Eq2.B);

	double DeterminantY = DeterminantMatrix2x2(Eq1.A, -Eq1.C, Eq2.A, -Eq2.C);

	Point PointIntersection(DeterminantX / Determinant, DeterminantY / Determinant);


	//where point locate
	if ((PointIntersection.GetX() < Eq1.FirstPoint.GetX() or PointIntersection.GetX() > Eq1.SecondPoint.GetX()) or (PointIntersection.GetX() < Eq2.FirstPoint.GetX() or PointIntersection.GetX() > Eq2.SecondPoint.GetX())) {
		return;//the point is located behind or in front of the segments
	}
	if (PointIntersection.GetX() == Eq1.FirstPoint.GetX() && PointIntersection.GetX() == Eq1.SecondPoint.GetX()) {//for the triangle line 1
		if (PointIntersection.GetY() < Eq1.FirstPoint.GetY() || PointIntersection.GetY() > Eq1.SecondPoint.GetY()) {
			return;
		}
	}
	else if (PointIntersection.GetX() == Eq2.FirstPoint.GetX() and PointIntersection.GetX() == Eq2.SecondPoint.GetX()) {//for the triangle line 2
		if (PointIntersection.GetY() < Eq2.FirstPoint.GetY() || PointIntersection.GetY() > Eq2.SecondPoint.GetY()) {
			return;
		}
	}
	for (int i = 0; i < PolygonPoints.GetCoordinatesIntersection().size(); i++) {
		if (PolygonPoints.GetCoordinatesIntersection()[i].GetX() == PointIntersection.GetX()
			and PolygonPoints.GetCoordinatesIntersection()[i].GetY() == PointIntersection.GetY()) {
			return;//already added
		}
	}
	PolygonPoints.SetIntersectionPoint(PointIntersection);
}

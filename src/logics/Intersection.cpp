#include "Intersection.h"
#include "Line.h"


Intersection::Intersection(int sz,std::vector<Point> Points)
{
    size=sz;
    CoordinateIntersection=Points;
}

bool Intersection::IsIdenticalIntersection(Intersection Figure1, Intersection Figure2){
    int FirstIntersectionSSize=Figure1.GetSize();
    int SecondIntersectionSSize=Figure2.GetSize();
    int flag=0;
    for (int i = 0;i < FirstIntersectionSSize;++i) {
        int j = 0;
        for (;j < SecondIntersectionSSize;j++) {
            if (Figure1.CoordinateIntersection[i].GetX() == Figure2.CoordinateIntersection[j].GetX() and
                Figure1.CoordinateIntersection[i].GetY() == Figure2.CoordinateIntersection[j].GetY()) {
                break;
            }
        }
        if (j == SecondIntersectionSSize) {
            return false;
        }
    }
    return true; // the same
}

void Intersection::PrintIntersectionPoints(){
	std::cout << "Figure " << std::endl;;
	for (int i =0 ; i < CoordinateIntersection.size(); i++){
		std::cout << "Point "<<i+1<<" ";
		CoordinateIntersection[i].PrintPoint();
	}
}

void Intersection::SetIntersectionPoint(Point IntersectionPoint){
	CoordinateIntersection.push_back(IntersectionPoint);
}

void Intersection::FigureIntersectionContour(Intersection &IntersectionPoints, Intersection Figure1, Intersection Figure2){
	Line Lines;
	std::vector<Line> LinesFigure1, LinesFigure2;

    Lines.LinesIntersection(LinesFigure1, Figure1);
    Lines.LinesIntersection(LinesFigure2, Figure2);

	for (int i = 0; i < LinesFigure1.size(); i++)
	{
		for (int j = 0; j < LinesFigure2.size(); j++)
		{
			Lines.IntersectionOfLines(IntersectionPoints, LinesFigure1[i], LinesFigure2[j]);
		}
	}
}

void Intersection::SetCoordinatesIntersection(std::vector<Point> Points){
    CoordinateIntersection=Points;
}

void Intersection::SetSize(int sz){
    size=sz;
}

// Function for determining the position of a point relative to a straight line
int Orientation(Point p, Point q, Point r) {
    int val = (q.GetY() - p.GetY()) * (r.GetX() - q.GetX() ) - (q.GetX()  - p.GetX() ) * (r.GetY() - q.GetY());

    if (val == 0)
        return 0;  // Точки коллинеарны

    return (val > 0) ? 1 : 2;  // 1 - По часовой стрелке, 2 - Против часовой стрелки
}

// Function for comparing two points based on the polar angle relative to point p
bool Compare(Point p, Point q) {
    int orientation_val = Orientation(Point(0, 0), p, q);

    if (orientation_val == 0)
        return (p.GetX() * p.GetX() + p.GetY() * p.GetY()) < (q.GetX() * q.GetX() + q.GetY() * q.GetY());  // Сортировка по расстоянию от начала координат

    return (orientation_val == 2);  // Сортировка против часовой стрелки
}

// Function for finding the minimum point (lowest, leftmost)
int FindMinPoint(std::vector<Point>& points) {
    int minIndex = 0;
    int minY = points[0].GetY();
    int minX = points[0].GetX();

    for (int i = 1; i < points.size(); i++) {
        int y = points[i].GetY();
        int x = points[i].GetX();

        if ((y < minY) || (y == minY && x < minX)) {
            minY = y;
            minX = x;
            minIndex = i;
        }
    }
    return minIndex;
}

// Function for sorting points to form a convex shape
std::vector<Point> ConvexHull(std::vector<Point>& points) {
    std::vector<Point> convexHullPoints;

    // Найти точку с минимальными координатами (самая нижняя, самая левая)
    int minIndex = FindMinPoint(points);

    // Переместить точку с минимальными координатами в начало массива
    std::swap(points[0], points[minIndex]);

    // Сортировать остальные точки относительно первой точки
    std::sort(points.begin() + 1, points.end(), Compare);

    // Если имеются точки с одинаковым углом, удалить все точки, кроме самой удаленной
    int m = 1;  // Размер измененного массива
    for (int i = 1; i < points.size(); i++) {
        while (i < points.size() - 1 && Orientation(Point(0, 0), points[i], points[i + 1]) == 0)
            i++;

        points[m] = points[i];
        m++;
    }

    std::vector<Point> stack;
    stack.push_back(points[0]);
    stack.push_back(points[1]);
    stack.push_back(points[2]);


    for (int i = 3; i < m; i++) {
        while (stack.size() > 1 && Orientation(stack[stack.size() - 2], stack[stack.size() - 1], points[i]) != 2)
            stack.pop_back();

        stack.push_back(points[i]);
    }

    convexHullPoints = stack;

    return convexHullPoints;
}
void FindPointsInsideFigure(Intersection& AllPoints, std::vector<Point> Figure1, std::vector<Point> Figure2) {
    std::vector<Point> insidePoints = AllPoints.GetCoordinatesIntersection();
    Line First;
    Line Second;
    for (int i = 0; i < Figure1.size(); i++) {
        bool isInside = true;
        for (int j = 0; j < Figure2.size(); j++) {
            int indexForEnd = j + 1;
            int indexForBegin = j - 1;
            if (j == Figure2.size() - 1) {
                indexForEnd = 0;
            }
            else if (j == 0) {
                indexForBegin = Figure2.size() - 1;
            }
            if ((Figure2[j].GetY() <= Figure2[indexForBegin].GetY() and Figure2[j].GetY() <= Figure2[indexForEnd].GetY()) or ((Figure2[j].GetY() >= Figure2[indexForBegin].GetY() and Figure2[j].GetY() >= Figure2[indexForEnd].GetY()))) {        
                if (Figure2[indexForBegin].GetX() < Figure2[indexForEnd].GetX()) {
                    First = Line::Line(Figure2[j], Figure2[indexForBegin]);//0-2              
                    Second = Line::Line(Figure2[j], Figure2[indexForEnd]);//0-1
                }
                else {
                    First = Line::Line(Figure2[j], Figure2[indexForEnd]);
                    Second = Line::Line(Figure2[j], Figure2[indexForBegin]);
                }               
                bool isUpperSide = true;
                for (int k = 0; k < Figure2.size(); k++) {
                    if (Figure2[j].GetY() > Figure2[k].GetY()) {
                        isUpperSide = false;
                    }
                }
                if ((isUpperSide == true and Figure1[i].GetY() > Figure2[j].GetY()) or (isUpperSide == false and Figure1[i].GetY() < Figure2[j].GetY())) {
                    if (First.GetA() != 0 or Second.GetA() != 0) {
                        if (!(First.GetXbyY(Figure1[i].GetY()) < Figure1[i].GetX() < Second.GetXbyY(Figure1[i].GetY()))) {
                            isInside = false;
                            break;
                        }
                    }
                    else if (First.GetA() == 0 and Second.GetA() != 0) {                        
                        if (!(Figure1[i].GetX() < Second.GetXbyY(Figure1[i].GetY()))) {
                            isInside = false;
                            break;
                        }
                    }
                    else if (First.GetA() != 0 and Second.GetA() == 0) {
                        if (!(First.GetXbyY(Figure1[i].GetY()) < Figure1[i].GetX())) {
                            isInside = false;
                            break;
                        }
                    }
                }
                else {
                    isInside = false;
                    break;
                }
            }
            else {                
                if (Figure2[indexForBegin].GetX() < Figure2[indexForEnd].GetX()) {
                    First = Line::Line(Figure2[j], Figure2[indexForBegin]);
                    Second = Line::Line(Figure2[j], Figure2[indexForEnd]);
                }
                else {
                    First = Line::Line(Figure2[j], Figure2[indexForEnd]);
                    Second = Line::Line(Figure2[j], Figure2[indexForBegin]);
                }
                bool isRightSide = true;
                for (int k = 0; k < Figure2.size(); k++) {
                    if (Figure2[j].GetX() > Figure2[k].GetX()) {
                        isRightSide = false;
                    }
                }
                if ((isRightSide == true and Figure1[i].GetX() > Figure2[j].GetX()) or (isRightSide == false and Figure1[i].GetX() < Figure2[j].GetX())) {
                    if (First.GetB() != 0 or Second.GetB() != 0) {
                        if (!(First.GetYbyX(Figure1[i].GetX()) < Figure1[i].GetY() < Second.GetYbyX(Figure1[i].GetX()))) {
                            
                            isInside = false;
                            break;
                        }
                    }
                    else if (First.GetB() == 0 and Second.GetB() != 0) {                        
                        if (!(Figure1[i].GetY() < Second.GetYbyX(Figure1[i].GetX()))) {
                            isInside = false;
                            break;
                        }
                    }
                    else if (First.GetB() != 0 and Second.GetB() == 0) {                        
                        if (!(First.GetYbyX(Figure1[i].GetX()) < Figure1[i].GetY())) {
                            isInside = false;
                            break;
                        }
                    }
                }
                else {
                    isInside = false;
                    break;
                }
            }
        }
        if (isInside == true) {            
            insidePoints.push_back(Figure1[i]);
        }
    }
    for (int i = 0; i < Figure2.size(); i++) {
        bool isInside = true;
        for (int j = 0; j < Figure1.size(); j++) {
            int indexForEnd = j + 1;
            int indexForBegin = j - 1;
            if (j == Figure1.size() - 1) {
                indexForEnd = 0;
            }
            else if (j == 0) {
                indexForBegin = Figure1.size() - 1;
            }
            if ((Figure1[j].GetY() <= Figure1[indexForBegin].GetY() and Figure1[j].GetY() <= Figure1[indexForEnd].GetY()) or ((Figure1[j].GetY() >= Figure1[indexForBegin].GetY() and Figure1[j].GetY() >= Figure1[indexForEnd].GetY()))) {
                if (Figure1[indexForBegin].GetX() < Figure1[indexForEnd].GetX()) {
                    First= Line::Line(Figure1[j], Figure1[indexForBegin]);
                    Second = Line::Line(Figure1[j], Figure1[indexForEnd]);
                }
                else {
                    First = Line::Line(Figure1[j], Figure1[indexForEnd]);
                    Second = Line::Line(Figure1[j], Figure1[indexForBegin]);
                }
                bool isUpperSide = true;
                for (int k = 0; k < Figure1.size(); k++) {
                    if (Figure1[j].GetY() > Figure1[k].GetY()) {
                        isUpperSide = false;
                    }
                }
                if ((isUpperSide == true and Figure2[i].GetY() > Figure1[j].GetY()) or (isUpperSide == false and Figure2[i].GetY() < Figure1[j].GetY())) {
                    if (First.GetA() != 0 or Second.GetA() != 0) {
                        if (!(First.GetXbyY(Figure2[i].GetY()) < Figure2[i].GetX() < Second.GetXbyY(Figure2[i].GetY()))) {
                            isInside = false;
                            break;
                        }
                    }
                    else if (First.GetA() == 0 and Second.GetA() != 0) {
                        if (!(Figure2[i].GetX() < Second.GetXbyY(Figure2[i].GetY()))) {
                            isInside = false;
                            break;
                        }
                    }
                    else if (First.GetA() != 0 and Second.GetA() == 0) {
                        if (!(First.GetXbyY(Figure2[i].GetY()) < Figure2[i].GetX())) {
                            isInside = false;
                            break;
                        }
                    }
                }
                else {
                    isInside = false;
                    break;
                }
            }
            else {
                if (Figure1[indexForBegin].GetX() < Figure1[indexForEnd].GetX()) {
                    First = Line::Line(Figure1[j], Figure1[indexForBegin]);
                    Second = Line::Line(Figure1[j], Figure1[indexForEnd]);
                }
                else {
                    First = Line::Line(Figure1[j], Figure1[indexForEnd]);
                    Second = Line::Line(Figure1[j], Figure1[indexForBegin]);
                }
                bool isRightSide = true;
                for (int k = 0; k < Figure1.size(); k++) {
                    if (Figure1[j].GetX() > Figure1[k].GetX()) {
                        isRightSide = false;
                    }
                }
                if ((isRightSide == true and Figure2[i].GetX() > Figure1[j].GetX()) or (isRightSide == false and Figure2[i].GetX() < Figure1[j].GetX())) {
                    if (First.GetB() != 0 or Second.GetB() != 0) {
                        if (!(First.GetYbyX(Figure2[i].GetX()) < Figure2[i].GetY() < Second.GetYbyX(Figure2[i].GetX()))) {
                            isInside = false;
                            break;
                        }
                    }
                    else if (First.GetB() == 0 and Second.GetB() != 0) {
                        if (!(Figure2[i].GetY() < Second.GetYbyX(Figure2[i].GetX()))) {
                            isInside = false;
                            break;
                        }
                    }
                    else if (First.GetB() != 0 and Second.GetB() == 0) {
                        if (!(First.GetYbyX(Figure2[i].GetX()) < Figure2[i].GetY())) {
                            isInside = false;
                            break;
                        }
                    }
                }
                else {
                    isInside = false;
                    break;
                }
            }
        }
        if (isInside == true) {
            insidePoints.push_back(Figure2[i]);
        }
    }
    AllPoints.SetCoordinatesIntersection(insidePoints);
}

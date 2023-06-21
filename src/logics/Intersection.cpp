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

    if (convexHullPoints.size()!=points.size()){
        throw std::invalid_argument("Is not a convex figure");
    }
    return convexHullPoints;
}

bool IsInsideFigure(Point point, Intersection Figure1) {
    std::vector<Point> figure = Figure1.GetCoordinatesIntersection();
    int numVertices = figure.size();
    int i, j;
    bool isInside = false;
    for (i = 0, j = numVertices - 1; i < numVertices; j = i++) {
        if (((figure[i].GetY() > point.GetY()) != (figure[j].GetY() > point.GetY())) &&
            (point.GetX() < (figure[j].GetX() - figure[i].GetX()) * (point.GetY() - figure[i].GetY()) /
                       (figure[j].GetY() - figure[i].GetY()) + figure[i].GetX()))
            isInside = !isInside;
    }
    return isInside;
}

bool IsVertex(Point Point, Intersection Figure){
    bool isVertex = false;
    int size=Figure.GetSize();
    for (int i=0;i<size;i++){
        if (Point.GetY()==Figure.GetCoordinatesIntersection()[i].GetY() and Point.GetX()==Figure.GetCoordinatesIntersection()[i].GetX()){
            isVertex=!isVertex;
            break;
        }
    }
    return isVertex;
}

void FindPointsInsideFigure(Intersection& AllPoints, Intersection Figure1, Intersection Figure2){
    int size1 = Figure1.GetSize();
    int size2 = Figure2.GetSize();
    for (int i=0;i<size1;i++){
        if (IsInsideFigure(Figure1.GetCoordinatesIntersection()[i],Figure2) and !IsVertex(Figure1.GetCoordinatesIntersection()[i],Figure2)){
            AllPoints.SetIntersectionPoint(Figure1.GetCoordinatesIntersection()[i]);
        }
    }
    for (int j=0;j<size2;j++){
        if (IsInsideFigure(Figure2.GetCoordinatesIntersection()[j],Figure1) and !IsVertex(Figure2.GetCoordinatesIntersection()[j],Figure1)){
            AllPoints.SetIntersectionPoint(Figure2.GetCoordinatesIntersection()[j]);
        }
    }
}

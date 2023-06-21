
#include <cstdio>
#include "logics/Line.h"
#include <GL/glut.h>

// Global variables for correct work RenderScene function.
std::vector<Point> FiguresCoordinates;
std::vector<Point> IntersectionCoordinates;
int size_1;

void ResizeCoordinates(int argc, char* argv[])
{
    //All coordinates in OpenGl must be between -1 and 1 for the visualisation to be correct.
    //Therefore, we change the coordinates.
    int Max = 0;
    bool Flaq = false;
    for (int i = 0; i < FiguresCoordinates.size(); i++) {
        if (abs(FiguresCoordinates[i].GetX()) > Max)
            Max = abs(FiguresCoordinates[i].GetX());
        if (abs(FiguresCoordinates[i].GetY()) > Max)
            Max = abs(FiguresCoordinates[i].GetY());
        if (abs(FiguresCoordinates[i].GetX()) > 1 or abs(FiguresCoordinates[i].GetY()) > 1)
            Flaq = true;
    }
    if (Flaq) {
        int Counter = 0;
        int Num = Max;
        while (Num != 0) {
            Num /= 10;
            Counter += 1;
        }
        int div = pow(10, Counter);
        for (int i = 0; i < FiguresCoordinates.size(); i++)
            FiguresCoordinates[i] = Point(FiguresCoordinates[i].GetX() / div, FiguresCoordinates[i].GetY() / div);

        for (int i = 0; i < IntersectionCoordinates.size(); i++)
            IntersectionCoordinates[i] = Point(IntersectionCoordinates[i].GetX() / div, IntersectionCoordinates[i].GetY() / div);
    }


}
void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLineWidth(2.0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < size_1; i++)
        glVertex2f(FiguresCoordinates[i].GetX(), FiguresCoordinates[i].GetY());
    glEnd();

    glLineWidth(2.0);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for (int i = size_1; i < FiguresCoordinates.size(); i++)
        glVertex2f(FiguresCoordinates[i].GetX(), FiguresCoordinates[i].GetY());
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 1.0);
    for (int i = 0; i < IntersectionCoordinates.size(); i++)
    {
        glVertex2f(IntersectionCoordinates[i].GetX(), IntersectionCoordinates[i].GetY());
    }
    glEnd();
    glFlush();

}


int main(int argc, char* argv[]) {

    double x, y;
    //find intersection
    int size1;
    std::cout << "Input Size First Figure" << std::endl;
    std::cin >> size1;
    std::vector<Point> PointsFirstFigure;
    for (int i = 0; i < size1; i++) {
        std::cout << "Input " << i + 1 << " Point" << std::endl;
        std::cin >> x >> y;
        Point SomePoint(x, y);
        PointsFirstFigure.push_back(SomePoint);
        FiguresCoordinates.push_back(SomePoint);
    }
    Intersection FirstFigure(size1, PointsFirstFigure);
    if (size1 > 3) {
        std::vector<Point> convexHullPoints = ConvexHull(PointsFirstFigure);
        FirstFigure.SetCoordinatesIntersection(convexHullPoints);
        FirstFigure.SetSize(convexHullPoints.size());
    }
    FirstFigure.PrintIntersectionPoints();
    for (int i = 0; i < FirstFigure.GetSize(); i++) {
        IntersectionCoordinates.push_back(FirstFigure.GetCoordinatesIntersection()[i]);
    }
    size_1 = FirstFigure.GetSize();

    int size2;
    std::cout << "Input Size Second Figure" << std::endl;
    std::cin >> size2;
    std::vector<Point> PointsSecondFigure;
    for (int i = 0; i < size2; i++) {
        std::cout << "Input " << i + 1 << " Point" << std::endl;
        std::cin >> x >> y;
        Point SomePoint(x, y);
        PointsSecondFigure.push_back(SomePoint);
        FiguresCoordinates.push_back(SomePoint);
    }
    Intersection SecondFigure(size2, PointsSecondFigure);
    if (size2 > 3) {
        std::vector<Point> convexHullPoints2 = ConvexHull(PointsSecondFigure);
        SecondFigure.SetCoordinatesIntersection(convexHullPoints2);
        SecondFigure.SetSize(convexHullPoints2.size());
    }
    SecondFigure.PrintIntersectionPoints();
    for (int i = 0; i < SecondFigure.GetSize(); i++) {
        IntersectionCoordinates.push_back(SecondFigure.GetCoordinatesIntersection()[i]);
    }

    std::vector<Point> FiguresIntersection;
    Intersection IntersectionFigure(0, FiguresIntersection);
    if (!FirstFigure.IsIdenticalIntersection(FirstFigure, SecondFigure)) {
        IntersectionFigure.FigureIntersectionContour(IntersectionFigure, FirstFigure, SecondFigure);
        FindPointsInsideFigure(IntersectionFigure, FirstFigure, SecondFigure);
        IntersectionFigure.SetSize(IntersectionFigure.GetCoordinatesIntersection().size());
        /*if (IntersectionFigure.GetSize() > 3) {
            std::vector<Point> Points = IntersectionFigure.GetCoordinatesIntersection();
            std::vector<Point> SortedPoints = ConvexHull(Points);
            IntersectionFigure.SetCoordinatesIntersection(SortedPoints);
        }*/   
    }
    else {
        std::cout << "Figures are Same";
    }
    IntersectionFigure.PrintIntersectionPoints();
    for (int i = 0; i < IntersectionFigure.GetSize(); i++) {
        IntersectionCoordinates.push_back(IntersectionFigure.GetCoordinatesIntersection()[i]);
    }
    glutInit(&argc, argv);
    glutCreateWindow("FiguresCrossing(OpenGL)");
    ResizeCoordinates(argc, argv);
    glutDisplayFunc(RenderScene);
    glutMainLoop();
    char end;
    std::cin>> end;
    return 0;
}

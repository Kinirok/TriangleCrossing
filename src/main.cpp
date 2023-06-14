#include "logics/Line.h"

//#include <GL/glut.h>

// Global variables for correct work RenderScene function.
std::vector<Point> TriangleCoordinates;
std::vector<Point> IntersectionCoordinates;

/*

void ResizeCoordinates(int argc, char* argv[])
{
    //All coordinates in OpenGl must be between -1 and 1 for the visualisation to be correct.
    //Therefore, we change the coordinates.
    int Max = 0;
    bool Flaq = false;
    for (int i = 0; i < TriangleCoordinates.size(); i++)
    {
        if (abs(TriangleCoordinates[i].GetX()) > Max)
            Max = abs(TriangleCoordinates[i].GetX());
        if (abs(TriangleCoordinates[i].GetY()) > Max)
            Max = abs(TriangleCoordinates[i].GetY());
        if (abs(TriangleCoordinates[i].GetX()) or abs(TriangleCoordinates[i].GetY()))
            Flaq = true;
    }
    if (Flaq)
    {
        int Counter = 0;
        int Num = Max;
        while (Num != 0)
        {
            Num /= 10;
            Counter += 1;
        }
        for (int i = 0; i < TriangleCoordinates.size(); i++)
            TriangleCoordinates[i] = Point(TriangleCoordinates[i].GetX() / pow(10, Counter), TriangleCoordinates[i].GetY() / pow(10, Counter));

        for (int i = 0; i < IntersectionCoordinates.size(); i++)
            IntersectionCoordinates[i] = Point(IntersectionCoordinates[i].GetX() / pow(10, Counter), IntersectionCoordinates[i].GetY() / pow(10, Counter));
    }


}
void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLineWidth(2.0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 3; i++)
        glVertex2f(TriangleCoordinates[i].GetX(), TriangleCoordinates[i].GetY());
    glEnd();

    glLineWidth(2.0);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 3; i < TriangleCoordinates.size(); i++)
        glVertex2f(TriangleCoordinates[i].GetX(), TriangleCoordinates[i].GetY());
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3f(0, 0, 1);
    for (int i = 0; i < IntersectionCoordinates.size(); i++)
    {
        glVertex2f(IntersectionCoordinates[i].GetX(), IntersectionCoordinates[i].GetY());
    }
    glEnd();
    glFlush();
}

*/

int main(int argc, char* argv[]) {

    int x, y;
    //find intersection
    int size1;
    std::cout << "Input Size First Figure" << std::endl;
    std::cin >> size1;
    std::vector<Point> PointsFirstFigure;
    for (int i=0;i<size1;i++){
        std::cout << "Input " <<i+1<< " Point" << std::endl;
        std::cin >> x >> y;
        Point SomePoint(x,y);
        PointsFirstFigure.push_back(SomePoint);
    }
    Intersection FirstFigure(size1,PointsFirstFigure);
    if (size1>3){
        std::vector<Point> convexHullPoints = ConvexHull(PointsFirstFigure);
        FirstFigure.SetCoordinatesIntersection(convexHullPoints);
        FirstFigure.SetSize(convexHullPoints.size());
    }
    FirstFigure.PrintIntersectionPoints();

    int size2;
    std::cout << "Input Size Second Figure" << std::endl;
    std::cin >> size2;
    std::vector<Point> PointsSecondFigure;
    for (int i=0;i<size2;i++){
        std::cout << "Input " <<i+1<< " Point" << std::endl;
        std::cin >> x >> y;
        Point SomePoint(x,y);
        PointsSecondFigure.push_back(SomePoint);
    }
    Intersection SecondFigure(size2,PointsSecondFigure);
    if (size2>3){
        std::vector<Point> convexHullPoints2 = ConvexHull(PointsSecondFigure);
        SecondFigure.SetCoordinatesIntersection(convexHullPoints2);
        SecondFigure.SetSize(convexHullPoints2.size());
    }
    SecondFigure.PrintIntersectionPoints();

    std::vector<Point> FiguresIntersection;
    Intersection IntersectionFigure(0,FiguresIntersection);
    if (!FirstFigure.IsIdenticalIntersection(FirstFigure, SecondFigure)) {
        IntersectionFigure.FigureIntersectionContour(IntersectionFigure, FirstFigure, SecondFigure);
        IntersectionFigure.SetSize(IntersectionFigure.GetCoordinatesIntersection().size());
        if (IntersectionFigure.GetSize()>3){
            std::vector<Point> Points=IntersectionFigure.GetCoordinatesIntersection();
            std::vector<Point> SortedPoints=ConvexHull(Points);
            IntersectionFigure.SetCoordinatesIntersection(SortedPoints);
        }
    }
    else {
        std::cout << "Triangle are Same";
    }
    IntersectionFigure.PrintIntersectionPoints();




    /*
    glutInit(&argc, argv);
    glutCreateWindow("TriangleCrossing(OpenGL)");
    ResizeCoordinates(argc, argv);
    glutDisplayFunc(RenderScene);
    glutMainLoop();
    */
    return 0;
}

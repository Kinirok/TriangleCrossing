#include "logics/Line.h"
#include <iostream>
#include <vector>
#include <GL/glut.h>

void ResizeCoordinates(int argc, char* argv[])
{
    //All coordinates in OpenGl must be between -1 and 1 for the visualisation to be correct.
    //Therefore, we change the coordinates.
    double Max = 0.0;
    bool Flaq = false;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (abs(Coordinates[i][j]) > Max)
                Max = abs(Coordinates[i][j]);
            if (abs(Coordinates[i][j]) > 1)
                Flaq = true;
        }
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
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 2; j++)
                Coordinates[i][j] = Coordinates[i][j] / pow(10, Counter);
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
    glVertex2f(Coordinates[0][0], Coordinates[0][1]);
    glVertex2f(Coordinates[1][0], Coordinates[1][1]);
    glVertex2f(Coordinates[2][0], Coordinates[2][1]);
    glEnd();

    glLineWidth(2.0);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(Coordinates[3][0], Coordinates[3][1]);
    glVertex2f(Coordinates[4][0], Coordinates[4][1]);
    glVertex2f(Coordinates[5][0], Coordinates[5][1]);
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
int main(int argc, char* argv[]) {

    /*
    //point use example
    Point A(0, 1);
    Point B(1, 3);
    Point C(3.4, 6);
    Point D(0, 0);
    Point E(1, 1);
    Point F(1.5, 1.5);
    //A.PrintPoint();
    //double x2 = B.GetX();
    //std::cout << x2<<std::endl;
    //double distance = A.DistanceTo(B);
    //std::cout << distance << std::endl;



    //Triangle use example
    Triangle Figure1(A, B, C);
    //Figure1.PrintTriangle();
    Triangle Figure2(B, A, C);
    Triangle Figure3(A, B, D);
    /*
    if (Figure1.IsIdenticalTriangles(Figure1, Figure2)) {
        Figure1.PrintTriangle();
        Figure2.PrintTriangle();
        std::cout << "Same"<<std::endl;
    }
    if (!Figure1.IsIdenticalTriangles(Figure1, Figure3)) {
        Figure1.PrintTriangle();
        Figure3.PrintTriangle();
        std::cout << "Not Same"<<std::endl;
    }

    Triangle Figure4(D, E,F);
    /*
    if (Figure4.IsTriangle()) {
        std::cout << "Triangle";
    }
    else {
        std::cout << "Not Triangle";
    }
    */


    //find intersection
    Intersection IntersectionTriangle;

    int x, y;
    std::cout << "Input First Point"<<std::endl;
    std::cin >> x >> y;
    Coordinates[0][0] = x;
    Coordinates[0][1] = y;
    Point TriangleFirstPointFirst(x, y);
    std::cout << "Input Second Point" << std::endl;
    std::cin >> x >> y;
    Coordinates[1][0] = x;
    Coordinates[1][1] = y;
    Point TriangleFirstPointSecond(x, y);
    std::cout << "Input Third Point" << std::endl;
    std::cin >> x >> y;
    Coordinates[2][0] = x;
    Coordinates[2][1] = y;
    Point TriangleFirstPointThird(x, y);

    Triangle FirstTriangle(TriangleFirstPointFirst, TriangleFirstPointSecond, TriangleFirstPointThird);
    if (!FirstTriangle.IsTriangle()){
        std::cout << "Not A Triangle";
        return 1;
    }

    std::cout << "Input First Point" << std::endl;
    std::cin >> x >> y;
    Coordinates[3][0] = x;
    Coordinates[3][1] = y;
    Point TriangleSecondPointFirst(x, y);
    std::cout << "Input Second Point" << std::endl;
    std::cin >> x >> y;
    Coordinates[4][0] = x;
    Coordinates[4][1] = y;
    Point TriangleSecondPointSecond(x, y);
    std::cout << "Input Third Point" << std::endl;
    std::cin >> x >> y;
    Coordinates[5][0] = x;
    Coordinates[5][1] = y;
    Point TriangleSecondPointThird(x, y);

    Triangle SecondTriangle(TriangleSecondPointFirst, TriangleSecondPointSecond, TriangleSecondPointThird);
    if (!SecondTriangle.IsTriangle()) {
        std::cout << "Not A Triangle";
        return 1;
    }


    FirstTriangle.PrintTriangle();
    SecondTriangle.PrintTriangle();

    if (!FirstTriangle.IsIdenticalTriangles(FirstTriangle, SecondTriangle)) {
        IntersectionTriangle.TriangleIntersectionContour(IntersectionTriangle, FirstTriangle, SecondTriangle);
        IntersectionTriangle.PrintIntersectionPoints();
    }
    else {
        std::cout << "Triangle are Same";
    }
    IntersectionCoordinates = IntersectionTriangle.GetCoordinatesIntersection();

    glutInit(&argc, argv);
    glutCreateWindow("TriangleCrossing(OpenGL)");
    ResizeCoordinates();
    glutDisplayFunc(RenderScene);
    glutMainLoop();
    return 0;
}
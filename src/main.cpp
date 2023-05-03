#include "logics/Line.h"


int main() {

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
    Point TriangleFirstPointFirst(x, y);
    std::cout << "Input Second Point" << std::endl;
    std::cin >> x >> y;
    Point TriangleFirstPointSecond(x, y);
    std::cout << "Input Third Point" << std::endl;
    std::cin >> x >> y;
    Point TriangleFirstPointThird(x, y);

    Triangle FirstTriangle(TriangleFirstPointFirst, TriangleFirstPointSecond, TriangleFirstPointThird);
    if (!FirstTriangle.IsTriangle()){
        std::cout << "Not A Triangle";
        return 1;
    }

    std::cout << "Input First Point" << std::endl;
    std::cin >> x >> y;
    Point TriangleSecondPointFirst(x, y);
    std::cout << "Input Second Point" << std::endl;
    std::cin >> x >> y;
    Point TriangleSecondPointSecond(x, y);
    std::cout << "Input Third Point" << std::endl;
    std::cin >> x >> y;
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
    return 0;
}
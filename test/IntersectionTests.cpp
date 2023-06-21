#include <gtest/gtest.h>
#include "../src/logics/Intersection.h"

class IntersectionFixture : public ::testing::Test {

protected:
    virtual void SetUp() {
    }

    std::vector<Point> points1 = {Point(0, 0), Point(0, 1), Point(1, 0)};
    std::vector<Point> points2 = {Point(0, 1), Point(1, 0), Point(1, 1)};
    std::vector<Point> points3 = {Point(1, 0), Point(1, -1), Point(2, -1)};
    std::vector<Point> points4 = {Point(1, 1), Point(1, 2), Point(2, 1)};
    std::vector<Point> points5 = {Point(2, 2), Point(3, 4), Point(4, 2)};
    std::vector<Point> points6 = {Point(2, 3), Point(4, 3), Point(3, 1)};
    std::vector<Point> points7 = {Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1)};
    std::vector<Point> points8 = {Point(2, 4), Point(2, 2), Point(4, 2), Point(4, 4), Point(4, 4)};
    std::vector<Point> points9 = {Point(1, 3), Point(3, 5), Point(5, 3)};
    std::vector<Point> points10 = {Point(1, 3), Point(3, 5), Point(5, 3), Point(2, 1), Point(4, 1)};
    std::vector<Point> points11 = {Point(1, 1),Point(5, 1),Point(6, 3),Point(4, 6), Point(2, 6), Point(0, 3), };
    std::vector<Point> points12 = {Point(4, 2), Point(8, 2), Point(8, 4), Point(6, 6)};
    std::vector<Point> points13 = {Point(6, 4), Point(10, 6), Point(10, 8)};
    Intersection tr1 = Intersection(3, points1);
    Intersection tr2 = Intersection(3, points2);
    Intersection tr3 = Intersection(3, points3);
    Intersection tr4 = Intersection(3, points4);
    Intersection tr5 = Intersection(3, points5);
    Intersection tr6 = Intersection(3, points6);
    Intersection square1 = Intersection(4, points7);
    Intersection square2 = Intersection(4, points8);
    Intersection tr7 = Intersection(3, points9);
    Intersection fig1 = Intersection(5, points10);
    Intersection fig2 = Intersection(6, points11);
    Intersection fig3 = Intersection(4, points12);
    Intersection tr8 = Intersection(3, points13);
};


TEST_F(IntersectionFixture, Unequality) {
    EXPECT_FALSE(tr1.IsIdenticalIntersection(tr1, tr2));
}

TEST_F(IntersectionFixture, Equality) {
    EXPECT_TRUE(tr1.IsIdenticalIntersection(tr1, tr1));
}

TEST_F(IntersectionFixture, SameDim3_TwoPointIntersection) {
    std::vector<Point> FiguresIntersection;
    Intersection IntersectionFigure(0, FiguresIntersection);
    IntersectionFigure.FigureIntersectionContour(IntersectionFigure, tr1, tr2);
    FindPointsInsideFigure(IntersectionFigure, tr1,tr2);
    IntersectionFigure.SetSize(IntersectionFigure.GetCoordinatesIntersection().size());
    EXPECT_EQ(IntersectionFigure.GetSize(), 2);
}

TEST_F(IntersectionFixture, SameDim3_OnePointIntersection) {
    std::vector<Point> FiguresIntersection;
    Intersection IntersectionFigure(0, FiguresIntersection);
    IntersectionFigure.FigureIntersectionContour(IntersectionFigure, tr2, tr3);
    FindPointsInsideFigure(IntersectionFigure, tr2,tr3);
    IntersectionFigure.SetSize(IntersectionFigure.GetCoordinatesIntersection().size());
    EXPECT_EQ(IntersectionFigure.GetSize(), 1);
}

TEST_F(IntersectionFixture, SameDim3_NoPointIntersection) {
    std::vector<Point> FiguresIntersection;
    Intersection IntersectionFigure(0, FiguresIntersection);
    IntersectionFigure.FigureIntersectionContour(IntersectionFigure, tr3, tr4);
    FindPointsInsideFigure(IntersectionFigure, tr3,tr4);
    IntersectionFigure.SetSize(IntersectionFigure.GetCoordinatesIntersection().size());
    EXPECT_EQ(IntersectionFigure.GetSize(), 0);
}

TEST_F(IntersectionFixture, SameDim3_SixPointIntersection) {
    std::vector<Point> FiguresIntersection;
    Intersection IntersectionFigure(0, FiguresIntersection);
    IntersectionFigure.FigureIntersectionContour(IntersectionFigure, tr5, tr6);
    FindPointsInsideFigure(IntersectionFigure, tr5,tr6);
    IntersectionFigure.SetSize(IntersectionFigure.GetCoordinatesIntersection().size());
    EXPECT_EQ(IntersectionFigure.GetSize(), 6);
}

TEST_F(IntersectionFixture, SameDim4_FourPointIntersection) {
    std::vector<Point> FiguresIntersection;
    Intersection IntersectionFigure(0, FiguresIntersection);
    IntersectionFigure.FigureIntersectionContour(IntersectionFigure, square1, square2);
    FindPointsInsideFigure(IntersectionFigure, square1,square2);
    IntersectionFigure.SetSize(IntersectionFigure.GetCoordinatesIntersection().size());
    EXPECT_EQ(IntersectionFigure.GetSize(), 4);
}

TEST_F(IntersectionFixture, DiffDim_OnePointIntersection) {
    std::vector<Point> FiguresIntersection;
    Intersection IntersectionFigure(0, FiguresIntersection);
    IntersectionFigure.FigureIntersectionContour(IntersectionFigure, square1, tr2);
    FindPointsInsideFigure(IntersectionFigure, square1,tr2);
    IntersectionFigure.SetSize(IntersectionFigure.GetCoordinatesIntersection().size());
    EXPECT_EQ(IntersectionFigure.GetSize(), 1);
}

TEST_F(IntersectionFixture, DiffDim_ThreePointIntersection) {
    std::vector<Point> FiguresIntersection;
    Intersection IntersectionFigure(0, FiguresIntersection);
    IntersectionFigure.FigureIntersectionContour(IntersectionFigure, tr7, fig1);
    FindPointsInsideFigure(IntersectionFigure, tr7,fig1);
    IntersectionFigure.SetSize(IntersectionFigure.GetCoordinatesIntersection().size());
    EXPECT_EQ(IntersectionFigure.GetSize(), 3);
}

TEST_F(IntersectionFixture, DiffDimInnerFigure_ThreePointIntersection) {
    std::vector<Point> FiguresIntersection;
    Intersection IntersectionFigure(0, FiguresIntersection);
    IntersectionFigure.FigureIntersectionContour(IntersectionFigure, tr7, fig2);
    FindPointsInsideFigure(IntersectionFigure, tr7, fig2);
    IntersectionFigure.SetSize(IntersectionFigure.GetCoordinatesIntersection().size());
    EXPECT_EQ(IntersectionFigure.GetSize(), 3);
}

TEST_F(IntersectionFixture, DiffDim2_ThreePointIntersection) {
    std::vector<Point> FiguresIntersection;
    Intersection IntersectionFigure(0, FiguresIntersection);
    IntersectionFigure.FigureIntersectionContour(IntersectionFigure, tr8, fig3);
    FindPointsInsideFigure(IntersectionFigure, tr8, fig3);
    IntersectionFigure.SetSize(IntersectionFigure.GetCoordinatesIntersection().size());
    EXPECT_EQ(IntersectionFigure.GetSize(), 3);
}


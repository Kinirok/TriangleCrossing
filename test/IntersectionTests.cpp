#include <gtest/gtest.h>
#include "../src/logics/Intersection.h"
class IntersectionFixture : public ::testing::Test {

protected:
    virtual void SetUp() {

    }
    Triangle tr0 = Triangle(Point(1,1),Point(2,2),Point(3,1));
    Triangle tr1 = Triangle(Point(1,3),Point(2,2),Point(3,3));
    Triangle tr2 = Triangle(Point(1,4),Point(2,3),Point(3,4));
    Triangle tr3 = Triangle(Point(1,2),Point(2,1),Point(3,2));
    Triangle tr4 = Triangle(Point(1,2),Point(2,3),Point(3,2));
    Triangle tr5 = Triangle(Point(1,3),Point(2,1),Point(3,3));
    Triangle tr6 = Triangle(Point(0,4),Point(2.5,2),Point(3,3));
    Triangle tr7 = Triangle(Point(1,5),Point(3,1),Point(5,5));
    Triangle tr8 = Triangle(Point(0,4),Point(3,3),Point(6,4));
    Triangle tr9 = Triangle(Point(1,1),Point(1,5),Point(5,1));
    Triangle tr10 = Triangle(Point(2,2),Point(3,4),Point(4,2));
    Triangle tr11 = Triangle(Point(2,3),Point(4,3),Point(3,1));
    Triangle tr12 = Triangle(Point(0,3),Point(3,0),Point(3,3));
    Triangle tr13 = Triangle(Point(2,3),Point(3,6),Point(5,3));

};

TEST_F(IntersectionFixture, NoIntersectionPointsNoPoints){
    Intersection i0;
    i0.TriangleIntersectionContour(i0,tr0,tr2);
    EXPECT_EQ(0,i0.GetCoordinatesIntersection().size());
}
TEST_F(IntersectionFixture, OneIntersectionPointsOnePoint){
    Intersection i0;
    i0.TriangleIntersectionContour(i0,tr0,tr1);
    EXPECT_EQ(1,i0.GetCoordinatesIntersection().size());
    EXPECT_EQ(2,i0.GetCoordinatesIntersection()[0].GetX());
    EXPECT_EQ(2,i0.GetCoordinatesIntersection()[0].GetY());
}

TEST_F(IntersectionFixture,TwoIntersectionPointsTwoPoints){
    Intersection i0;
    i0.TriangleIntersectionContour(i0,tr3,tr4);
    EXPECT_EQ(2,i0.GetCoordinatesIntersection().size());
    EXPECT_EQ(1,i0.GetCoordinatesIntersection()[0].GetX());
    EXPECT_EQ(2,i0.GetCoordinatesIntersection()[0].GetY());
    EXPECT_EQ(3,i0.GetCoordinatesIntersection()[1].GetX());
    EXPECT_EQ(2,i0.GetCoordinatesIntersection()[1].GetY());
}
TEST_F(IntersectionFixture,ThreeIntersectionPointsTwoPoints){
    Intersection i0;
    i0.TriangleIntersectionContour(i0,tr5,tr6);
    EXPECT_EQ(3,i0.GetCoordinatesIntersection().size());
    EXPECT_EQ(2.5,i0.GetCoordinatesIntersection()[0].GetX());
    EXPECT_EQ(2,i0.GetCoordinatesIntersection()[0].GetY());
    EXPECT_EQ(3,i0.GetCoordinatesIntersection()[1].GetX());
    EXPECT_EQ(3,i0.GetCoordinatesIntersection()[1].GetY());
    EXPECT_EQ(1.25,i0.GetCoordinatesIntersection()[2].GetX());
    EXPECT_EQ(3,i0.GetCoordinatesIntersection()[2].GetY());

}
TEST_F(IntersectionFixture,FourIntersectionPointsFourPoints){
    Intersection i0;
    i0.TriangleIntersectionContour(i0,tr7,tr8);
    EXPECT_EQ(4,i0.GetCoordinatesIntersection().size());
    EXPECT_EQ(1.8,i0.GetCoordinatesIntersection()[0].GetX());
    EXPECT_EQ(3.4,i0.GetCoordinatesIntersection()[0].GetY());
    EXPECT_EQ(1.5,i0.GetCoordinatesIntersection()[1].GetX());
    EXPECT_EQ(4,i0.GetCoordinatesIntersection()[1].GetY());
    EXPECT_EQ(4.2,i0.GetCoordinatesIntersection()[2].GetX());
    EXPECT_EQ(3.4,i0.GetCoordinatesIntersection()[2].GetY());
    EXPECT_EQ(4.5,i0.GetCoordinatesIntersection()[3].GetX());
    EXPECT_EQ(4,i0.GetCoordinatesIntersection()[3].GetY());
}
TEST_F(IntersectionFixture,FiveIntersectionPointsFirstFivePoints){
    Intersection i0;
    i0.TriangleIntersectionContour(i0,tr12,tr9);
    EXPECT_EQ(5,i0.GetCoordinatesIntersection().size());
    EXPECT_EQ(1,i0.GetCoordinatesIntersection()[0].GetX());
    EXPECT_EQ(2,i0.GetCoordinatesIntersection()[0].GetY());
    EXPECT_EQ(2,i0.GetCoordinatesIntersection()[1].GetX());
    EXPECT_EQ(1,i0.GetCoordinatesIntersection()[1].GetY());
    EXPECT_EQ(3,i0.GetCoordinatesIntersection()[2].GetX());
    EXPECT_EQ(3,i0.GetCoordinatesIntersection()[2].GetY());
    EXPECT_EQ(3,i0.GetCoordinatesIntersection()[3].GetX());
    EXPECT_EQ(1,i0.GetCoordinatesIntersection()[3].GetY());
    EXPECT_EQ(1,i0.GetCoordinatesIntersection()[4].GetX());
    EXPECT_EQ(3,i0.GetCoordinatesIntersection()[4].GetY());
}
TEST_F(IntersectionFixture,DISABLED_FiveIntersectionPointsSecondFivePoints){
    Intersection i0;
    i0.TriangleIntersectionContour(i0,tr7,tr13);
    EXPECT_EQ(5,i0.GetCoordinatesIntersection().size());

}
TEST_F(IntersectionFixture,SixIntersectionPointsSixPoints){
    Intersection i0;
    i0.TriangleIntersectionContour(i0,tr10,tr11);
    EXPECT_EQ(6,i0.GetCoordinatesIntersection().size());
    EXPECT_EQ(2.5,i0.GetCoordinatesIntersection()[0].GetX());
    EXPECT_EQ(3,i0.GetCoordinatesIntersection()[0].GetY());
    EXPECT_EQ(2.25,i0.GetCoordinatesIntersection()[1].GetX());
    EXPECT_EQ(2.5,i0.GetCoordinatesIntersection()[1].GetY());
    EXPECT_EQ(3.5,i0.GetCoordinatesIntersection()[2].GetX());
    EXPECT_EQ(3,i0.GetCoordinatesIntersection()[2].GetY());
    EXPECT_EQ(3.75,i0.GetCoordinatesIntersection()[3].GetX());
    EXPECT_EQ(2.5,i0.GetCoordinatesIntersection()[3].GetY());
    EXPECT_EQ(3.5,i0.GetCoordinatesIntersection()[4].GetX());
    EXPECT_EQ(2,i0.GetCoordinatesIntersection()[4].GetY());
    EXPECT_EQ(2.5,i0.GetCoordinatesIntersection()[5].GetX());
    EXPECT_EQ(2,i0.GetCoordinatesIntersection()[5].GetY());
}
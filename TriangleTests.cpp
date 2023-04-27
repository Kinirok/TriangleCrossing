#include <gtest/gtest.h>
#include "Triangle.h"

class TriangleFixture : public ::testing::Test {

protected:
    virtual void SetUp() {
        tr0=Triangle();
        tr1=Triangle(Point(1,1),Point(2,2),Point(3,1));
        tr2=Triangle();
    }
    Triangle tr0;
    Triangle tr1;
    Triangle tr2;
    };

TEST_F(TriangleFixture, DefaultConstructorGetEmptyTriangle) {
    EXPECT_EQ(0,tr0.GetCoordinatesTriangle()[0].GetX());
    EXPECT_EQ(0,tr0.GetCoordinatesTriangle()[0].GetY());
    EXPECT_EQ(0,tr0.GetCoordinatesTriangle()[1].GetX());
    EXPECT_EQ(0,tr0.GetCoordinatesTriangle()[1].GetY());
    EXPECT_EQ(0,tr0.GetCoordinatesTriangle()[2].GetX());
    EXPECT_EQ(0,tr0.GetCoordinatesTriangle()[2].GetY());
}
TEST_F(TriangleFixture, ConstructorGetTrianglePoints) {
    EXPECT_EQ(1,tr1.GetCoordinatesTriangle()[0].GetX());
    EXPECT_EQ(1,tr1.GetCoordinatesTriangle()[0].GetY());
    EXPECT_EQ(2,tr1.GetCoordinatesTriangle()[1].GetX());
    EXPECT_EQ(2,tr1.GetCoordinatesTriangle()[1].GetY());
    EXPECT_EQ(3,tr1.GetCoordinatesTriangle()[2].GetX());
    EXPECT_EQ(1,tr1.GetCoordinatesTriangle()[2].GetY());
}
TEST_F(TriangleFixture, EqualTrianglesTrue){
    EXPECT_EQ(true,tr0.IsIdenticalTriangles(tr0,tr2));
}
TEST_F(TriangleFixture, NotEqualTrianglesTrue){
    EXPECT_NE(true,tr1.IsIdenticalTriangles(tr1,tr2));
}
TEST_F(TriangleFixture,IsTriangleTrue){
    EXPECT_EQ(true,tr1.IsTriangle());
}
TEST_F(TriangleFixture,IsTriangleFalse){
    EXPECT_EQ(false,tr0.IsTriangle());
}
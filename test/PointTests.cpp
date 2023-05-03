#include <gtest/gtest.h>
#include "../src/logics/Point.h"
class PointFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        p0 = Point();
        p1 = Point(10, 12);
        p2 = Point(4, 4);
    }

    Point p0;
    Point p1;
    Point p2;
};

TEST_F(PointFixture, DefaultConstructorEmptyPoint) {
    EXPECT_EQ(0, p0.GetX());
    EXPECT_EQ(0, p0.GetY());
}

TEST_F(PointFixture, ConstructorXY) {
    EXPECT_EQ(10, p1.GetX());
    EXPECT_EQ(12, p1.GetY());
}

TEST_F(PointFixture, CalculateDistanceDistance) {
    EXPECT_EQ(10.0, p1.DistanceTo(p2));
}
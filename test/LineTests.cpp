#include <gtest/gtest.h>
#include "../src/logics/Line.h"

class LineFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
    }
};


TEST(LineFixture, GetA) {
    Line L1 = Line(Point(1, 1), Point(2, 2));
    EXPECT_EQ(L1.GetA(), 1 - 2);
}

TEST(LineFixture, GetB) {
    Line L2 = Line(Point(1, 2), Point(2, 1));
    EXPECT_EQ(L2.GetB(), 2 - 1);
}

TEST(LineFixture, GetC) {
    Line L3 = Line(Point(0, -2.5), Point(2, 3));
    EXPECT_EQ(L3.GetC(), 0 * 3 - (-2.5) * 2);
}

TEST(LineFixture, GetXbyY) {
    Line L3 = Line(Point(0, -2.5), Point(2, 3));
    EXPECT_EQ(L3.GetXbyY(3), 2);
}

TEST(LineFixture, GetYbyX) {
    Line L3 = Line(Point(0, -2.5), Point(2, 3));
    EXPECT_EQ(L3.GetYbyX(3), 5.75);
}

#include "patch.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

const int WIDTH = 20;
const int HEIGHT = 20;

TEST(BoundaryCalculatorTest, NoSharedBoundary) {
    BoundaryCalculator underTest(WIDTH, HEIGHT);
    Patch patch1(Point(1, 1), 3);
    Patch patch2(Point(5, 5), 3);

    underTest.AddPatch(patch1);
    underTest.AddPatch(patch2);
    std::vector<Point> boundaryPoints = underTest.GetBoundaryPoints();
    EXPECT_EQ(0, boundaryPoints.size());
}

TEST(BoundaryCalculatorTest, SideBySideSameSize) {
    BoundaryCalculator underTest(WIDTH, HEIGHT);
    Patch patch1(Point(1, 1), 3);
    Patch patch2(Point(3, 1), 3);

    underTest.AddPatch(patch1);
    underTest.AddPatch(patch2);
    std::vector<Point> boundaryPoints = underTest.GetBoundaryPoints();
    EXPECT_EQ(3, boundaryPoints.size());
    EXPECT_THAT(boundaryPoints, ::testing::Contains(Point(2, 2)));
    EXPECT_THAT(boundaryPoints, ::testing::Contains(Point(2, 1)));
    EXPECT_THAT(boundaryPoints, ::testing::Contains(Point(2, 0)));
}

TEST(BoundaryCalculatorTest, VerticalOffset) {
    BoundaryCalculator underTest(WIDTH, HEIGHT);
    Patch patch1(Point(1, 1), 3);
    Patch patch2(Point(3, 2), 3);

    underTest.AddPatch(patch1);
    underTest.AddPatch(patch2);
    std::vector<Point> boundaryPoints = underTest.GetBoundaryPoints();
    EXPECT_EQ(2, boundaryPoints.size());
    EXPECT_THAT(boundaryPoints, ::testing::Contains(Point(2, 2)));
    EXPECT_THAT(boundaryPoints, ::testing::Contains(Point(2, 1)));
}

TEST(BoundaryCalculatorTest, VerticalAndHorizontalOffset) {
    BoundaryCalculator underTest(WIDTH, HEIGHT);
    Patch patch1(Point(1, 1), 3);
    Patch patch2(Point(2, 2), 3);

    underTest.AddPatch(patch1);
    underTest.AddPatch(patch2);
    std::vector<Point> boundaryPoints = underTest.GetBoundaryPoints();
    EXPECT_EQ(3, boundaryPoints.size());
    EXPECT_THAT(boundaryPoints, ::testing::Contains(Point(2, 2)));
    EXPECT_THAT(boundaryPoints, ::testing::Contains(Point(2, 1)));
    EXPECT_THAT(boundaryPoints, ::testing::Contains(Point(1, 2)));
}

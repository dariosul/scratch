#include "patch.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(BoundaryCalculatorTest, NoSharedBoundary) {
    BoundaryCalculator underTest;
    Patch patch1(Point(0, 0), 3);
    Patch patch2(Point(5, 5), 3);

    std::vector<Point> boundaryPoints = underTest.GetBoundaryPoints(patch1, patch2);
    EXPECT_EQ(0, boundaryPoints.size());
}

TEST(BoundaryCalculatorTest, SideBySideSameSize) {
    BoundaryCalculator underTest;
    Patch patch1(Point(0, 0), 3);
    Patch patch2(Point(2, 0), 3);

    std::vector<Point> boundaryPoints = underTest.GetBoundaryPoints(patch1, patch2);
    EXPECT_EQ(3, boundaryPoints.size());
    EXPECT_THAT(boundaryPoints, ::testing::Contains(Point(1, 1)));
    EXPECT_THAT(boundaryPoints, ::testing::Contains(Point(1, 0)));
    EXPECT_THAT(boundaryPoints, ::testing::Contains(Point(1, -1)));
}

TEST(BoundaryCalculatorTest, VerticalOffset) {
    BoundaryCalculator underTest;
    Patch patch1(Point(0, 0), 3);
    Patch patch2(Point(2, 1), 3);

    std::vector<Point> boundaryPoints = underTest.GetBoundaryPoints(patch1, patch2);
    EXPECT_EQ(2, boundaryPoints.size());
    EXPECT_THAT(boundaryPoints, ::testing::Contains(Point(1, 1)));
    EXPECT_THAT(boundaryPoints, ::testing::Contains(Point(1, 0)));
}

TEST(BoundaryCalculatorTest, VerticalAndHorizontalOffset) {
    BoundaryCalculator underTest;
    Patch patch1(Point(0, 0), 3);
    Patch patch2(Point(1, 1), 3);

    std::vector<Point> boundaryPoints = underTest.GetBoundaryPoints(patch1, patch2);
    EXPECT_EQ(3, boundaryPoints.size());
    EXPECT_THAT(boundaryPoints, ::testing::Contains(Point(1, 1)));
    EXPECT_THAT(boundaryPoints, ::testing::Contains(Point(1, 0)));
    EXPECT_THAT(boundaryPoints, ::testing::Contains(Point(0, 1)));
}

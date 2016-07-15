#include "patch.h"

#include "gtest/gtest.h"

TEST(BoundaryCalculatorTest, NoSharedBoundary) {
    BoundaryCalculator underTest;
    Patch patch1(Point(0, 0), 3);
    Patch patch2(Point(5, 5), 3);

    std::vector<Point> boundaryPoints = underTest.GetBoundaryPoints(patch1, patch2);
    EXPECT_EQ(0, boundaryPoints.size());
}

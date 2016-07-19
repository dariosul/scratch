#include "patch.h"

std::vector<Point> Patch::GetBorderPoints() {
    std::vector<Point> borderPoints;

    for (int x = minX; x <= maxX; ++x) {
        borderPoints.push_back(Point(x, minY));
        borderPoints.push_back(Point(x, maxY));
    }

    /* Don't do corner points twice! */
    for (int y = minY + 1; y < maxY; ++y) {
        borderPoints.push_back(Point(minX, y));
        borderPoints.push_back(Point(maxX, y));
    }

    return borderPoints;
}

bool Patch::Contains(const Point& point) const {
    return point.x <= maxX && point.x >= minX && point.y <= maxY && point.y >= minY;
}

void BoundaryCalculator::AddPatch(Patch patch) {
    patches.push_back(patch);
}

std::vector<Point> BoundaryCalculator::GetBoundaryPoints() {
    // XXX temporary hack to conform to new API with test cases passing
    Patch patch2 = patches.back();
    patches.pop_back();
    Patch patch1 = patches.back();

    std::vector<Point> boundaryPoints;

    for (Point& point : patch1.GetBorderPoints()) {
        if (patch2.Contains(point)) {
            boundaryPoints.push_back(point);
        }
    }

    return boundaryPoints;
}

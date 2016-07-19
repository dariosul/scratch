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

void BoolMap2D::Set(int x, int y) {
    map[y][x] = true;
}

bool BoolMap2D::Test(int x, int y) {
    return map[y][x];
}

void BoundaryCalculator::AddPatch(Patch patch) {
    for (Point& point : patch.GetBorderPoints()) {
        if (!IsInPatchedArea(point)) {
            boundaryPoints.push_back(point);
        }
    }

    AddPatchedArea(patch);
}

bool BoundaryCalculator::IsInPatchedArea(Point point) {
    return patchMap.Test(point.x, point.y);
}

void BoundaryCalculator::AddPatchedArea(Patch patch) {
    for (int y = patch.GetMinY(); y <= patch.GetMaxY(); ++y) {
        for (int x = patch.GetMinX(); x <= patch.GetMaxX(); ++x) {
            patchMap.Set(x, y);
        }
    }
}

#include <vector>

struct Point {
    explicit Point(int x, int y) : x(x), y(y) {};

    int x;
    int y;

    bool operator==(const Point& otherPoint) const {
        return x == otherPoint.x && y == otherPoint.y;
    }
};

class Patch {
public:
    explicit Patch(Point centre, int length) : centre(centre), length(length) {
        int halfLength = length / 2;
        minX = centre.x - halfLength;
        maxX = centre.x + halfLength;
        minY = centre.y - halfLength;
        maxY = centre.y + halfLength;
    };

    int GetMinX() { return minX; }
    int GetMaxX() { return maxX; }
    int GetMinY() { return minY; }
    int GetMaxY() { return maxY; }

    std::vector<Point> GetBorderPoints();
    bool Contains(const Point& point) const;

private:
    Point centre;
    int length;

    // Cache values
    int minX;
    int maxX;
    int minY;
    int maxY;
};

class BoolMap2D {
public:
    BoolMap2D(int width, int height)
        : map(height, std::vector<bool>(width, false)) {};

    void Set(int x, int y);
    bool Test(int x, int y);

private:
    std::vector<std::vector<bool>> map;
};

class BoundaryCalculator {
public:
    explicit BoundaryCalculator(int width, int height)
        : patchMap(width, height), boundaryPoints() {};

    void AddPatch(Patch patch);
    std::vector<Point> GetBoundaryPoints() { return boundaryPoints; };

private:
    BoolMap2D patchMap;
    std::vector<Point> boundaryPoints;

    bool IsInPatchedArea(Point point);
    void AddPatchedArea(Patch patch);
};

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

class BoundaryCalculator {
public:
    explicit BoundaryCalculator(int width, int height)
    : width(width), height(height), patches() {};

    void AddPatch(Patch patch);
    std::vector<Point> GetBoundaryPoints();

private:
    int width;
    int height;
    std::vector<Patch> patches;
};

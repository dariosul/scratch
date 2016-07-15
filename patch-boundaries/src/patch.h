#include <vector>

struct Point {
    Point(int x, int y) : x(x), y(y) {};

    int x;
    int y;
};

class Patch {
public:
    Patch(Point centre, int length) : centre(centre), length(length) {};

private:
    Point centre;
    int length;
};

class BoundaryCalculator {
public:
    std::vector<Point> GetBoundaryPoints(Patch patch1, Patch patch2);
};

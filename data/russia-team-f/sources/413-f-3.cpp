#define _USE_MATH_DEFINES

#include <algorithm>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

ifstream in("polygon.in");
ofstream out("polygon.out");

typedef long double ld;

const ld EPS = 1e-9;

struct Point
{
    ld x, y;
    Point() {}
    Point(ld x, ld y): x(x), y(y) {}
    Point(Point const &P): x(P.x), y(P.y) {}

    void read()
    {
        in >> x >> y;
    }

    Point operator-(Point const &P) const
    {
        return Point(x - P.x, y - P.y);
    }

};

Point center, rad, delta;

ld dist(Point a, Point b)
{
    return (sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}

bool good(Point a, Point b, ld r)
{
    if (fabs(dist(center, a) - r) < EPS || fabs(dist(center, b) - r) < EPS)
        return true;
    if ((dist(center, a) > r && dist(center, b) < r) || (dist(center, a) < r && dist(center, b) > r))
        return true;
    return false;
}

struct Line
{
    ld a, b, c;
    void make2points(Point p, Point q)
    {
        Point vec = q - p;
        a = -vec.y;
        b = vec.x;
        c = p.x * vec.y - vec.x * p.y;
    }
};

bool in_line(Line line, Point a)
{
    return (line.a * a.x + line.b * a.y + line.c) < EPS;
}

bool equal(Point a, Point b)
{
    return (fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS);
}

bool in_otr(Point a, Point b, Point c)
{
    if (equal(a, c) || equal(b, c))
        return true;
    return (max(a.x, b.x) > c.x && min(a.x, b.x) < c.x && max(a.y, b.y) > c.y && min(a.y, b.y) < c.y);
}



int main()
{
    int n, m;
    ld r;
    in >> n;
    vector <Point> polygon(n + 1);

    polygon[0].read();
    delta = polygon[0];
    center = Point(0, 0);

    for (int i = 1; i < n; i++)
    {
        polygon[i].read();
        polygon[i] = polygon[i] - delta;
    }

    polygon[0] = polygon[0] - delta;
    polygon[n] = polygon[0];



    in >> m;
    for (int j = 0; j < m; j++)
    {
        rad.read();
        rad = rad - delta;

        r = dist(rad, polygon[0]);
        vector <Point> inter;
        for (int i = 0; i < n; i++)
        {
            Line line;
            line.make2points(polygon[i], polygon[i + 1]);
            if (good(polygon[i], polygon[i + 1], r))
            {
                if (fabs(line.b) > EPS)
                {
                    ld curr_a, curr_b, curr_c, y1, y2, x1, x2, x3, x4;
                    curr_a = line.a * line.a + line.b * line.b;
                    curr_b = 2 * line.b * line.c;
                    curr_c = line.c * line.c - r * r * line.a * line.a;
                    y1 = (-curr_b + sqrtl(curr_b * curr_b - 4 * curr_a * curr_c)) / (2. * curr_a);
                    y2 = (-curr_b - sqrtl(curr_b * curr_b - 4 * curr_a * curr_c)) / (2. * curr_a);
                    x1 = sqrtl(r * r - y1 * y1);
                    x2 = -sqrtl(r * r - y1 * y1);
                    x3 = sqrtl(r * r - y2 * y2);
                    x4 = -sqrtl(r * r - y2 * y2);
                    if (in_line(line, Point(x1, y1)) && in_otr(polygon[i], polygon[i + 1], Point(x1, y1)))
                        inter.push_back(Point(x1, y1));
                    if (in_line(line, Point(x2, y1)) && in_otr(polygon[i], polygon[i + 1], Point(x2, y1)))
                        inter.push_back(Point(x2, y1));
                    if (in_line(line, Point(x3, y2)) && in_otr(polygon[i], polygon[i + 1], Point(x3, y2)))
                        inter.push_back(Point(x3, y2));
                    if (in_line(line, Point(x4, y2)) && in_otr(polygon[i], polygon[i + 1], Point(x4, y2)))
                        inter.push_back(Point(x4, y2));
                }
                else
                {
                    ld y, x1, x2;
                    y = polygon[i].y;
                    x1 = sqrtl(r * r - y * y);
                    x2 = -sqrtl(r * r - y * y);
                    if (in_line(line, Point(x1, y)) && in_otr(polygon[i], polygon[i + 1], Point(x1, y)))
                        inter.push_back(Point(x1, y));
                    if (in_line(line, Point(x2, y)) && in_otr(polygon[i], polygon[i + 1], Point(x2, y)))
                        inter.push_back(Point(x2, y));
                }
            }
        }

        out.precision(20);
        out << fixed;

        if (!inter.empty())
        {
            ld min_angle = 360., max_angle = 360.;
            for (int i = 0; i < inter.size(); i++)
            {
                ld angle_clock, angle_aclock;
                angle_clock = 360. * (atan2(inter[i].x, inter[i].y) - atan2(rad.x, rad.y)) / (2. * M_PI);
                if (angle_clock < 0.)
                    angle_clock += 360.;
                angle_aclock = 360. * (atan2(rad.x, rad.y) - atan2(inter[i].x, inter[i].y)) / (2. * M_PI);
                if (angle_aclock < 0.)
                    angle_aclock += 360.;
                min_angle = min(min_angle, angle_clock);
                max_angle = min(max_angle, angle_aclock);
            }

            out << max_angle << ' ' << min_angle << endl;
        }
        else
        {
            out << "360.00000000 360.00000000" << endl;
        }
    }


    in.close();
    out.close();

    return 0;
}
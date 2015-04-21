#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;

const int INF = 1000 * 1000 * 1000 + 100;
const double eps = 0.0000001;

struct Point
{
    int x,y;
} point[400][400];

int leng[400];

double get_y(Point p1, Point p2, int p)
{
    double a = p1.y - p2.y,
           b = p2.x - p1.x,
           c = (double)p1.x * p2.y - (double)p1.y * p2.x;
    return (-a * p - c) / b;
}

bool check(int pl1, int pl2)
{
    bool higher = 0, lower = 0;
    int p1 = 0, p2 = 1;

    while(p1 < leng[pl1])
    {
        while(point[pl2][p2].x < point[pl1][p1].x)
            p2++;
        double y = get_y(point[pl2][p2], point[pl2][p2 - 1], point[pl1][p1].x);
        if(y - point[pl1][p1].y > eps)
            lower = 1;
        else if(point[pl1][p1].y - y > eps)
            higher = 1;
        p1++;
    }
    return lower && higher;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a,b,n;
    cin >> a >> b >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> leng[i];
        leng[i]++;
        for(int j = 0; j < leng[i]; j++)
            cin >> point[i][j].x >> point[i][j].y;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j && check(i, j))
            {
                cout << "No\n" << i + 1 << ' ' << j + 1 << '\n';
                return 0;
            }
    cout << "Yes\n";
    return 0;
}

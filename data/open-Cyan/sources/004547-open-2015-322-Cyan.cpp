#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cstring>
#include <iomanip>
#include <algorithm>

using namespace std;

const double eps = 1e-7;

struct point{
    double x, y;
    point(){};
    point(int x0, int y0){
        x = x0;
        y = y0;
    }
};

struct my_vector{
    long long x, y;
    my_vector(point p1, point p2): x(p2.x - p1.x), y(p2.y - p1.y){}
};

long long dot(my_vector v1, my_vector v2){
    return (v1.x * v2.x + v1.y * v2.y);
}

long long cross(my_vector v1, my_vector v2){
    return (v1.x * v2.y - v2.x * v1.y);
}

bool dif_cross(long long &a, long long &b){
    if ((a >= 0 && b <= 0) || (a <= 0 && b >= 0))
        return true;
    else
        return false;
}

struct line{
    double k;
    point p1, p2;
    line(point pn, point pk){
        p1 = pn;
        p2 = pk;
        k = (p2.y - p1.y)/(p2.x - p1.x);
    }
};

point intersection(line l1, line l2){
    double a1(l1.p1.y - l1.p2.y), a2(l2.p1.y - l2.p2.y), b1(l1.p2.x - l1.p1.x), b2(l2.p2.x - l2.p1.x);
    double c1(-l1.p1.x*a1 - l1.p1.y*b1), c2(-l2.p1.x * a2 - l2.p1.y * b2);
    if (a1 == 0){
        swap(a1, a2);
        swap(b1, b2);
        swap(c1, c2);
    }
    point p;
    p.y = (a2 * c1 - c2 * a1) / (a1 * b2 - b1 * a2);
    p.x = (-c1 - b1 * p.y) / a1;
    return p;
}

bool isintersected(line l1, line l2){
    if (abs(l1.k - l2.k) < eps)
        return false;
    return true;
}

int main(){
    //ios_base::sync_with_stdio(0);
    //ifstream in("input.txt");
    //ofstream out("output.txt");
    int a, b, n, l;
    cin >> a >> b >> n;
    vector<line> mount[n];
    point last, p;
    for (int i = 0; i < n; i++){
        cin >> l;
        for (int j = 0; j <= l; j++){
            cin >> p.x >> p.y;
            if (j != 0)
                mount[i].push_back(line(last, p));
            last = p;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            if (i == j)
                continue;
            int l = 0;
            bool bb = false;
            for (int a = 0; a < mount[i].size(); a++)
                for (int b = l; b < mount[j].size(); b++){
                    if (mount[j][b].p2.x <= mount[i][a].p1.x){
                        l++;
                        continue;
                    }
                    if (mount[j][b].p1.x >= mount[i][a].p2.x)
                        break;
                    if (!isintersected(mount[i][a], mount[j][b]))
                        continue;
                    else{
                        p = intersection(mount[i][a], mount[j][b]);
                        if (p.x > mount[i][a].p1.x && p.x < mount[i][a].p2.x &&
                        p.x > mount[j][b].p1.x && p.x < mount[j][b].p2.x){
                            cout << "No" << endl;
                            cout << i + 1 << " " << j + 1 << endl;
                            return 0;
                        }
                        /*if (p.x == mount[i][a].p2.x && a != mount[i].size() - 1){
                            if (mount[i][a].k < mount[j][b].k && mount[i][a + 1].k > mount[j][b].k){
                                cout << "No" << endl;
                                cout << i + 1 << " " << j + 1 << endl;
                                return 0;
                            }else
                            if (mount[i][a].k > mount[j][b].k && mount[i][a + 1].k < mount[j][b].k){
                                cout << "No" << endl;
                                cout << i + 1 << " " << j + 1 << endl;
                                return 0;
                            }
                        }*/

                    }
            }
    }
    cout << "Yes" << endl;
    return 0;
}

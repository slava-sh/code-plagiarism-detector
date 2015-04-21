#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct point{
    int x;
    double y;

    point(int _x, double _y){
        x = _x;
        y = _y;
    }

    point(){
    }

};

const double eps = 1e-7;
int l[200001];
vector<point> ln[100001];

double get(point a, point b, int x){
    if (b.x == a.x) return a.x;
    return ((b.y - a.y) / ((double)(b.x - a.x))) * ((double)(x - a.x)) + a.y;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> l[i];
        ln[i].resize(l[i]);
        for (int j = 0; j < l[i] + 1; j++){
            int x;
            double y;
            cin >> x >> y;
            ln[i][j] = point(x, y);
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            int i1 = 0;
            int j1 = 0;
            bool b1 = false;
            bool b2 = false;
            if (ln[i][i1].y > ln[j][j1].y + eps){
                b1 = true;
            }
            if (ln[i][i1].y + eps < ln[j][j1].y){
                b2 = true;
            }
            while (i1 < l[i] && j1 < l[j]){
                int x1 = ln[i][i1].x;
                int x2 = ln[j][j1].x;
                if (x1 < x2){
                    int x3 = ln[i][i1 + 1].x;
                    while (x2 < x3){
                        double y1 = get(ln[i][i1], ln[i][i1 + 1], x2);
                        double y2 = ln[j][j1].y;
                        double a = (y2 - y1);
                        if (a - eps > 0){
                            b2 = true;
                        }
                        if (a + eps < 0){
                            b1 = true;
                        }
                        j1++;
                        x2 = ln[j][j1].x;
                    }
                    j1--;
                    i1++;
                }
                else{
                    int x3 = ln[j][j1 + 1].x;
                    while (x1 < x3){
                        double y1 = get(ln[j][j1], ln[j][j1 + 1], x2);
                        double y2 = ln[i][i1].y;
                        double a = (y2 - y1);
                        if (a - eps > 0){
                            b1 = true;
                        }
                        if (a + eps < 0){
                            b2 = true;
                        }
                        i1++;
                        x1 = ln[i][i1].x;
                    }
                    i1--;
                    j1++;
                }
            }
            if (b1 && b2){
                cout << "No\n" << i + 1 << " " << j + 1;
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}

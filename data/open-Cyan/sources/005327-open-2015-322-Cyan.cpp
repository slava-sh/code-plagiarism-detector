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

int main(){
    //ios_base::sync_with_stdio(0);
    //ifstream in("input.txt");
    //ofstream out("output.txt");
    int a, b, n, l;
    cin >> a >> b >> n;
    vector<point> mount[n];
    double pos[n][150];
    point p;
    for (int i = 0; i < n; i++){
        cin >> l;
        for (int j = 0; j <= l; j++){
            cin >> p.x >> p.y;
            mount[i].push_back(p);
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 1; j < mount[i].size(); j++){
            for (int k = mount[i][j - 1].x; k < mount[i][j].x; k++){
                pos[i][k + 50] = (mount[i][j].y - mount[i][j - 1].y)/(mount[i][j].x - mount[i][j - 1].x) * (k - mount[i][j - 1].x) + mount[i][j - 1].y;
            }
            pos[i][b + 50] = mount[i][mount[i].size() - 1].y;
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++){
            bool b1(false), b2(false);
            for (int k = a + 50; k <= b + 50; k++){
                if (pos[i][k] > pos[j][k])
                    b1 = true;
                else
                if (pos[i][k] < pos[j][k])
                    b2 = true;
            }
            if (b1 && b2){
                cout << "No" << endl;
                cout << i + 1 << " " << j + 1;
                return 0;
            }
    }
    cout << "Yes" << endl;
    return 0;
}

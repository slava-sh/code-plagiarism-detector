#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <fstream>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 100000 + 10;

vector <pii> lines[N];
double z[200][200];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int leng;
        cin >> leng;
        for (int j = 0; j <= leng; j++) {
            int x, y;
            cin >> x >> y;
            x -= a;
            lines[i].push_back(make_pair(x, y));
        }
    }
    b -= a;
    a = 0;
    /*
    cout << a << " " << b << "\n";
    for (int i = 1; i <= n; i++) {
        cout << "LINE " << i << "\n";
        for (int j = 0; j < lines[i].size(); j++) {
            cout << "POINT " << lines[i][j].first << " " << lines[i][j].second << "\n";
        }
    }
    */
    //cout << setprecision(6) << fixed;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < lines[i].size(); j++) {
            int lf = lines[i][j - 1].first;
            int rh = lines[i][j].first;
            for (int x = lf; x <= rh; x++) {
                z[i][x] = lines[i][j - 1].second + (lines[i][j].second - lines[i][j - 1].second) * ((x - lf) / (rh - lf + 0.0));
                //cout << i << " " << x << " " << z[i][x] << "\n";
            }
            //cout << lf << " " << rh << "\n";
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
            bool ok = false;
            for (int x1 = 0; x1 <= b; x1++) {
                for (int x2 = 0; x2 <= b; x2++) {
                    if (z[i][x1] > z[j][x1] && z[i][x2] < z[j][x2]) {
                        ok = true;
                    }
                }
            }
            if (ok) {
                cout << "No\n";
                cout << i << " " << j << "\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}
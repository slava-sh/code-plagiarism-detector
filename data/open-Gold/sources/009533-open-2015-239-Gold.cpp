#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#define mp make_pair
#define x first
#define y second
#define point pair<int, int>
#define pb push_back
#define For(i, a, b) for(int i = a; i < b; ++i)
#define int long long
#define pow asdf

using namespace std;

int n, k, c, d;
vector <point> light;
int arr[7501][7501];

main() {
    cin >> n >> k >> c >> d;
    For(i, 0, n) {
        int a, b;
        cin >> a >> b;
        light.pb(mp(a, b));
    }
    For(i, 0, n) {
        For(j, 0, k) {
            arr[i][j] = 1e18;
        }
    }
    arr[0][k] = (light[0].y - light[0].x) * d;
    For(i, 1, n) {
        int ans1 = (light[i].x - light[i - 1].y) * d, ans2 = (light[i].y - light[i].x) * d;
        For(j, 1, k) {
            arr[i][j] = min(arr[i - 1][j] + ans1, arr[i - 1][j + 1]) + ans2;
        }
        arr[i][k] = min(arr[i - 1][k] + ans1, arr[i - 1][1] + c) + ans2;
    }
    int MinAns = 1e18;
    For(i, 1, k + 1) {
        MinAns = min(MinAns, arr[n - 1][i]);
    }
    cout << MinAns << endl;
}


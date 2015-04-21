#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cstdlib>

#define mp make_pair
#define ll long long
#define ld long double
#define pii pair <int, int>

using namespace std;

const int N = (int)5e5 + 7;
const ll INF = (ll)1e9 + 7;
const ld EPS = 1e-9;

short int b[15007][15007], m[15007][15007], a[N];

int main(){
    int n, dd, x = -1, y = -1, ma = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++){
        if (i != 0)
            for (int j = 0; j < n; j++)
                b[i][j] = b[i - 1][j], m[i][j] = m[i - 1][j];
        for (int j = 0; j < a[i]; j++)
            b[i][j]++;
        for (int j = a[i] + 1; j < n; j++)
            m[i][j]++;
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]){
                dd = m[n - 1][a[i]] - m[i][a[i]] + m[n - 1][a[j]] - m[j][a[j]] - (m[n - 1][a[i]] - m[j][a[i]] + m[n - 1][a[j]] - m[i][a[j]]);
                if (dd > ma)
                    ma = dd, x = i + 1, y = j + 1;
            }
    cout << x << " " << y;
    return 0;
}

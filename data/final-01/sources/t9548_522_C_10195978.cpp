//#pragma comment(linker,"/STACK:100000000000,100000000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <iomanip>
#include <queue>
#include <map>
#include <functional>
#include <list>
#include <sstream>
#include <ctime>
#include <climits>
#include <bitset>
#include <list>
#include <cassert>
#include <complex>

using namespace std;

/* Constants begin */
const long long inf = 2e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = 2*acos(0.0);
const double E = 2.71828;
/* Constants end */

/* Defines begin */
#define pb push_back
#define mp make_pair
#define ll long long
#define double long double
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define forn(i, n) for (int (i)=0; (i)<(n); ++(i))
#define random (rand()<<16|rand())
#define sqr(x) (x)*(x)
#define base complex<double>
/* Defines end */

int t;

int n, m;
int a[100005];
int x[100005], y[100005];
int last[100005];
char res[100005];

void Solve() {
    scanf("%d %d", &n, &m); --n;
    for (int i = 0; i <= m; ++i) {
        last[i] = -1;
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; ++i) {
        res[i] = 'N';
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &x[i], &y[i]);
        last[x[i]] = i;
    }

    bool firstBad = false;
    int zeroesBefore = 0, zeroesAfter = 0;
    int bst = -mod;

    for (int i = 1; i <= n; ++i) {
        if (y[i] == 1 && !firstBad) {
            firstBad = true;
            for (int num = 1; num <= m; ++num) {
                if (last[num] < i && zeroesBefore >= a[num]) {
                    res[num] = 'Y';
                    bst = max(bst, zeroesBefore - a[num]);
                }
            }
        }
        if (!firstBad) {
            if (x[i] == 0)
                ++zeroesBefore;
            else
                --a[x[i]];
        } else {
            if (x[i] == 0)
                ++zeroesAfter;
            else
                --a[x[i]];
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (firstBad) {
            if (res[i] == 'Y' ||
                zeroesAfter + bst >= a[i]) {
                res[i] = 'Y';
            }
        } else {
            if (zeroesBefore + zeroesAfter >= a[i]) {
                res[i] = 'Y';
            }
        }
        printf("%c", res[i]);
    }
    printf("\n");
}

int main(void) {
    #ifdef nobik
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        Solve();
    }
    return 0;
}
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <functional>
#include <cassert>
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n,a[1001005];

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);

    scanf("%d",&n);
    bool good = true;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
        good &= (a[i] == i+1);
    }
    if (good) { printf("-1 -1"); return 0; }
    int mx = 0, mxi = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] != i+1 && mx < a[i]) {
            mx = a[i];
            mxi = i;
        }
    }
    int mxl = -2e9, mxli = -1, mnr = 2e9, mnri = -1;
    for (int i = 0; i < mxi; ++i) {
        if (a[i] > mxl) {
            mxl = a[i];
            mxli = i;
        }
    }
    for (int i = mxi+1; i < n; ++i) {
        if (a[i] < mnr) {
            mnr = a[i];
            mnri = i;
        }
    }

    if (mnri == -1) printf("%d %d",mxli+1, mxi+1);
    else if (mxli == -1) printf("%d %d",mxi+1, mnri+1);
    else printf("%d %d",mxli+1,mnri+1);

    return 0;
}

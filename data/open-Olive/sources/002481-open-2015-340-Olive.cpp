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

int n,a[1001005],inv[1001005];

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

    for (int i = 0; i < n; ++i) {
        inv[i] = abs(i+1 - a[i]);
    }

    int mx = -2e9, mxi = -1;
    for (int i = 0; i < n; ++i) {
        if (inv[i] > mx) mx = inv[i], mxi = i;
    }
    int mx2 = -2e9, mx2i = -1;
    for (int i = 0; i < n; ++i) {
        if (inv[i] > mx2 && (i < mxi && a[i] > a[mxi] || i > mxi && a[i] < a[mxi])) mx2 = inv[i], mx2i = i;
    }
    if (mxi > mx2i) swap(mxi, mx2i);
    printf("%d %d",mxi+1,mx2i+1);

    return 0;
}

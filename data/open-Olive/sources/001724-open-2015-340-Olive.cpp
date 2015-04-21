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
        for (int j = i + 1; j < n; ++j)
            if (a[i] > a[j]) ++inv[i];
    }

    int mx = -2e9, mxi = -1;
    for (int i = 0; i < n; ++i) {
        if (inv[i] > mx && a[i] != i+1) mx = inv[i], mxi = i;
    }
    int mn = 2e9, mni = -1;
    for (int i = mxi+1; i < n; ++i) {
        if (inv[i] < mn && a[i] != i+1) mn = inv[i], mni = i;
    }
    printf("%d %d",mxi+1,mni+1);

    return 0;
}

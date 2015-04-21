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
ll sum,mn=9e18;
int mni1,mni2;

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
        sum += ll(inv[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ll cursum = sum - inv[i] - inv[j] + ll(abs(i+1-a[j])) + ll(abs(j+1-a[i]));
            if (cursum < mn) {
                mn = cursum;
                mni1 = i+1;
                mni2 = j+1;
            }
        }
    }

    printf("%d %d",mni1,mni2);

    return 0;
}

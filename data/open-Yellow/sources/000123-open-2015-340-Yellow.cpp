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

int n,q,x,y,a[100105];
int ans;

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);

    scanf("%d",&n);
    for (int i = 0; i < n; ++i) scanf("%d",&a[i]);
    for (int i = 1; i < n; ++i)
        if (a[i] != a[i-1]) ++ans;
    if (n) ++ans;

    scanf("%d",&q);
    if (n == 1) {
        while (q--) printf("1\n");
        return 0;
    }

    while (q--) {
        scanf("%d%d",&x,&y); --x;
        if (x == 0) {
            if (a[0] == a[1]) {
                a[0] = y;
                if (a[0] != a[1]) ++ans;
            } else {
                a[0] = y;
                if (a[0] == a[1]) --ans;
            }
        } else if (x == n-1) {
            if (a[n-2] == a[n-1]) {
                a[n-1] = y;
                if (a[n-2] != a[n-1]) ++ans;
            } else {
                a[n-1] = y;
                if (a[n-2] == a[n-1]) --ans;
            }
        } else {
            if (a[x-1] == a[x]) {
                if (a[x] == a[x+1]) {
                    a[x] = y;
                    if (a[x] != a[x+1]) ans += 2;
                } else {
                    a[x] = y;
                    if (a[x-1] != a[x] && a[x] != a[x+1]) ++ans;
                }
            } else {
                if (a[x] == a[x+1]) {
                    a[x] = y;
                    if (a[x-1] != a[x] && a[x] != a[x+1]) ++ans;
                } else {
                    if (a[x-1] == a[x+1]) {
                        a[x] = y;
                        if (a[x-1] == a[x]) ans -= 2;
                    } else {
                        a[x] = y;
                        if (a[x-1] == a[x] || a[x] == a[x+1]) --ans;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}

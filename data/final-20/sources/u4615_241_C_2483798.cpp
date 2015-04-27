#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#else
#define LOG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (1LL<<60)
#define MOD (YOUR_MODULUS)
#define EPS (1e-6)

int h1, h2, n;
int v[128], a[128], b[128], use[128];
char c[128];

int solve(int C, int f, int t) {
    rep (i, n) use[i] = 0;
    double k = (t-h1)/100000.0;
    int ans = 0;
    rep (i, C) {
        const int y = t < 0 ? -i*100 : (i+1)*100;
        double x = (y - h1) / k;
        assert(0 <= x && x <= 100000);
        int ix = -1;
        rep (j, n) {
            if ((f+i)%2 == 1 && c[j] == 'T') {
                if (a[j]-EPS <= x && x <= b[j]+EPS) ix = j;
            }
            if ((f+i)%2 == 0 && c[j] == 'F') {
                if (a[j]-EPS <= x && x <= b[j]+EPS) ix = j;
            }
        }
        if (ix == -1 || use[ix]) return 0;
        ans += v[ix];
        use[ix] = 1;
    }
    return ans;
}

int main() {
    scanf("%d%d%d", &h1, &h2, &n);
    rep (i, n) scanf("%d %c%d%d", v+i, c+i, a+i, b+i);
    int ans = 0;
    for (int i = 1, t = h2; i <= 200; i++) {
        t -= i%2 ? h2*2 : (100-h2)*2;
        ans = max(ans, solve(i, 0, t));
    }
    for (int i = 1, t = h2; i <= 200; i++) {
        t += i%2 ? (100-h2)*2 : h2*2;
        ans = max(ans, solve(i, 1, t));
    }
    printf("%d\n", ans);
    return 0;
}

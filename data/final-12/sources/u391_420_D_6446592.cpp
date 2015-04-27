#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
#include <numeric>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define forit(it,S) for(__typeof(S.begin()) it = S.begin(); it != S.end(); ++it)
#ifdef WIN32
#define I64d "%I64d"
#else
#define I64d "%lld"
#endif

typedef pair <int, int> pi;
typedef vector <int> vi;
typedef long long ll;

const int maxn = 2000000;
int xx[1111111], yy[1111111];
int pos[1111111], n, m, op[1111111], np[1111111], ff;
int owner[3333333], f[3333333];
int ans[1111111];
bool used[1111111];


void imp() {
    puts("-1");
    exit(0);
}

inline int sum(int x) {
    int r = 0;
    while (x >= 0) {
        r += f[x];
        x = (x & (x + 1)) - 1;
    }
    return r;
}

inline void add(int x, int d) {
    while (x <= maxn) {
        f[x] += d;
        x = (x | (x + 1));
    }
}
               
inline int getFirst(int x) {
    int l = -1, r = maxn;
    while (r - l > 1) {
        int mid = ((l + r) >> 1);
        if (sum(mid) >= x) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}


int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &xx[i], &yy[i]);
        --xx[i];
    }
    memset(owner, -1, sizeof(owner));
    memset(pos, -1, sizeof(pos));
    
    int ff = m;
    for (int i = 1; i <= n; ++i) {
        add(ff + i, 1);
    }
    
    for (int i = 0; i < m; ++i) {
        int &oldPlace = op[i];
        int &newPlace = np[i];
        int &x = xx[i];
        int &y = yy[i];
        
        oldPlace = getFirst(y);
        if ((pos[x] != -1 && oldPlace != pos[x]) || (owner[oldPlace] != -1 && owner[oldPlace] != x)) {
            imp();
        }
        newPlace = ff--;
        
        owner[oldPlace] = -1;
        add(oldPlace, -1);
        
        add(newPlace, 1);
        pos[x] = newPlace;
        owner[newPlace] = x;
        
        //printf("x=%d y=%d op=%d np=%d pos=%d\n", x + 1, y, oldPlace, newPlace, pos[x]);
    }
    
    for (int i = m - 1; i >= 0; --i) {
        int &oldPlace = op[i];
        int &newPlace = np[i];
        int &x = xx[i];
        int &y = yy[i];
        
        pos[x] = oldPlace;
        owner[oldPlace] = x;
        add(oldPlace, 1);
        
        owner[newPlace] = -1;
        add(newPlace, -1);
    }
    
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < n; ++i) if (pos[i] != -1) {
        int p = sum(pos[i]);
        ans[p - 1] = i;
        used[i] = true;
    }
    
    int fx = 0;
    for (int i = 0; i < n; ++i) if (ans[i] == -1) {
        while (used[fx]) {
            ++fx;
        }
        ans[i] = fx;
        used[fx] = true;
    }
    
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            putchar(' ');
        }
        printf("%d", ans[i] + 1);
    }
    puts("");
    return 0;
}
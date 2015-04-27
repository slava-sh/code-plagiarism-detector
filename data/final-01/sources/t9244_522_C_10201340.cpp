#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

#define pb push_back
#define pp pop_back
#define f first
#define s second
#define mp make_pair
#define sz(a) int((a).size())
#define fname "."

const int N = (int)1e5 + 123;
const double eps = 1e-6;
const int inf = (int)1e9 + 123;

using namespace std;

int m, k;
int a[N];
int t[N], r[N];
int cnt;
bool u[N];
bool H;
int num[N];

inline void solve() {
    memset(u, 0, sizeof u);
    H = cnt = 0;
    scanf("%d%d", &m, &k);
    for (int i = 1; i <= k; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < m; i++) {
        scanf("%d%d", &t[i], &r[i]);
        num[t[i]]++;
    }
    for (int i = 1; i < m; i++) {
        if (r[i] && !H) {
            H = 1;
            int mini = inf;
            for (int i = 1; i <= k; i++) {
                if (num[i] > 0)
                    continue;
                mini = min(mini, a[i]);
                if (cnt >= a[i])
                    u[i] = 1;
            }
            cnt -= mini;
        }
        if (t[i] == 0)
            cnt++;
        else {
            num[t[i]]--;
            a[t[i]]--;
            if (!a[t[i]])
                H = u[t[i]] = 1;
        }
    }
    for (int i = 1; i <= k; i++) {
        if (cnt >= a[i])
            u[i] = 1;
        if (!u[i])
            printf("N");
        else
            printf("Y");
    }
    printf("\n");
}

int main()
{
//  freopen(fname"in","r",stdin);
//  freopen(fname"out","w",stdout);
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}

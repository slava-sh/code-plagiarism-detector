#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (int)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

int a[1010], n;
int b[1010];
int c[1010];

int f(int x, int y) {
    swap(a[x], a[y]);
    int i, j, ans = 0;
    for(i = 1; i <= n; i++)
        for(j = i + 1; j <= n; j++)
            if(a[i] > a[j])
                ans++;
    swap(a[x], a[y]);
    return ans;
}

int main() {
    must;
    int i, ii, jj, ans, j;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> a[i];
    ans = f(1, 1);
    ii = jj = -1;
    for(i = 1; i <= n; i++)
    for(j = i + 1; j <= n; j++) {
        int x = f(i, j);
        if(ans > x) {
            ans = x;
            ii = i, jj = j;
        }
    }
    cout << ii << ' ' << jj << "\n";
    return 0;
}

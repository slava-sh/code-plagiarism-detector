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

int a[5010], n;
int b[5010][5010], kol;
int c[5010][5010];


int main() {
    inp("input.txt");
    must;
    int i, ii, jj, ans, j;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> a[i];
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++)
            b[i][j] = b[i][j - 1] + (a[j] > a[i]);
        for(j = n; j >= 1; j--)
            c[i][j] = c[i][j + 1] + (a[j] < a[i]);
    }
    ans = 0;
    for(i = 1; i <= n; i++)
        for(j = i + 1; j <= n; j++)
            ans += (a[i] > a[j]);
//    cout << ans << "\n\n";
    kol = ans;
    ii = jj = -1;

    for(i = 1; i <= n; i++)
    for(j = i + 1; j <= n; j++) {
//        if(a[i] < a[j]) continue;
        int d = kol - c[j][j + 1] - b[j][j - 1] - c[i][i + 1] - b[i][i - 1] + b[j][i - 1] + c[j][i + 1] + b[i][j - 1] + c[i][j + 1];
        if(d < ans) {
            ans = d;
            ii = i;
            jj = j;

        }
    }
//    cout << ans << "\n";
    cout << ii << ' ' << jj << "\n";
}


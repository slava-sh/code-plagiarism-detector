#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

vector <vector <int> > t;
int n;

vector <int> unite(const vector <int> &a, const vector <int> &b)
{
    vector <int> ans;
    int n = sz(a), m = sz(b);
    for (int i = 0, j = 0; i <= n && j <= m;)
    {
        if (i == n && j == m) break;
        if (i == n || a[i] > b[j]) {ans.pb(b[j]); ++j;}
        else {ans.pb(a[i]); ++i;}
    }
    return ans;
}

int solve(const vector <int> &a, int c)
{
    return lower_bound(all(a), c) - a.begin();
}

int get(int l, int r, int c)///how many < c
{
    int ans = 0;
    for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1)
    {
        if (l & 1) ans += solve(t[l], c);
        if (!(r & 1)) ans += solve(t[r], c);
        //cout << t[l][0] << " " << t[r][0] << "\n";
    }
    return ans;
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    vector <int> a(n);

    t.resize(2 * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        t[i + n].pb(a[i]);
    }

    for (int i = n - 1; i; i--)
        t[i] = unite(t[i * 2], t[i * 2 + 1]);

    bool ok = true;
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1]) {ok = false; break;}

    vector <pii> suff_min(n);
    suff_min[n - 1] = mp(a[n - 1], n - 1);

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < suff_min[i + 1].first) suff_min[i] = mp(a[i], i);
        else suff_min[i] = suff_min[i + 1];
    }

    if (ok) {printf("-1 -1\n"); return 0;}

    int ans = 0;
    int posl, posr;

    for (int l = 0; l < n - 1; l++)
    {
        for (int r = l + 1; r < n; r++)
            if (a[r] < a[l]/* && (r == n - 1 || suff_min[r + 1].first > a[r])*/)
        {
            int g = 2 * (get(l + 1, r - 1, a[l]) - get(l + 1, r - 1, a[r])) + 1;
            if (ans < g)
            {
                ans = g;
                posl = l;
                posr = r;
            }

        }
    }

    cout << posl + 1 << " " << posr + 1 << "\n";

}




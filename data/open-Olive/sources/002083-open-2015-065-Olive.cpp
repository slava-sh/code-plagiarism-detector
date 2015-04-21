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

void out(const vector <int> &a)
{
    int n = sz(a);
    printf("%d: ", n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

inline int solve(const vector <int> &a, int c)
{
    return lower_bound(all(a), c - 1) - a.begin() + 1;
}

int get(int l, int r, int c)///how many < c
{
    int ans = 0;
    for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1)
    {
        if (l & 1) ans += solve(t[l], c);
        if (!(r & 1)) ans += solve(t[r], c);
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

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

    if (ok) {printf("-1 -1\n"); return 0;}

    int ans = 0;
    int posl, posr;

    for (int l = 0; l < n - 1; l++)
    {
        int minim = a[l];
        for (int r = l + 1; r < n; r++)
        {
            if (minim > a[r])
            {
                int g = 2 * (get(l, r, a[l]) - get(l, r, a[r])) + 1;
                if (ans < g)
                {
                    ans = g;
                    posl = l;
                    posr = r;
                }
                minim = a[r];
            }
        }
    }

    cout << posl + 1 << " " << posr + 1 << "\n";

}




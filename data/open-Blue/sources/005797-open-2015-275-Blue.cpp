#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define forn(i,a,b) for(int i = a; i < (int)b; i++)
#define srep(i, a) for(__typeof(a.begin()) i = a.begin(); i != a.end(); i++)

typedef long long ll;

const int maxn = 1005;
const int p = 29;
const ll mod = 1e9+7;

ll h[maxn];
ll pp[maxn];

inline ll gethash(int l, int r)
{
    if (l == 0) return h[r];
    return ((h[r] - h[l-1]*pp[r-l+1])%mod+mod)%mod;
}

inline bool cmp(int l1, int r1, int l2, int r2)
{
    return gethash(l1, r1) == gethash(l2, r2);
}

bool d[maxn];
int n, L;
string s;

bool check(int l1, int h1, int l2, int h2, int bn)
{
    forn(j, bn, n+1)
    {
        if (j >= l1 && d[j-l1] && gethash(j-l1, j-1) == h1)
        {
            d[j] = 1;
        }
        if (j >= l2 && d[j-l2] && gethash(j-l2, j-1) == h2)
        {
            d[j] = 1;
        }
    }
    bool res = d[n];
    forn(j, bn, n+1) d[j] = 0;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> L >> s;
    n = s.length();
    h[0] = s[0]-'a';
    forn(i, 1, n) h[i] = (h[i-1]*p+s[i]-'a')%mod;
    pp[0] = 1;
    forn(i, 1, n+1) pp[i] = pp[i-1]*p%mod;
    forn(i, 1, L+1)
    {
        if (n%i != 0) continue;
        if (cmp(0, n-1-i, i, n-1))
        {
            cout << 1 << endl;
            cout << s.substr(0, i);
            return 0;
        }
    }
    if (s.find("c") == string::npos)
    {
        cout << 2 << endl << 'a' << endl << 'b';
        return 0;
    }
    if (s.find("a") == string::npos)
    {
        cout << 2 << endl << 'c' << endl << 'b';
        return 0;
    }
    if (s.find("b") == string::npos)
    {
        cout << 2 << endl << 'a' << endl << 'c';
        return 0;
    }
    forn(l1, 1, L+1)
    {
        ll h1 = gethash(0, l1-1);
        int k = 1;
        while (l1*k+l1-1 < n && gethash(l1*k, l1*k+l1-1) == h1) k++;
        rep(i, n+1) d[i] = 0;
        rep(i, k+1) d[i*l1] = 1;
        forn(l2, 1, L+1)
        {
            ll h2 = gethash(l1*k, l1*k+l2-1);
            if (check(l1, h1, l2, h2, k*l1+1))
            {
                cout << 2 << endl;
                cout << s.substr(0, l1) << endl;
                cout << s.substr(l1*k, l2);
                return 0;
            }
        }
    }
    cout << 3 << endl << 'a' << endl << 'b' << endl << 'c';
    return 0;
}

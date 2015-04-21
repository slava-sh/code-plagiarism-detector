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

int main()
{
    int L;
    string s;
    cin >> L >> s;
    int n = s.length();
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
    cout << 2 << endl << 'a' << endl << 'b';
    return 0;
}

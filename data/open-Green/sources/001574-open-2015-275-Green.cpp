#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define forn(i,a,b) for(int i = a; i < (int)b; i++)
#define srep(i, a) for(__typeof(a.begin()) i = a.begin(); i != a.end(); i++)

const ll INF = 1e18;

inline ll dup2(ll a)
{
    return (a >> ((ll)1))+(a & ((ll)1));
}

int K;
ll N;

vector<ll> divs;
ll res = INF;

ll dans[1000][1000];

ll go(int n, int k, ll tans)
{
    if (n == 2 && k == 2)
    {
        int qw = 0;
    }
    if (dans[n][k] != -1)
    {
        res = min(res, tans*dans[n][k]);
        return tans*dans[n][k];
    }
    if (k == K && n == (int)divs.size())
    {
        res = min(res, tans);
        dans[n][k] = 1;
        return tans;
    }
    if (k == K-1)
    {
        ll q = 1;
        forn(i, n, divs.size())
        {
            q *= divs[i];
        }
        ll qq = go(divs.size(), k+1, tans*dup2(q));
        dans[n][k] = qq / tans;
        return qq;
    }
    ll qq = go(n, k+1, tans);
    ll q = 1;
    forn(i, n, divs.size())
    {
        q *= divs[i];
        qq = min(qq, go(i+1, k+1, tans*dup2(q)));
    }
    dans[n][k] = qq / tans;
    return qq;
}

int main()
{
    cin >> N >> K;
    ll bN = N;
    for (ll i = 2; i*i <= bN; i++)
    {
        while (N % i == 0)
        {
            N /= i;
            divs.push_back(i);
        }
    }
    if (N != 1)
    {
        divs.push_back(N);
    }
    N = bN;
    rep(i, divs.size()+1)
    {
        rep(j, K+1)
        {
            dans[i][j] = -1;
        }
    }
    go(0, 0, 1);
    cout << res;
    return 0;
}

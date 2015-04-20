#include <bits\stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long ll;

vector<pair<int, int> > fact(int n)
{
    vector<pair<int, int> > ans;

    for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
    {
        int deg = 0;
        while (n % i == 0)
            deg++, n /= i;

        ans.pb(mp(i, deg));
    }

    if (n > 1)
        ans.pb(mp(n, 1));
    return ans;
}

ll stp(int x, int y)
{
    ll ans = 1;
    for (int i = 1; i <= y; i++)
        ans *= x;
    return ans;
}

void solve(int n)
{
    int m;
    cin >> m;

    vector<pair<int, int> > nfact = fact(n);
    vector<pair<int, int> > mfact = fact(m);

    vector<int> values;
    vector<int> low,  high;

    map<int, int> Low, High;

    for (int i = 0; i < (int)mfact.size(); i++)
    {
        int l1 = mfact[i].second;
        auto it = lower_bound(nfact.begin(),
                nfact.end(), mp(mfact[i].first, -1));

        int l2;
        if (it == nfact.end() || it -> first !=
            mfact[i].first)
            l2 = 0;
        else
            l2 = (it -> second);

       // cerr << mfact[i].first << endl;
       // cerr << l1 << ' ' << l2 << endl;

        if (l1 < l2)
            Low[mfact[i].first] = l1,
            High[mfact[i].first] = l2;
        else
            Low[mfact[i].first] = l2,
            High[mfact[i].first] = l1;
    }

    for (int i = 0; i < (int)nfact.size(); i++)
    {
        int l1 = nfact[i].second;
        auto it = lower_bound(mfact.begin(),
                mfact.end(), mp(nfact[i].first, -1));

        int l2;
        if (it == mfact.end() || it -> first !=
            nfact[i].first)
            l2 = 0;
        else
            l2 = (it -> second);

        if (l1 < l2)
            Low[nfact[i].first] = l1,
            High[nfact[i].first] = l2;
        else
            Low[nfact[i].first] = l2,
            High[nfact[i].first] = l1;
    }

    for (auto it = Low.begin(); it != Low.end(); it++)
        values.pb(it -> first), low.pb(it -> second),
        high.pb(High[it -> first]);
/*
    for (int x : values)
        cerr << x << ' ';
    cerr << endl;
    for (int x : low)
        cerr << x << ' ';
    cerr << endl;
    for (int x : high)
        cerr << x << ' ';
    cerr << endl;
*/
    int all = (int)values.size();

    ll bestdiff = (int)1e9 + 10;
    ll mema = -1;
    ll memb = -1;

    for (int i = 0; i < (1 << all); i++)
    {
        ll a = 1;
        ll b = 1;

        for (int j = 0; j < all; j++)
        {
            if ((i >> j) & 1)
                a *= stp(values[j], low[j]),
                b *= stp(values[j], high[j]);
            else
                b *= stp(values[j], low[j]),
                a *= stp(values[j], high[j]);
        }

        if (b >= a && bestdiff > b - a)
            bestdiff = b - a, memb = b,
            mema = a;
    }

    cout << mema << ' ' << memb << endl;
}

int main()
{
   // freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("gcm.in", "rt", stdin);
    freopen("gcm.out", "w", stdout);

    int n;
    while (cin >> n)
        solve(n);
}

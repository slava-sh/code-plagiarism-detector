#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef long long ll;

const pair<ll, ll> bad_pair = make_pair(-1, -1);
const ll mod = 1e9 + 7;
const ll p = 5;
const int nmax = 22000;

int pref[nmax];
ll h[nmax];
ll pw[nmax];
map<ll, pair<int, int> > mp;
string s;
int n, l, period;


void read()
{
    fin >> l;
    fin >> s;
    n = s.length();
}


bool try_1()
{
    pref[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int v = pref[i - 1];
        while ((v > 0) && (s[v] != s[i]))
            v = pref[v - 1];
        if (s[i] == s[v])
            v++;
        pref[i] = v;
    }
    //fout << n << ' ' << pref[n - 1] << endl;
    if (2 * pref[n - 1] < n)
        period = n;
    else
        period = n - pref[n - 1];
    if (n % period != 0)
        period = n;
    //fout << period << endl;
    assert(n % period == 0);
    for (int i = period; i < n; i += period)
        assert(s.substr(i, period) == s.substr(0, period));
    return (period <= l);
}


ll hesh(int i, int j)
{
    return (h[i + j] - h[i] * pw[j] + mod * mod) % mod;
}

inline bool good(pair<ll, ll> & p)
{
    return ((p.first >= 0) || (p.second >= 0));
}


pair<ll, ll> dfs(int i, ll h1, ll h2)
{
    //fout << i << ' ' << h1 << ' ' << h2 << endl;
    pair<ll, ll> p;
    if (i == n)
    {
        //fout << i << ' ' << h1 << ' ' << h2 << " returns true" << endl;
        assert((h1 >= 0) || (h2 >= 0));
        return make_pair(h1, h2);
    }
    if ((h1 == -1) && (h2 == -1))
    {
        for (int j = 1; j <= min(n - i, l); j++)
        {
            p = dfs(i + j, hesh(i, j), -1);
            if (good(p))
                return p;
        }
        return bad_pair;
    }
    if (h2 == -1)
    {
        int l1 = mp[h1].second;
        //fout << i << ' ' << l1 << endl;
        assert(l1 > 0);
        if ((l1 <= n - i) && (hesh(i, l1) == h1))
        {
            p = dfs(i + l1, h1, -1);
            if (good(p))
                return p;
        }
        for (int j = 1; j <= min(l, n - i); j++)
            if (hesh(i, j) != h1)
            {
                p = dfs(i + j, h1, hesh(i, j));
                if (good(p))
                    return p;
            }
        return bad_pair;
    }
    int l1 = mp[h1].second;
    int l2 = mp[h2].second;
    if (hesh(i, l1) == h1)
    {
        p = dfs(i + l1, h1, h2);
        if (good(p))
            return p;
    }
    if (hesh(i, l2) == h2)
    {
        p = dfs(i + l2, h1, h2);
        if (good(p))
            return p;
    }
    return bad_pair;
}


bool try_2()
{
    h[0] = 0;
    for (int i = 1; i <= n; i++)
        h[i] = (h[i - 1] * p + s[i - 1] - 'a' + 1) % mod;
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = (pw[i - 1] * p) % mod;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= min(n - i, l); j++)
            mp[hesh(i, j)] = make_pair(i, j);
    /*for (int i = 0; i <= n; i++)
        fout << "h[" << i << "] = " << h[i] << endl;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= n - i; j++)
            fout << "hesh(" << i << ", " << j << ") = " << hesh(i, j) << endl;*/
    //fout << "I am alive" << endl;
    pair<ll, ll> p = dfs(0, -1, -1);
    if (good(p))
    {
        ll h1 = p.first;
        ll h2 = p.second;
        assert(h1 != h2);
        fout << 2 << endl;
        int i = mp[h1].first;
        int j = mp[h1].second;
        fout << s.substr(i, j) << endl;
        i = mp[h2].first;
        j = mp[h2].second;
        fout << s.substr(i, j) << endl;
    }
    return good(p);
}


bool try_22()
{
    h[0] = 0;
    for (int i = 1; i <= n; i++)
        h[i] = (h[i - 1] * p + s[i - 1] - 'a' + 1) % mod;
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = (pw[i - 1] * p) % mod;
    /*for (int i = 0; i < n; i++)
        for (int j = 1; j <= min(n - i, l); j++)
            mp[hesh(i, j)] = make_pair(i, j);*/

    for (int p = 1; p <= l; p++)
    {
        int k;
        //string ss1 = s.substr(0, p);
        ll s1 = h[p];
        for (k = p; k + p <= n; k += p)
            if (hesh(k, p) != s1)
                break;
        for (int q = 1; q <= l; q++)
        {
            //string ss2 = s.substr(k, q);
            ll s2 = hesh(k, q);
            bool flag = true;
            int i = k + q;
            while (i < n)
            {
                bool now = false;
                if ((i + p <= n) && (hesh(i, p) == s1))
                {
                    i += p;
                    now = true;
                }
                if ((i + q <= n) && (hesh(i, q) == s2))
                {
                    i += q;
                    now = true;
                }
                if (!now)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                fout << 2 << endl << s.substr(0, p) << endl << s.substr(k, q) << endl;
                return true;
            }
        }
    }
    return false;
}


void solve()
{
    if (try_1())
    {
        fout << 1 << endl;
        fout << s.substr(0, period);
        return;
    }
    if (try_22())
        return;
    fout << 3 << endl;
    fout << 'a' << endl << 'b' << endl << 'c' << endl;
}


int main()
{
    read();
    solve();
    return 0;
}

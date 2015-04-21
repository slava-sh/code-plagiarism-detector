#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef long long ll;

const pair<ll, ll> bad_pair = make_pair(-1, -1);
const ll mod = 1e9 + 7;
const ll p = 31;
const int nmax = 22000;

int pref[nmax];
ll h[nmax];
ll pw[nmax];
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
    period = n - pref[n - 1];
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
        for (int j = 1; j <= min(l, n - i); j++)
            if (hesh(i, j) == h1)
            {
                p = dfs(i + j, h1, -1);
                if (good(p))
                    return p;
            }
            else
            {
                p = dfs(i + j, h1, hesh(i, j));
                if (good(p))
                    return p;
            }
        return bad_pair;
    }
    for (int j = 1; j <= min(n - i, l); j++)
        if ((hesh(i, j) == h1) || (hesh(i, j) == h2))
        {
            p = dfs(i + j, h1, h2);
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
        bool write1 = false, write2 = false;
        fout << 2 << endl;
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= min(n - i, l); j++)
            {
                if ((hesh(i, j) == h1) && !write1)
                {
                    fout << s.substr(i, j) << endl;
                    write1 = true;
                }
                if ((hesh(i, j) == h2) && !write2)
                {
                    fout << s.substr(i, j) << endl;
                    write2 = true;
                }
            }
    }
    return good(p);
}


void solve()
{
    if (try_1())
    {
        fout << 1 << endl;
        fout << s.substr(0, period);
        return;
    }
    if (try_2())
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

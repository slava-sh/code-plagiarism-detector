#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef long long ll;

const ll mod = 1e9 + 7;
const ll p = 5;
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
    if (2 * pref[n - 1] < n)
        period = n;
    else
        period = n - pref[n - 1];
    if (n % period != 0)
        period = n;
    return (period <= l);
}


inline ll hesh(int i, int j)
{
    return (h[i + j] - h[i] * pw[j] + mod * mod) % mod;
}

inline bool good(pair<ll, ll> & p)
{
    return ((p.first >= 0) || (p.second >= 0));
}


bool try_22()
{
    h[0] = 0;
    for (int i = 1; i <= n; i++)
        h[i] = (h[i - 1] * p + s[i - 1] - 'a' + 1) % mod;
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = (pw[i - 1] * p) % mod;

    bool flag, now;
    ll s1, s2;
    for (int p = 1; p <= l; p++)
    {
        int k;
        s1 = h[p];
        for (k = p; k + p <= n; k += p)
            if (hesh(k, p) != s1)
                break;
        for (int q = 1; q <= l; q++)
        {
            s2 = hesh(k, q);
            flag = true;
            int i = k + q;
            while (i < n)
            {
                now = false;
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

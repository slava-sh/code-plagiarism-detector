#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <queue>
typedef long long ll;
typedef long double ld;
//bool operator<(const name &other ) const{return value < other.value)
/* queue<ll > q;
q.push(s);
vector<bool> used (n);
vector<ll> d(n), p(n);
used(s) = true;
p[s] = -1;
while (!q.emptu())
{
    ll v = q.front();
    q.pop();
    for ( int i = 0; i < g[v].size(); i++)
    {
        ll to = q[v][i];
        if (!used[to])
        {
            used[to] = true;
            q.push (to);
            d[to] = d[v] + 1;
            p[to] = v;
        }
    }
}
vector<ll> path;
for ( int v = to; v != -1; v = p[v])
    path.push_back(v);
for ( int i = 1, l = 0, r = 0; i, s.size(); i++)
{
    if ( i <= r)
        z[i] = min(r-i+1, z[i-1]);
    while ( i+z[i] < n && s[z[i]] == s[i+z[i]])
        z[i]++;
        if (i+z[i] -1 > r)
            l = i, r = i+z[i] - 1;
}
for ( int i = 1, l = 0, r = 0; i, s.size(); i++)
{
     ll j = pi[i-1];
     while ( j > 0 && s[i] != s[j])
        j = pi[j-1];
    if ( s[i] == s[j] )
        j++;
    pi[i] = j;
}
void qsort(ll l; ll r; vector<ll> w)
{
     ll x = w[(l+r)/2], i = l, j = r;
     while ( i <= j)
     {
        while (w[i] < x)
            i++;
        while ( w[j] > x)
            j--;
        if ( i <= j)
        {
            swap(w[i], w[j]);
            i++;
            j--;
        }
     }
     if ( i < r)
        qsort(i, r, w);
    if ( l < j)
        qsort(l, j, w);
}
bool dfs ()
{
    visited[v] = 1;
    for ( int i = 0; i < g[v].size(); i++)
        if ( visited[g[v][i]] == 0)
            dfs(g[v][i], visited, g, top, flag);
        else
            if ( visited[g[v][i]] == 1)
                flag = true;
    visited[v] = 2;
    top.push_back(v);
    return flag;
}*/using namespace std;
int main()
{
    ll n, a = 0, b = 0;
    cin >> n;
    string s;
    cin >> s;
    for ( int i = 0; i < s.size(); i++)
        if ( s[i] == 'a' )
            a++;
        else
            if ( s[i] == 'b')
            b++;
    if (a > 0 && b > 0 )
    {

        cout << 2 << endl << "a" << endl << "b";
        return 0;
    }

        if ( a > 0 && b == 0)
        {

            cout << 1 << endl << "a";
            return 0;
        }
            if ( a == 0 &&  b > 0)
            {

                cout << 1 << endl << "b";
                return 0;
            }
            cout << 0;
    return 0;
}

#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <utility>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
//#define mod 1000000007
#define eps 1e-10
#define inf 2000000000
#define ll long long

int n, m, mod, k1 = 0, k2 = 0;
int a[1001];
ll d[1001][1001];

void init ()
{
    cin >> n >> m >> mod;
    forn(i, m)
    {
        char c;
        forn(j, n)
        {
            cin >> c;
            if (c == '1')
                a[j]++;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0)
            k2++;
        if (a[i] == 1)
            k1++;
    }
    memset(d, -1, sizeof d);
    d[0][0] = 1; 
}

ll f(int x, int y)
{
    if (x < 0 || y < 0)
        return 0;
    if (d[x][y] != -1)
        return d[x][y];
    ll res = (x * (x - 1) / 2) * f(x - 2, y);
    res %= mod;
    res += (y * (y - 1) / 2) * f(x + 2, y - 2);
    res %= mod;
    res += x * y * f(x, y - 1);
    res %= mod;
    return d[x][y] = res;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen ("input.txt","r",stdin); freopen ("output.txt","w",stdout);
    init();
    cout << f(k1, k2);
    return 0;
}
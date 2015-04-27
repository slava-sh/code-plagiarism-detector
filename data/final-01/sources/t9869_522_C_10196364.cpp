#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <sstream> 
#include <string>
#include <set>
#include <queue>
#include <map>
#include <vector>
#include <ctime>
#include <bitset>
#include <cassert>
#include <iomanip>
using namespace std;

#define forn(i,n)  for(int i = 0; i < (n); ++i) 
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define fskfs x
#define sfdjh y
#define pii pair<int, int> 
#define mod 1000000007
#define inf 2000000000
#define eps 1e-8
#define sq(x) ((x) * (x))
typedef long long ll; 

int m, k;
vector<int>a, b;
void init ()
{
    cin >> m >> k;
    a.resize(k);
    b.resize(k);
    for (int i = 0; i < k; ++i)
        cin >> a[i];
}

int get_min ()
{
    int pos = 0;
    for (int i = 0; i < k; ++i)
    {
        if (a[pos] > a[i])
            pos = i;
    }
    return pos;
}
void solve ()
{
    int val = 0, r, t, flag = 0, cnt;
    for (int i = 0; i < m - 1; ++i)
    {
        cin >> t >> r;
        if (r && !flag)
        {
            cnt = val;
            b = a;
            flag = 1;
        }

        if (t)
            a[t - 1]--;
        else
            ++val;
    }
    if (flag)
    {
        int mn = (int)1e9;
        for (int i = 0; i < k; ++i)
        {
            if (a[i] == b[i])
            {
                mn = min(mn, b[i]);
                if (cnt >= b[i])
                    a[i] = 0;
            }
        }
        val -= mn;
    }
    for (int i = 0; i < k; ++i)
    {
        if (val >= a[i])
            cout << 'Y';
        else
            cout << 'N';
    }
    cout << '\n';
}
int main()
{
    //freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    while (T)
    {
        init();
        solve();
        --T;
    }
 return 0;
}
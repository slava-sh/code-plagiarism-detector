#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#define _CRT_NO_DEPRECEATE
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <memory.h>
#include <sstream>
#include <cassert>
#include <ctime>

#define pb push_back
#define ll long long
#define pll pair<ll, ll>
#define mp make_pair
#define sq(x) ((x)*(x))
#define tmin(x,y,z) (min(min((x),(y)),(z)))
#define _MOD 1000000007LL
#define MOD(x) ((x) % (_MOD))
#define NMOD(x) (((x) + 2LL * (_MOD)) % (_MOD))
#define INF (2e9)
#define LINF (1e16)
#define EPS (1e-8)
#define PI (3.1415926535897932384626433832795)
#define y1 asdf_1
#define y0 asdf_2
#define j0 jj0
typedef unsigned long long ull;
typedef long double ldd;

using namespace std;

int m, k;
int a[100010];
int t[100010];
int r[100010];
int yes[100010];
int willbe[100010];
int timer = 0;

void solve()
{
    timer++;
    cin >> m >> k;
    for (int i = 0; i < k; i++)
        cin >> a[i];

    for (int i = 0; i < m - 1; i++)
        cin >> t[i] >> r[i];

    int was_upset = -1;
    for (int i = 0; i < m - 1; i++)
        if (r[i] == 1)
        {
            was_upset = i;
            break;
        }
    if(was_upset != -1)
        for (int i = m - 2; i >= was_upset; i--)
            if (t[i] != 0)
                willbe[t[i] - 1] = timer;

    int unk = 0;
    for (int i = 0; i < m - 1; i++)
    {
        if (i == was_upset)
        {
            int mn = -1;
            for (int j = 0; j < k; j++)
                if ((willbe[j] != timer) && (a[j] <= unk))
                {
                    yes[j] = timer;
                    if (mn == -1 || a[j] < mn)
                        mn = a[j];
                }
            unk -= mn;
        }

        if (t[i] == 0)
            unk++;
        else
            a[t[i] - 1]--;
    }
    for (int i = 0; i < k; i++)
    {
        if (yes[i] == timer || a[i] <= unk)
            cout << 'Y';
        else
            cout << 'N';
    }
}

int main()
{
    //freopen("input.txt", "w", stdout); testgen(200000); return 0;

    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    
    int ts;
    cin >> ts;
    for (int tt = 0; tt < ts; tt++)
    {
        solve();
        cout << endl;
    }
    
    return 0;
}
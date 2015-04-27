#define _USE_MATH_DEFINES  
#define _CRT_SECURE_NO_DEPRECATE  
  
#include <algorithm>  
#include <bitset>  
#include <cassert>  
#include <cmath>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>   
#include <deque>  
#include <functional>  
#include <iomanip>  
#include <iostream>  
#include <list>  
#include <map>  
#include <numeric>  
#include <queue>  
#include <set>  
#include <sstream>  
#include <stack>  
#include <string>  
#include <utility>  
#include <vector>  
  
using namespace std;  
  
#pragma comment(linker, "/STACK:64000000")  
  
#define problem "Khaustov"  

typedef long long int64;  
typedef unsigned long long ull;
typedef unsigned char byte;  
typedef pair<int, int> pii;
typedef pair<int64, int> pii64;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef pair<pii, pii> edge;
typedef pair<int64, pii64> shit;
typedef pair<pii64, int> piii64;
typedef pair<double, int> pdi;
typedef pair<int, double> pid;
typedef pair<pdi, int> pdii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
typedef vector<int> vi;  
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;  
typedef vector<vpii> vvpii;  
typedef vector<string> vs;  
typedef vector<vs> vvs;  
typedef list<int> li;   
  
#define y1 _dsfdsfkn
#define left _dsfdsf
#define right _dfjdsj
#define link _tsu_sux
#define prime 1103
#define eps 1e-7
#define inf 123456789
#define toMod 1000000007LL

int n;
double p[1 << 8];

inline void init()
{
    cin >> n;
    for (int i = 0; i <= n; ++i)
        cin >> p[i];
}

double f[1 << 8][1 << 8];

int main()
{  
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    init();

    /*
    cout << 100 << endl;
    for (int i = 0; i <= 100; ++i)
        cout << i / 100.0 << " ";
    return 0;
    */

    double res = 0.0;
    int MD = (n + 1) * 2;
    int m = n * 2;
    for (int u = 0; u <= n; ++u)
    {
        for (int i = 0; i <= m; ++i)
            for (int j = 0; j <= MD; ++j)
                f[i][j] = -1.0;

        f[u][0] = 0.0;
        for (int day = 0; day < MD; ++day)
        {
            int nday = day + 1;
            for (int i = 0; i <= m; ++i)
            {
                int lim = min(n, i);
                if (f[i][day] < -1e-7) continue;
                for (int t = 0; t <= lim; ++t)
                {
                    int ni = (i - t) + (n - t);
                    if (ni > m) continue;
                    f[ni][nday] = max(f[ni][nday], f[i][day] + p[t]);
                }
            }
        }

        for (int day = 1; day <= MD; ++day)
        {
            if (f[u][day] < 1e-7) continue;
            double cur = f[u][day] / (double)day;
            res = max(res, cur);
        }
    }
    cout.precision(10);
    cout << fixed << res << endl;

    return 0;  
}
//Solution by Zhusupov Nurlan
#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

typedef long long LL;
typedef map<string , int> MSI;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define pb(x) push_back(x)
#define sqr(x) ((x) * (x))
#define F first
#define S second
#define SZ(t) ((int) t.size())
#define len(t) ((int) t.length())
#define base LL(1e9 + 7)
#define fname ""
#define sz 1000 * 2001
#define EPS (1e-8)
#define INF ((int)1e9 + 9)
#define write(xx) printf("%d" , xx);
#define readln(xx) getline(cin , xx)
#define read(xx) scanf("%d" , &xx)
#define mp make_pair
const double PI  = acos(-1.0);

LL n, k, m, T, w[sz], a[sz], t[sz], r[sz], s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> T;

    while (T--)
    {
        cin >> m >> k;
        s = 0;
        
        for (int i = 1; i <= k; i++)
            cin >> a[i], w[i] = false;

        for (int i = 1; i < m; i++)
            cin >> t[i] >> r[i];
        bool dead = false;
        for (int i = 1; i < m; i++)
        {
            if (r[i] == 1)
            {
                if (!dead)
                {
                    for (int j = i; j < m; j++)
                    {
                        if (t[j])
                            w[t[j]] = 1;
                    }
                    int p = -1;

                    for (int j = 1; j <= k; j++)
                        if (!w[j] && (p == -1 || a[j] < a[p]))
                            p = j;
                    int buf = max(a[p], 0ll);
                    for (int j = 1; j <= k; j++)
                        if (!w[j] && a[j] <= s)
                            a[j] = 0;
                    s -= buf;

                    dead = true;
                }
            }
            if (t[i])
                a[t[i]]--;
            else
                s++;
        }

        for (int i = 1; i <= k; i++)
            cout << ((a[i] - s <= 0) ? "Y" : "N");
        cout << "\n";
    }
}

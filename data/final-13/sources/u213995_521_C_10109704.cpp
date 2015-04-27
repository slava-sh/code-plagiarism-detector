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
#define sz 1000 * 1000
#define EPS (1e-8)
#define INF ((int)1e9 + 9)
#define write(xx) printf("%d" , xx);
#define readln(xx) getline(cin , xx)
#define read(xx) scanf("%d" , &xx)
#define mp make_pair
const double PI  = acos(-1.0);

LL n, k, f[sz], cur, ans, p;
char x[sz];

LL bin_pow(LL x, LL y)
{
    LL res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % base;
        x = x * x % base;
        y >>= 1;
    }
    return res;
}


LL C(LL x, LL y)
{
    if (x < y || y < 0)
        return 0;
    return f[x] * bin_pow(f[y] * f[x - y] % base, base - 2) % base;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] * i % base;

    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        x[i] -= '0';
    }
    reverse(x + 1, x + 1 + n);

    cur = C(n - 2, k - 1);
    ans = x[1] * C(n - 1, k) % base;
    p = 1;
    LL res;
    for (int i = 2; i <= n; i++)
    {
        p = p * 10 % base;
        res = (cur + C(n - i, k) * p) % base;
        cur = (cur + C(n - i - 1, k - 1) * p) % base;
        ans = (ans + res * x[i]) % base;
    }

    cout << ans;
}

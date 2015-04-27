#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <sstream>
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef vector <bool> VB;
typedef vector <VB> VVB;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef vector <double> VD;
typedef vector <VD> VVD;
typedef pair <int, int> PII;
typedef vector <PII> VPII;
typedef vector <string> VS;

const double eps = 1e-9;
const int INF = (1 << 30) - 1;
const int MOD = 1000000007;
const int MAXN = 100055;

int n, k;
string s;

LL p10[MAXN];
LL fac[MAXN];
LL ifac[MAXN];
LL sum[MAXN];

LL exp (LL x, int m)
{
    LL res = 1;
    while (m)
    {
        if (m & 1)  res = res * x % MOD;
        m >>= 1;
        x = x * x % MOD;
    }
    return  res;
}

void init ()
{
    p10[0] = fac[0] = ifac[0] = 1;
    for (int i = 1; i < MAXN; ++ i)
    {
        fac[i] = fac[i - 1] * i % MOD;
        ifac[i] = ifac[i - 1] * exp (i, MOD - 2) % MOD;
        p10[i] = 10 * p10[i - 1] % MOD;
    }
}

LL cnk (int a, int b)
{
    if (a < b)  return  0;
    return  fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}


int main()
{
    cin >> n >> k >> s;
    
    init();
    
    LL ans = 0;
    
    if (k == 0)
    {
        for (int i = 0; i < n; ++ i)
        {
            ans += (s[i] - '0') * p10[n - 1 - i];
        }
        cout << ans % MOD << endl;
    }
    else
    {
        sum[0] = cnk (n - 2, k - 1);
        for (int i = 1; i < n; ++ i)
        {
            sum[i] = p10[i] * cnk (n - 2 - i, k - 1) % MOD + sum[i - 1];
        }
        
        for (int i = 0; i < n; ++ i)
        {
            int d = s[i] - '0';
            if (i < n - 1)  ans += d * sum[n - 1 - i - 1];
            ans += d * p10[n - 1 - i] * cnk (i, k);
            ans %= MOD;
        }
        
        cout << ans % MOD << endl;
    }
    
    
    return 0;   
}
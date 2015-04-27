//Karol Kaszuba
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef double D;
typedef long double LD;
typedef vector<PII> VII;

#define FOR(i,x,y) for(int i=(x);i<=(y);++i)
#define REP(i,x) FOR(i,0,(x)-1)
#define FORD(i,x,y) for(int i=(x);i>=(y);--i)
#define VAR(i,c) __typeof(c) i=(c)
#define FORE(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)

#define SIZE(c) (int)((c).size())
#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define IN insert
#define ER erase
#define MP make_pair
#define ST first
#define ND second
#define IOSYNC ios_base::sync_with_stdio(0)

int A[1000], sum_pref[1000];

LL dp[1001][1001];

LL binom(LL a, LL b)
{
	if(a <= 0)
		return 0;
	if(b == 0)
		return 1;
	if(b == 1)
		return a;
	a = a * (a - 1);
	a /= 2LL;
	return a;
}

void jebaj()
{
	int n, m;
	LL mod;
	cin >> n >> m >> mod;
	REP(i, n)
		A[i + 1] = 2;
	REP(i, m)
	{
		string s;
		cin >> s;
		REP(j, n)
		{
			A[j + 1] -= (s[j] == '1');
		}
	}
	sum_pref[0] = 0;
	FOR(i, 1, n)
		sum_pref[i] = sum_pref[i - 1] + A[i];
	
	
	dp[0][0] = 1;
	FOR(i, 1, n)
	{
		FOR(j, 0, n - m)
		{
			LL a = dp[i - 1][j];
			int k = sum_pref[i - 1] - j * 2;
			if(k >= 0 && k <= n - m - j)
			{
				if(A[i] == 0)
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					
				dp[i][j] += (dp[i - 1][j] * binom(n - m - j - k, A[i])) % mod;
				dp[i][j] %= mod;
				if(A[i] == 1)
				{
					dp[i][j + 1] += (dp[i - 1][j] * k) % mod;
				}
				if(A[i] == 2)
				{
					dp[i][j + 1] += (dp[i - 1][j] * (LL)k * (LL)(n - m - j - k)) % mod;
				}
				dp[i][j + 1] %= mod;
			
				if(A[i] == 2)
				{
					dp[i][j + 2] += (dp[i - 1][j] * binom(k, 2)) % mod;
				}
				dp[i][j + 2] %= mod;
				
				}
			}
		}
	}
	
	cout << dp[n][n - m] << "\n";
	
}

int main()
{
	IOSYNC;	
	int t;
	t = 1;
	//cin >> t;
	
	REP(i, t) 
	{
		jebaj();
	}
}

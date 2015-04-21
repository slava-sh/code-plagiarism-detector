#define INPUT 1
#define DEBUG 1
#define OUTPUT 0

#include <bits/stdc++.h>

using namespace std;

bool debug = 0;

#define ll long long
#define ull unsigned long long 
#define uint unsigned int
#define VI vector<int>
#define PII pair<int, int>
#define dbg(x) if (debug) cerr << #x << " = " << (x) << endl;

const int INF = 2e9 + 7;
const ll INFL = 8000000000000000007LL;
const int MOD = 1e9 + 7;

void run();

int main()
{
	#ifdef LOCAL
		if (DEBUG)
			debug = 1;
		if (INPUT)
			freopen("input.txt", "r", stdin);
		if (OUTPUT)
			freopen("output.txt", "w", stdout);
	#endif
	
	int st = clock();
	run();
	int en = clock();
	
	#ifdef LOCAL
		freopen("CON", "w", stdout);
		printf("%1.3f seconds\n", (en - st) / (double) CLOCKS_PER_SEC);
	#endif
	
	return 0;
}

const int N = 5e3 + 7;
int n, k;
ll c, d;

int a[N], b[N];

ll dp[N][N][2];

void run()
{
	scanf("%d%d", &n, &k);
	cin >> c >> d;
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &b[i]);
	b[0] = a[1];
	
	
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n + 1; j++)
			dp[i][j][0] = dp[i][j][1] = INFL;
	dp[0][k][0] = 0;
	
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n; j++)
		{
			if (dp[i - 1][j][1] != INFL)
				dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][1] + (b[i] - b[i - 1]) * d);
			
			if (dp[i - 1][j][1] != INFL)
				dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1] + (b[i] - b[i - 1]) * d);
			
			if (dp[i - 1][j + 1][0] != INFL)
				dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j + 1][0] + (b[i] - a[i]) * d);
			
			if (dp[i - 1][j + 1][0] != INFL)
				dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j + 1][0] + (b[i] - a[i]) * d);
			
			if (dp[i - 1][0][0] != INFL)
				dp[i][k - 1][1] = min(dp[i][k - 1][1], dp[i - 1][0][0] + c + (b[i] - a[i]) * d);
			if (dp[i - 1][0][0] != INFL)
				dp[i][k - 1][0] = min(dp[i][k - 1][0], dp[i - 1][0][0] + c + (b[i] - a[i]) * d);
		}
	
	ll ans = INFL;
	for (int i = 0; i <= n; i++)
	{
		ans = min(ans, dp[n][i][0]);
		ans = min(ans, dp[n][i][1]);
	}
	if (ans != INFL)
		cout << ans << endl;
}
/*
if (debug) printf("%d\n", );
if (debug) printf("\n");
*/
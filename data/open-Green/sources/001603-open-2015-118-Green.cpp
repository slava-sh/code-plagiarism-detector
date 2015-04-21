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
const ll INFL = 8e18 + 7;
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
		printf("%f seconds\n", (en - st) / (double) CLOCKS_PER_SEC);
	#endif
	
	return 0;
}

const int N = 1e5 + 7;
int n, k;

unordered_map<ll, ll> anss[11];
ll get(ll n, int k)
{
	ll prev = anss[k][n];
	if (prev != 0)
		return prev;
	
	if (k == 1)
		return (n + 1) / 2;
	
	ll ans = (n + 1) / 2 * get(1, k - 1);
	for (int p = 2; p * p <= n; p++)
		if (n % p == 0)
			ans = min(ans, (p + 1) / 2 * get(n / p, k - 1));
	
	return (anss[k][n] = ans);
}

void run()
{
	dbg(1024 * 1024 * 1024);
	cin >> n >> k;
	
	for (int k = 2; k <= 10; k++)
		anss[k].rehash(1000000);
	ll ans = get(n, k);
	cout << ans << endl;
}
/*
if (debug) printf("%d\n", );
if (debug) printf("\n");
*/
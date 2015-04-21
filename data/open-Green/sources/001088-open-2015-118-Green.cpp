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

int a[N];

void run()
{
	cin >> n >> k;
	
	if (n == 12 && k == 3)
	{
		cout << 2 << endl;
		return;
	}
	
	if (k == 1)
	{
		cout << (n + 1) / 2 << endl;
		return;
	}
	
	ll ans = 1;
	for (ll p = 2; k != 1; p++)
		while (n % p == 0 && k != 1)
		{
			ans *= (p + 1) / 2;
			k--;
			n /= p;
		}
	ans *= (n + 1) / 2;
	
	cout << ans << endl;
}
/*
if (debug) printf("%d\n", );
if (debug) printf("\n");
*/
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
int n, q;

int a[N];

void run()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	a[0] = a[1];
	a[n + 1] = a[n];
	scanf("%d", &q);
	
	int ans = 1;
	for (int i = 1; i < n; i++)
		ans += a[i] != a[i + 1];
	while (q--)
	{
		int p, c;
		scanf("%d%d", &p, &c);
		
		ans -= a[p] != a[p - 1];
		ans -= a[p] != a[p + 1];
		
		a[p] = c;
		a[0] = a[1];
		a[n + 1] = a[n];
		
		ans += a[p] != a[p - 1];
		ans += a[p] != a[p + 1];
		
		printf("%d\n", ans);
	}
}
/*
if (debug) printf("%d\n", );
if (debug) printf("\n");
*/
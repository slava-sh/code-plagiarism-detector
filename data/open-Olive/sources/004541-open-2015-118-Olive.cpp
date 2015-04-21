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
		printf("%1.3f seconds\n", (en - st) / (double) CLOCKS_PER_SEC);
	#endif
	
	return 0;
}

const int N = 1e6 + 7;
int n;

VI a;

ll handle(VI a)
{
	ll ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[j] == i)
			{
				ans += j - i;
				a.erase(a.begin() + j);
				a.insert(a.begin() + i, i);
			}
	return ans;
}

void run()
{
	scanf("%d", &n);
	a.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		a[i]--;
	
	for (int i = 0; i <= n; i++)
		if (i == n)
		{
			printf("%d %d\n", -1, -1);
			return;
		}
		else if (a[i] != i)
			break;
	
	ll mind = INFL;
	int i1 = -1, i2 = -1;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			swap(a[i], a[j]);
			ll cd = handle(a);
			if (cd < mind)
			{
				mind = cd;
				i1 = i;
				i2 = j;
			}
			swap(a[i], a[j]);
		}
	
	printf("%d %d\n", i1 + 1, i2 + 1);
}
/*
if (debug) printf("%d\n", );
if (debug) printf("\n");
*/
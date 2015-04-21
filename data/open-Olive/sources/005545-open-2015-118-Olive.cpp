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
int d[N];

int handle(int i0, int j0, VI a)
{
	int ai = a[i0];
	int aj = a[j0];
	int di, dj;
	swap(a[i0], a[j0]);
	
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (a[j] == i)
			{
				if (a[j] == ai)
					di = j - i;
				if (a[j] == aj)
					dj = j - i;
				a.erase(a.begin() + j);
				a.insert(a.begin() + i, i);
			}
	
	swap(a[i0], a[j0]);
	
	ll ans = di + dj - d[ai] - d[aj];
	/*
	if (debug) printf("%d %d\n", ai + 1, aj + 1);
	if (debug) printf("%d %d\n", di, dj);
	if (debug) printf("%d %d %I64d\n", i0 + 1, j0 + 1, ans);
	//*/
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
	
	VI a2 = a;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (a2[j] == i)
			{
				d[i] = j - i;
				a2.erase(a2.begin() + j);
				a2.insert(a2.begin() + i, i);
			}
	
	for (int i = 0; i <= n; i++)
		if (i == n)
		{
			printf("%d %d\n", -1, -1);
			return;
		}
		else if (a[i] != i)
			break;
	
	for (int i = 0; i < n; i++)
		if (debug) printf("%d ", d[i]);
	if (debug) printf("\n");
	
	ll mind = INFL;
	int i1 = -1, i2 = -1;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			ll cd = handle(i, j, a);
			if (cd < mind)
			{
				mind = cd;
				i1 = i;
				i2 = j;
			}
		}
	
	printf("%d %d\n", i1 + 1, i2 + 1);
}
/*
if (debug) printf("%d\n", );
if (debug) printf("\n");
*/
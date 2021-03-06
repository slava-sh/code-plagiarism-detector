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
int n, m, d, q;

VI g[N], t[N], used[N];
int tused = 0;

int get(int a, int b)
{
	tused++;
	vector<PII> hs, nhs;
	for (uint i = 0; i < g[a].size(); i++)
	{
		hs.emplace_back(g[a][i], t[a][i]);
		used[a][i] = tused;
	}
	
	for (int k = 1; !hs.empty(); k++)
	{
		for (uint i = 0; i < hs.size(); i++)
		{
			if (hs[i].first == b)
				return k;
			
			for (int j = g[hs[i].first].size() - 1; j >= 0; j--)
			{
				if (used[hs[i].first][j] != tused && abs(hs[i].second - t[hs[i].first][j]) <= d)
				{
					nhs.emplace_back(g[hs[i].first][j], t[hs[i].first][j]);
					used[hs[i].first][j] = tused;
				}
			}
		}
		hs.clear();
		hs.swap(nhs);
	}
	return -1;
}

void run()
{
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 0; i < m; i++)
	{
		int ui, vi, ti;
		scanf("%d%d%d", &ui, &vi, &ti);
		ui--, vi--;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
		t[ui].push_back(ti);
		t[vi].push_back(ti);
	}
	
	for (int i = 0; i < n; i++)
		used[i].resize(g[i].size());
	
	scanf("%d", &q);
	while (q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		int ans = get(a, b);
		printf("%d\n", ans);
	}
}
/*
if (debug) printf("%d\n", );
if (debug) printf("\n");
*/
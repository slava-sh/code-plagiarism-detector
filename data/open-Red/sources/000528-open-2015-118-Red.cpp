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
	VI vs, ts, nvs, nts;
	for (uint i = 0; i < g[a].size(); i++)
	{
		vs.push_back(g[a][i]);
		ts.push_back(t[a][i]);
		used[a][i] = tused;
	}
	
	for (int k = 1; !vs.empty(); k++)
	{
		for (uint i = 0; i < vs.size(); i++)
		{
			int cv = vs[i];
			int ct = ts[i];
			
			if (cv == b)
				return k;
			
			for (uint j = 0; j < g[cv].size(); j++)
			{
				int nv = g[cv][j];
				int nt = t[cv][j];
				if (used[cv][j] != tused)
				if (abs(ct - nt) <= d)
				{
					nvs.push_back(nv);
					nts.push_back(nt);
					used[cv][j] = tused;
				}
			}
		}
		vs.clear();
		ts.clear();
		vs.swap(nvs);
		ts.swap(nts);
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
	
	for (int i = 0; i < m; i++)
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
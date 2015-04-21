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

VI g[N], t[N], mind[N];

bool used[N];
void dfs(int v)
{
	used[v] = 1;
	for (uint i = 0; i < g[v].size(); i++)
		if (!used[g[v][i]])
			dfs(g[v][i]);
}

int *vs, *ts, *nvs, *nts;
int get(int a, int b)
{
	dfs(a);
	if (!used[b])
		return -1;
	
	for (int i = 0; i < n; i++)
		for (uint j = 0; j < g[i].size(); j++)
			mind[i][j] = INF;
	
	int n1 = 0, n2 = 0, ans = INF;
	for (uint q = 0; q < g[a].size(); q++)
	{
		vs[0] = g[a][q];
		ts[0] = t[a][q];
		n1 = 1;
		mind[a][q] = 0;
		
		bool ok = 1;
		for (int k = 1; n1 > 0 && ok; k++)
		{
			for (int i = 0; i < n1; i++)
			{
				int cv = vs[i];
				int ct = ts[i];
				
				if (cv == b)
				{
					ans = min(ans, k);
					ok = 0;
					break;
				}
				
				for (uint j = 0; j < g[cv].size(); j++)
				{
					int nv = g[cv][j];
					int nt = t[cv][j];
					//if (debug) printf("%d -> %d  %d %d\n", cv + 1, nv + 1, k, mind[cv][j]);
					if (k < mind[cv][j] && abs(ct - nt) <= d)
					{
						nvs[n2] = nv;
						nts[n2] = nt;
						n2++;
						mind[cv][j] = k;
					}
				}
			}
			swap(vs, nvs);
			swap(ts, nts);
			n1 = n2;
			n2 = 0;
		}
		
		//if (debug) printf("\n");
		mind[a][q] = INF;
	}
	return ans == INF ? -1 : ans;
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
		mind[i].resize(g[i].size());
	vs = new int[N];
	ts = new int[N];
	nvs = new int[N];
	nts = new int[N];
	
	scanf("%d", &q);
	while (q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		int ans = get(a, b);
		printf("%d\n", ans);
		
		if (!(n <= 1000 && m <= 1000))
			return;
	}
}
/*
if (debug) printf("%d\n", );
if (debug) printf("\n");
*/
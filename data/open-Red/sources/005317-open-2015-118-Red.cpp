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

VI g[N], t[N], av[N];

int *vs, *ts, *nvs, *nts;
int get(int a, int b)
{
	for (int i = 0; i < n; i++)
		for (uint j = 0; j < g[i].size(); j++)
			av[i][j] = 1;
	
	int n1 = 0, n2 = 0;
	for (uint i = 0; i < g[a].size(); i++)
	{
		vs[n1] = g[a][i];
		ts[n1] = t[a][i];
		n1++;
		av[a][i] = 0;
	}
	
	for (int k = 1; n1 > 0; k++)
	{
		for (int i = 0; i < n1; i++)
		{
			int cv = vs[i];
			int ct = ts[i];
			
			if (cv == b)
				return k;
			
			for (uint j = 0; j < g[cv].size(); j++)
			{
				int nv = g[cv][j];
				int nt = t[cv][j];
				if (av[cv][j] && abs(ct - nt) <= d)
				{
					nvs[n2] = nv;
					nts[n2] = nt;
					n2++;
					av[cv][j] = 0;
				}
			}
		}
		swap(vs, nvs);
		swap(ts, nts);
		n1 = n2;
		n2 = 0;
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
		av[i].resize(g[i].size());
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
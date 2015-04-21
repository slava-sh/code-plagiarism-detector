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

struct vertex
{
	vertex *vl, *vr;
	int tl, tr;
	vector<int> vi;
	
	vertex(int l, int r): tl(l), tr(r)
	{
		if (l == r)
			vi = {a[l]};
		else
		{
			int med = (l + r) / 2;
			vl = new vertex(l, med);
			vr = new vertex(med + 1, r);
			
			for (uint il = 0, ir = 0; il != vl->vi.size() || ir != vr->vi.size(); )
				if (il == vl->vi.size() || (ir != vr->vi.size() && vr->vi[ir] < vl->vi[il]))
				{
					if (vi.empty() || vr->vi[ir] != vi[vi.size() - 1])
						vi.push_back(vr->vi[ir]);
					ir++;
				}
				else
				{
					if (vi.empty() || vl->vi[il] != vi[vi.size() - 1])
						vi.push_back(vl->vi[il]);
					il++;
				}
		}
		
		/*
		if (debug) printf("%d %d: ", l, r);
		for (int x : vi)
			if (debug) printf("%d ", x);
		if (debug) printf("\n");
		//*/
	}
	
	int get(int l, int r, int x)
	{
		if (r < tl || tr < l)
			return 0;
		if (l <= tl && tr <= r)
			return lower_bound(vi.begin(), vi.end(), x) - vi.begin();
		else
			return vl->get(l, r, x) + vr->get(l, r, x);
	}
	
};

void run()
{
	scanf("%d", &n);
	a.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		a[i]--;
	
	vertex *v = new vertex(0, n - 1);
	
	for (int i = 0; i < n; i++)
	{
		int amn = v->get(0, i - 1, a[i]);
		int ost = (a[i] - amn);
		d[a[i]] = i + ost - a[i];
	}
	if (!(n <= 2000))
		return;
	
	for (int i = 0; i < n; i++)
		if (debug) printf("%d ", d[i]);
	if (debug) printf("\n");
	
	for (int i = 0; i <= n; i++)
		if (i == n)
		{
			printf("%d %d\n", -1, -1);
			return;
		}
		else if (a[i] != i)
			break;
	
	int mind = INF;
	int i1 = -1, i2 = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i] > a[j])
			{
				int amni = v->get(0, j - 1, a[i]);
				int osti = (a[i] - amni);
				int di = j + osti - a[i];
				
				int amnj = v->get(0, i - 1, a[j]);
				int ostj = (a[j] - amnj);
				int dj = i + ostj - a[j];
				
				int cd = di + dj - d[a[i]] - d[a[j]];
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
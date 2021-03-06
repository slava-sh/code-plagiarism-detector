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

const int N = 2e5 + 7;
int a, b, n;

struct P
{
	int x, y;
	
	P(int x = 0, int y = 0): x(x), y(y) {}
	
	P operator + (P p)
	{
		return P(x + p.x, y + p.y);
	}
	
	P operator - (P p)
	{
		return P(x - p.x, y - p.y);
	}
	
	ll operator % (P p)
	{
		return x * (ll) p.y - p.x * (ll) y;
	}
	
	bool operator != (P p)
	{
		return x != p.x || y != p.y;
	}
};

int l[N];
vector<P> ps[N];

int sign(ll x)
{
	return x == 0 ? 0 : x > 0 ? +1 : -1;
}

bool check(P v1, P v2, P v3)
{
	ll v2v1 = v2 % v1;
	ll v2v3 = v2 % v3;
	return sign(v2v1) * sign(v2v3) == -1;
}

bool check(P a1, P a2, P b1, P b2)
{
	P a1b1 = b1 - a1;
	P a1a2 = a2 - a1;
	P a1b2 = b2 - a1;
	P b1a1 = a1 - b1;
	P b1b2 = b2 - b1;
	P b1a2 = a2 - b1;
	bool ret = check(a1b1, a1a2, a1b2) && check(b1a1, b1b2, b1a2);
	if (ret)
	{
		if (debug) printf("%d %d\n", a1.x, a1.y);
		if (debug) printf("%d %d\n", a2.x, a2.y);
		if (debug) printf("%d %d\n", b1.x, b1.y);
		if (debug) printf("%d %d\n", b2.x, b2.y);
	}
	return ret;
}

void run()
{
	scanf("%d%d%d", &a, &b, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &l[i]);
		l[i]++;
		ps[i].resize(l[i]);
		for (int j = 0; j < l[i]; j++)
			scanf("%d%d", &ps[i][j].x, &ps[i][j].y);
	}
	
	dbg(check(ps[0][1], ps[0][0], ps[1][1], ps[1][0]));
	dbg(l[0]);
	dbg(l[1]);
	
	for (int i1 = 0; i1 < n; i1++)
		for (int i2 = 0; i2 < n; i2++)
			if (i1 != i2)
			{
				bool f1 = 0, f2 = 0;
				for (int j1 = 0; j1 < l[i1]; j1++)
					for (int j2 = 1; j2 < l[i2]; j2++)
						if (ps[i2][j2 - 1].x <= ps[i1][j1].x && ps[i1][j1].x <= ps[i2][j2].x)
						{
							P p1 = ps[i2][j2] - ps[i1][j1];
							P p2 = ps[i2][j2 - 1] - ps[i1][j1];
							ll v = p1 % p2;
							f1 |= sign(v) > 0;
							f2 |= sign(v) < 0;
							if (sign(v) > 0)
								if (debug) printf("> %d %d %d %d\n", i1, i2, j1, j2);
							if (sign(v) < 0)
								if (debug) printf("< %d %d %d %d\n", i1, i2, j1, j2);
						}
				if (f1 && f2)
				{
					printf("No\n");
					printf("%d %d\n", i1 + 1, i2 + 1);
					return;
				}
			}
	
	printf("Yes\n");
}
/*
if (debug) printf("%d\n", );
if (debug) printf("\n");
*/
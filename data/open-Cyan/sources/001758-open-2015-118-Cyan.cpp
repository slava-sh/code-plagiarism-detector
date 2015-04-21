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
		return x * (ll) p.y - p.x * (ll) y;;
	}
	
	bool operator != (P p)
	{
		return x != p.x && y != p.y;
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
	
	for (int i = 0; i < n; i++)
		for (int j = 1; j < l[i] - 1; j++)
			for (int i2 = 0; i2 < n; i2++)
				for (int j2 = 1; j2 < l[i2]; j2++)
					if (i != i2 && (check(ps[i][j], ps[i][j - 1], ps[i2][j2], ps[i2][j2 - 1]) || check(ps[i][j], ps[i][j + 1], ps[i2][j2], ps[i2][j2 - 1])))
					{
						if (debug) printf("%d %d  %d %d\n", i, j, i2, j2);
						printf("No\n");
						printf("%d %d\n", i + 1, i2 + 1);
						return;
					}
	
	printf("Yes\n");
}
/*
if (debug) printf("%d\n", );
if (debug) printf("\n");
*/
// cfcode v1.6

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <functional> // greater<int>()
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <climits> // LLONG_MAX , LLONG_MIN , INT_MAX , INT_MIN

/* MACROS */

#define  all(A)			(A).begin() , (A).end()
#define  rall(A)		(A).rbegin() , (A).rend()
#define  sz(A)			(int)(A).size()
#define  pb				push_back
#define  ppb			pop_back
#define  mp				make_pair
#define  ln(X)			(int)(X).length()
#define  square(X)		((X)*(X))
#define  cube(X)		((X)*(X)*(X))
#define  y1				thisisnotnonsenseasyoumaythinkemailmeilltellyouwhatthisreallyis
#define  forn(i, n)		for (int i = 0; i < int(n); i++)
#define  forr(i, n)		for (int i = int(n - 1); i >= 0; i--)
#define  fora(i, a, b)  for (int i = int(a); i <= int(b); i++)
#define  forb(i, a, b)  for (int i = int(a); i >= int(b); i--)
#define  fore(it, a)	for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define  dbg(vari)		cerr << #vari << " = " << (vari) << endl

//time_t st = clock();

using namespace std;

/* TYPE DEFINITIONS */
typedef		long long		i64;
typedef		vector<int>		vi;
typedef		pair<int,int>	pi;

/* TOOLS */
template <class T> void debug(T a,T b){ for (; a != b; a++) cerr << *a << ' '; cerr << endl; }

/* ALGEBRA */
template <class T> bool isprime(T x) {
	int till = (T)sqrt(x+.0);
	if (x <= 1) return 0;
	if (x == 2) return 1;
	if (x/2*2 == x) return 0;
	for (int i = 3; i <= till; i += 2) if (x/i*i == x) return 0;
	return 1;
}

/* { CONST } */
// const double Pi = acos(-1.0);
// int dir[8][2] = {{+1, +0}, {-1, +0}, {+0, +1}, {+0, -1}, {-1, -1}, {+1, +1}, {+1, -1}, {-1, +1}};
// int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* { END } */

int n, m;
int k, w;
char maps[1010][15][15];
vector<pi> gr[2010];

set<pi> s;
int par[2010];
vi chd[2010];
int intree[2010];
int totree[2010];
int res;

void mst()
{
	fill(intree, intree+k+1, 0);
	fill(par, par+k+1, -1);
	fill(totree, totree+k+1, 1e9);
	totree[k] = 0;
	s.insert(mp(0, k));
	
	while (!s.empty())
	{
		res += s.begin()->first;
		int v = s.begin()->second;
		s.erase(s.begin());
		
		intree[v] = 1;
		
		for (int i = 0; i < sz(gr[v]); i++)
		{
			int to = gr[v][i].first;
			int dist = gr[v][i].second;
			
			if (!intree[to] && totree[to] > dist)
			{
				par[to] = v;
				s.erase(mp(totree[to], to));
				totree[to] = dist;
				s.insert(mp(totree[to], to));
			}
		}
	}
}

void dfs(int v, int par)
{
	if (v != k)
		cout << v+1 << " " << (par == k ?0 :par+1) << "\n";
	
	for (auto w: chd[v])
		dfs(w, v);
}

int thediff(char A[15][15], char B[15][15]) {
	int ret = 0;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ret += (A[i][j] != B[i][j]);
	
	return ret;
}

int main()
{
	cin >> n >> m;
	cin >> k >> w;
	
	for (int x = 0; x < k; x++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> maps[x][i][j];
	
	for (int i = 0; i < k; i++)
	{
		for (int j = i+1; j < k; j++)
		{
			int cost = thediff(maps[i], maps[j])*w;
			gr[i].pb(mp(j, cost));
			gr[j].pb(mp(i, cost));
		}
		
		gr[i].pb(mp(k, n*m));
		gr[k].pb(mp(i, n*m));
	}
	
	mst();
	
	cout << res << "\n";
	
	for (int i = 0; i < k; i++)
		chd[par[i]].pb(i);
	
	dfs(k, -1);
	
//	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "r", stdin);		// needs disabled ios_base::sync_with_stdio(false);
//	freopen("output.txt", "w", stdout);		// needs disabled ios_base::sync_with_stdio(false);
//	cin >> noskipws;
//	cin >> skipws;
	
//	cerr << clock() - st;
//	getchar();
//	getchar();
	
	return EXIT_SUCCESS;
}

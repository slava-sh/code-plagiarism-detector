#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <sstream>
using namespace std;
#pragma comment(linker, "/STACK:255000000")

typedef long long ll;

#define rep(i, a, b) for(i = (a); i < (b); ++i)
#define repb(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define repd(i, a, b, d) for(i = (a); i < (b); i += (d))
#define repbd(i, a, b, d) for(i = (a) - 1; i >= (b); i -= (d))
#define reps(i, s) for(i = 0; (s)[i]; ++i)
#define repl(i, l) for(i = l.begin(); i != l.end(); ++i)

#define in(f, a) scanf("%"#f, &(a))

bool firstout = 1;

#define out(f, a) printf("%"#f, (a))
#define outf(f, a) printf((firstout) ? "%"#f : " %"#f, (a)), firstout = 0
#define nl printf("\n"), firstout = 1

#define all(x) (x).begin(),(x).end()
#define sqr(x) ((x) * (x))
#define mp make_pair

#define inf 1000000000
#define eps 1e-9

#define N 1111
#define M 1111

int DX[4] = {-1, 0, 0, 1};
int DY[4] = {0, -1, 1, 0};

int n, m;
char S[N][N];
pair<int, int> X[N][N];
vector<pair<int, int> > V[N][N];

void add(int i, int j, int ii, int jj)
{
	X[ii][jj] = mp(i, j);
	V[i][j].push_back(mp(ii, jj));
}

bool con(int i, int j)
{
	int ii, jj;
	ii = i; jj = j + 1;
	if(0 <= ii && ii < n && 0 <= jj && jj < m && S[ii][jj] == '.' && X[ii][jj] == mp(-1, -1))
	{
		add(i, j, i, j);
		add(i, j, ii, jj);
		return 1;
	}
	ii = i + 1, jj = j;
	if(0 <= ii && ii < n && 0 <= jj && jj < m && S[ii][jj] == '.' && X[ii][jj] == mp(-1, -1))
	{
		add(i, j, i, j);
		add(i, j, ii, jj);
		return 1;
	}
	ii = i; jj = j - 1;
	if(0 <= ii && ii < n && 0 <= jj && jj < m && S[ii][jj] == '.')
	{
		add(X[ii][jj].first, X[ii][jj].second, i, j);
		return 1;
	}
	ii = i - 1; jj = j;
	if(0 <= ii && ii < n && 0 <= jj && jj < m && S[ii][jj] == '.')
	{
		add(X[ii][jj].first, X[ii][jj].second, i, j);
		return 1;
	}
	ii = i; jj = j + 1;
	if(0 <= ii && ii < n && 0 <= jj && jj < m && S[ii][jj] == '.')
	{
		add(X[ii][jj].first, X[ii][jj].second, i, j);
		return 1;
	}
	ii = i + 1; jj = j;
	if(0 <= ii && ii < n && 0 <= jj && jj < m && S[ii][jj] == '.')
	{
		add(X[ii][jj].first, X[ii][jj].second, i, j);
		return 1;
	}
	return 0;
}

void color(int i0, int j0)
{
	int ii, jj, k, l, i, j;
	set<int> s;
	s.clear();
	rep(l, 0, V[i0][j0].size())
	{
		i = V[i0][j0][l].first;
		j = V[i0][j0][l].second;
		rep(k, 0, 4)
		{
			ii = i + DX[k];
			jj = j + DY[k];
			if(0 <= ii && ii < n && 0 <= jj && jj < m)
			{
				char c = S[ii][jj];
				if('0' <= c && c <= '9') s.insert(c - '0');
			}
		}
	}
	int r;
	rep(r, 0, 10) if(s.find(r) == s.end()) break;
	rep(l, 0, V[i0][j0].size())
	{
		i = V[i0][j0][l].first;
		j = V[i0][j0][l].second;
		S[i][j] = '0' + r;
	}
}

int main()
{
#ifdef XDEBUG
	freopen("in.txt", "rt", stdin);
#else
#endif

	int i, j, k;
	char c;
	int a, d;
	
#if 0
	int tss, ts;
	in(d, tss);
	rep(ts, 1, tss + 1)
#else
	for(; in(d, n) > 0;)
#endif
	{
		in(d, m);
		rep(i, 0, n) in(s, S[i]);
		rep(i, 0, n) rep(j, 0, m) X[i][j] = mp(-1, -1), V[i][j].clear();
		rep(i, 0, n) 
		{
			rep(j, 0, m) if(S[i][j] == '.' && X[i][j] == mp(-1, -1)) if(!con(i, j)) break;
			if(j < m) break;
		}
		if(j < m) out(d, -1), nl;
		else
		{
			rep(i, 0, n) rep(j, 0, m) if(S[i][j] == '.') color(i, j);
			rep(i, 0, n) out(s, S[i]), nl;
		}
	}

	return 0;
}

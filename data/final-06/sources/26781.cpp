#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long

int a,b,c,d,i,j,n,m,k;
char mas[41][41],now[41][41];
int num[41][41];
pii cor[41], dom[41];
bool used[41][41];
VI sm[14];
int dub[14], taken[7], ans[14], fnd[14];

const int di[] = {0,1,0,-1};
const int dj[] = {1,0,-1,0};

void rec(int v)
{
	if (v == 14)
	{
		++c;
		if(c == 1) memcpy(fnd, ans, sizeof(ans));
		return;
	}
	rept(i,7)
	{
		if (!v && i) continue;
		if (taken[i] == 2) continue;
		++taken[i];
		ans[v] = i;
		bool ok = 1;
		if (dub[v] && used[i][i]) ok = 0;
		vector<pii> need;
		if (dub[v]) need.pb(mp(i,i));
		rept(j,L(sm[v])) { 
			int w = sm[v][j];
			if (used[i][ans[w]]) {
				ok = 0;
				break;
			} else need.pb(mp(i,ans[w]));
		}
		rept(q,L(need)) { rept(j,q) if (need[q] == need[j]) { ok = 0; break; } if (!ok) break; }
		if (ok) {
			rept(j,L(need)) used[need[j].x][need[j].y] = used[need[j].y][need[j].x] = 1;
			rec(v+1);
			rept(j,L(need)) used[need[j].x][need[j].y] = used[need[j].y][need[j].x] = 0;
		}
		--taken[i];
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	rept(i,n) scanf("%s", mas[i]);

	rept(i,7) FOR(j,i,6) dom[d++] = mp(i,j);
	memset(num,-1,sizeof(num));
	rept(i,n)
	{
		rept(j,m)
		{
			if (num[i][j] != -1 || mas[i][j]=='.') continue;
			num[i][j] = num[i][j+1] = num[i+1][j] = num[i+1][j+1] = k++;
			cor[k-1]=mp(i,j);
		}
	}
	rept(i,n)
	{
		rept(j,m)
		{
			if (num[i][j] == -1) continue;
			rept(z,4) { 
				int ni = i + di[z];
				int nj = j + dj[z];
				if (ni<0 || ni>=n || nj<0 || nj>=m) continue;
				if (mas[ni][nj] != mas[i][j]) continue;
				if (num[ni][nj] == num[i][j]) ++dub[num[i][j]]; else
				if (num[ni][nj] < num[i][j]) sm[num[i][j]].pb(num[ni][nj]);
			}
		}
	}

	rept(i,n) rept(j,m) now[i][j] = '.';
	C(used);
	rec(0);
	printf("%d\n",c*7);
	rept(i,14)
	{
		int ci = cor[i].x, cj = cor[i].y;
		now[ci][cj] = now[ci+1][cj] = now[ci][cj+1] = now[ci+1][cj+1] = fnd[i] + '0';
	}
	rept(i,n) printf("%s\n", now[i]);
}

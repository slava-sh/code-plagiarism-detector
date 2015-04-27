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
#pragma comment(linker, "/STACK:66777216")
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
vector<pii> pnt;

void solve(vector<pii> &pnt)
{
	if (L(pnt) == 1) return;
	if (L(pnt) == 2)
	{
		if (pnt[0].x == pnt[1].x || pnt[0].y == pnt[1].y) return;
		pnt.pb(mp(pnt[0].x,pnt[1].y));
		SORT(pnt);
		return;
	}
	vector<pii> lf(0), rt(0);
	int n= L(pnt);
	rept(i,L(pnt)) if (i<n/2) lf.pb(pnt[i]); else rt.pb(pnt[i]);
	int X = lf.back().x;
	solve(lf); solve(rt);
	pnt.clear();
	rept(i,L(lf)) pnt.pb(mp(X,lf[i].y));
	rept(i,L(rt)) pnt.pb(mp(X,rt[i].y));
	rept(i,L(lf)) pnt.pb(lf[i]);
	rept(i,L(rt)) pnt.pb(rt[i]);
	if (L(pnt)>50000) {
		SORT(pnt);
		pnt.resize(unique(all(pnt)) - pnt.begin());
	}
}
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d",&n);
	rept(i,n) {
		scanf("%d%d",&a,&b);
		pnt.pb(mp(a,b));
	}
	SORT(pnt);
	solve(pnt);
	SORT(pnt);
	pnt.resize(unique(all(pnt)) - pnt.begin());
	printf("%d\n",L(pnt));
	rept(i,L(pnt))
	{
		printf("%d %d\n",pnt[i].x, pnt[i].y);
	}
}

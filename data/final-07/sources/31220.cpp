#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
using namespace std;
#define REP(i,n) for (int i=0; i<(n); ++i)
const int N=200000;
int n, m;
pair<int,int> x[N];
void go(int l, int u) {
	if (x[l].first==x[u].first) return;
	int id=(l+u)/2, pt=x[id].first;
	for (int i=l; i<=u; ++i) if (x[i].first!=pt) x[m++]=make_pair(pt,x[i].second);
	int t=id;
	if (x[l].first!=pt) {
		while (x[t].first==pt) --t;
		go(l,t);
	}
	if (x[u].first!=pt) {
		t=id;
		while (x[t].first==pt) ++t;
		go(t,u);
	}

}
int main()
{
//	freopen("B.in", "r", stdin);
	scanf("%d", &n); REP(i,n) scanf("%d%d", &x[i].first, &x[i].second);
	m=n; sort(x,x+n);
	go(0,n-1);
	sort(x,x+m);
	int m2=0;
	REP(i,m) if (i==0||x[i]!=x[i-1]) ++m2;
	printf("%d\n", m2);
	REP(i,m) if (i==0||x[i]!=x[i-1]) printf("%d %d\n", x[i].first, x[i].second);
}

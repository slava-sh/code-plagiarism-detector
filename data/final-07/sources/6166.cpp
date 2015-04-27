#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>

using namespace std;

#define lint long long

#define ss stringstream
#define sz size()
#define pb push_back
#define mp make_pair

#define FOR(i,n) SFOR(i,0,n)
#define SFOR(i,m,n) for(i=m;i<n;i++)
#define FORD(i,n) for(i=n-1;i>=0;i--)

pair<int, int> A[10010];
vector<int> Y;

vector<pair<int,int> > T;

void Rec(int l, int r) {
	if (l == r) return ;
	int m;
	Y.clear();
	SFOR(m,l,r) Y.pb(A[m].second);
	sort(Y.begin(),Y.end());
	Y.erase(unique(Y.begin(),Y.end()),Y.end());
	int x = A[(l+r)/2].first;
	FOR(m,Y.sz) T.pb(mp(x,Y[m]));
	SFOR(m,l,r) if (A[m].first == x) { Rec(l,m); break; }
	SFOR(m,l,r) if (A[m].first > x) { Rec(m,r); return ; }
}

int main() {
	T.clear();
    int i,j,m,n,k,fx,fy,p;
	char ch;
	scanf("%d",&n);
	FOR(i,n) scanf("%d%d",&A[i].first, &A[i].second);
	sort(A,A+n);
	Rec(0,n);
	printf("%d\n",T.sz);
	FOR(i,T.sz) printf("%d %d\n",T[i].first, T[i].second);
	return 0;
}
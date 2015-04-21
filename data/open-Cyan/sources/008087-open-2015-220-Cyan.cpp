#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cstdlib>

#define SC(x) scanf("%d",&x)
#define mp make_pair

using namespace std;
const int inf=2147483647, md=1e9+7;
const double eps=1e-7;

int n,m,i,j,k,L,R,N[100500],x[809][809],y[809][809],mn[809][809],mx[809][809],pointer[809],p1,p2;
vector<pair<double, int> > Y;
vector<int> X;

double gety(int X, int i){
	while (x[i][pointer[i]]<X) ++pointer[i];
	if (pointer[i]==0) return y[i][0];
	int r=pointer[i];
	return 1.*(y[i][r]-y[i][r-1])*1.*(X-x[i][r-1])/(x[i][r]-x[i][r-1])+y[i][r-1];
}

int main(){
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	SC(L); SC(R);
	SC(n);
	for (i=1; i<=n; ++i){
		SC(N[i]);
		for (j=0; j<=N[i]; ++j){
			SC(x[i][j]); SC(y[i][j]);
			X.push_back(x[i][j]);
		}
	}
	sort(X.begin(), X.end());
	k=0;
	for (i=1; i<X.size(); ++i)
		if (X[i]!=X[k]) X[++k]=X[i];
	X.resize(k+1);
	for (i=1; i<=n; ++i)
		pointer[i]=0;
	for (i=0; i<X.size(); ++i){
		Y.clear();
		for (j=1; j<=n; ++j){
			Y.push_back(mp(gety(X[i],j),j));
		}
		sort(Y.begin(), Y.end());
		for (j=0; j<Y.size(); ++j)
			mn[i][Y[j].second]=mx[i][Y[j].second]=j+1;
		for (j=2; j<=n; ++j)
			if (fabs(Y[mn[i][j]-1].first-Y[mn[i][j-1]-1].first)<eps) mn[i][j]=mn[i][j-1];
		for (j=n-1; j>=1; --j)
			if (fabs(Y[mx[i][j]-1].first-Y[mx[i][j+1]-1].first)<eps) mx[i][j]=mx[i][j+1];
		if (!i) continue;
		p1=0;
		p2=0;
		for (j=1; j<=n; ++j){
			if (mn[i][j]>mx[i-1][j] && !p1) p1=j;
			if (mx[i][j]<mn[i-1][j] && p1!=j) p2=j;
		}
		if (p2){
			printf("No\n%d %d\n",p1,p2);
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}

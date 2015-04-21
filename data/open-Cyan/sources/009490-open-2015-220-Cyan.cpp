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
#define pow success

using namespace std;
const int inf=2147483647, md=1e9+7;
const double eps=1e-7;

int n,m,i,j,k,L,R,N[100500],x[809][809],y[809][809],mn[809][809],mx[809][809],pointer[809],p1,p2,tmn[809],tmx[809],root,minpow,pow;
int fl[809],dir[809][809];
vector<pair<double, int> > Y;
vector<int> X;

double gety(int X, int i){
	while (x[i][pointer[i]]<X) ++pointer[i];
	if (pointer[i]==0) return y[i][0];
	int r=pointer[i];
	return 1.*(y[i][r]-y[i][r-1])*1.*(X-x[i][r-1])/(x[i][r]-x[i][r-1])+y[i][r-1];
}

void No(int i1, int i2){
	printf("No\n%d %d\n",i1+1,i2+1);
	exit(0);
}

void dfs(int u, int w){
	if (fl[u]==1) No(u,w);
	if (fl[u]==2) return;
	fl[u]=1;
	for (int j=0; j<n; ++j)
		if (dir[u][j]==1 && u!=j) dfs(j,u);
	fl[u]=2;
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
		//~ sort(Y.begin(), Y.end());
		//~ for (j=1; j<=n; ++j)
			//~ tmn[j]=tmx[j]=j;
		//~ for (j=2; j<=n; ++j)
			//~ if (fabs(Y[j-1].first-Y[j-1-1].first)<eps) tmn[j]=tmn[j-1];
		//~ for (j=n-1; j>=1; --j)
			//~ if (fabs(Y[j-1].first-Y[j+1-1].first)<eps) tmx[j]=tmx[j+1];
		//~ 
		//~ for (j=0; j<Y.size(); ++j){
			//~ mn[i][Y[j].second]=tmn[j+1];
			//~ mx[i][Y[j].second]=tmn[j+1];
		//~ }
		
		//~ if (!i) continue;
		//~ p1=0;
		//~ p2=0;
		//~ for (j=1; j<=n; ++j){
			//~ if (mn[i][j]>mx[i-1][j] && !p1) p1=j;
			//~ if (mx[i][j]<mn[i-1][j] && p1!=j) p2=j;
		//~ }
		//~ if (p2){
			//~ printf("No\n%d %d\n",p1,p2);
			//~ return 0;
		//~ }
		
		for (int j1=0; j1<Y.size(); ++j1)
			for (int j2=0; j2<Y.size(); ++j2){
				if (j1==j2) continue;
				if (Y[j1].first+eps<Y[j2].first){
					if (dir[j1][j2]==-1) No(j1,j2);
					dir[j1][j2]=1;
					dir[j2][j1]=-1;
				}
				if (Y[j2].first+eps<Y[j1].first){
					if (dir[j2][j1]==-1) No(j2,j1);
					dir[j2][j1]=1;
					dir[j1][j2]=-1;
				}
			}
	}
	minpow=inf;
	root=-1;
	for (i=0; i<n; ++i){
		pow=0;
		for (j=0; j<n; ++j)
			if (dir[j][i]==1) ++pow;
		if (pow<minpow){
			minpow=pow;
			root=i;
		}
	}
	dfs(root,-1);
	printf("Yes\n");
	return 0;
}

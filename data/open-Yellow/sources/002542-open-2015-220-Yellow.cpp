#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <math.h>

#define SC(x) scanf("%d",&x)

using namespace std;
const int inf=2147483647;

int n,m,i,j,k,pos,x,a[800500],col[800500],L[800500],R[800500],n0,ttt;

int main(){
	//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	SC(n);
	n0=1; while (n0<n+1) n0<<=1; --n0;
	for (i=1; i<=n; ++i)
		SC(a[i]);
	for (i=n+1; i<=n0+1; ++i)
		a[i]=inf;
	for (i=n0+n0+1; i>=1; --i){
		if (i-n0>=1){
			L[i]=R[i]=i-n0;
			col[i]=1;
		} else {
			L[i]=L[i*2];
			R[i]=R[i*2+1];
			col[i]=col[i*2]+col[i*2+1];
			if (a[R[i*2]]==a[L[i*2+1]]) --col[i];
		}
	}
	SC(ttt);
	while (ttt--){
		SC(pos); SC(x);
		a[pos]=x;
		i=pos+n0;
		col[i]=1;
		while (i>1){
			i>>=1;
			col[i]=col[i*2]+col[i*2+1];
			if (a[R[i*2]]==a[L[i*2+1]]) --col[i];
		}
		printf("%d\n",col[1]-1);
	}
	return 0;
}

#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
struct tree{
	int col,suf,pref;
};
vector<tree>t;
int m=1;
int ans(int v, int l, int r, int left, int right){
	if(left>right)
		return 0;
	if(l==left && r==right)
		return t[v].col;
	int m=(l+r)/2;
	int x1=ans(v*2,l,m,left,min(m,right)), x2=ans(v*2+1,m+1,r,max(m+1,left),right);
	if(x1 && x2 && t[v*2].suf==t[v*2+1].pref)
		return  x1+x2-1;
	return x1+x2;
}
void upd(int v, int a){
	t[v].suf=a;
	t[v].pref=a;
	v/=2;
	while(v){
		if(t[v*2].suf==t[v*2+1].pref)
			t[v].col=t[v*2].col+t[v*2+1].col-1;
		else
			t[v].col=t[v*2].col+t[v*2+1].col;
		t[v].pref=t[v*2].pref;
		t[v].suf=t[v*2+1].suf;
		v/=2;
	}
}
int main(){
	int n,Q;
	scanf("%d",&n);
	while(m<n)
		m*=2;
	t.resize(2*m);
	for(int i=0;i<2*m;i++)
		t[i].col=t[i].pref=t[i].suf=0;
	for(int i=m;i<m+n;i++){
		scanf("%d",&t[i].suf);
		t[i].pref=t[i].suf;
		t[i].col=1;
	}
	for(int i=m-1;i>0;i--){
		if(t[i*2].suf==t[i*2+1].pref)
			t[i].col=t[i*2].col+t[i*2+1].col-1;
		else
			t[i].col=t[i*2].col+t[i*2+1].col;
		t[i].pref=t[i*2].pref;
		t[i].suf=t[i*2+1].suf;
	}
	scanf("%d",&Q);
	for(;Q;Q--){
		int p,c;
		scanf("%d%d",&p,&c);
		upd(p+m-1,c);
		printf("%d\n",ans(1,m,2*m-1,m,m+n-1));
	}
}
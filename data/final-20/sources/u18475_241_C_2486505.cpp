#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define go(i,n) for(int i=0;i<n;++i)
int v[128],l[128],r[128],n,ans,hl,hr;
vector<int> b[2];
vector<double> a[2];
const double eps = 1e-10;
const int finf=-99999999;
bool cmp(int a,int b){
	return l[a]<l[b];
}
int sc(vector<int> b,vector<double >a){
	int j=0,ss=0;
	go(i,a.size()){
		if(j>=b.size())return finf;
		for(;j<b.size()&& r[b[j]]<a[i]-eps;++j);
		if(j>=b.size()||l[b[j]]>a[i]+eps)return finf;
		ss+=v[b[j]];++j;
	}
	return ss;
}
void check(){
	int x=sc(b[0],a[0])+sc(b[1],a[1]);
	if(x>ans)ans = x;
}
void sol(){
	go(_,n){
		int m =_+1;
		double step,pos;
		if(m&1){
			step =100000/( (hl+hr)/100.0+_); 
		}else{
			step =100000/((hl+100-hr)/100.0+_);
		}
		pos=step * hl /100;
		a[0].clear();
		a[1].clear();
		go(__,m){
			a[__&1].push_back(pos);
			pos+=step;
		}
		check();
	}
}
int main(){
	scanf("%d%d%d",&hl,&hr,&n);
	go(i,n){
		char c;
		scanf("%d %c %d %d",v+i,&c,l+i,r+i);
		b[c=='T'].push_back(i);
	}
	go(i,2)sort(b[i].begin(),b[i].end(),cmp);
	sol();
	b[0].swap(b[1]);
	hl=100-hl;hr=100-hr;
	sol();
	printf("%d\n",ans);
}

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 110
#define eps 1e-8
struct Nodes{
	int l,r,id,val;
}p[maxn];
int cnt1,cnt2,n,cnt[maxn];
int h1,h2,h=100,w=100000;
int ans;
int check(int id,double x)
{
	int i;
	for(i=1;i<=n;i++){
		if(p[i].id==id&&p[i].l<x+eps&&p[i].r>x-eps){
			return i;
		}
	}
	return 0;
}
void cal()
{
	double nowx=0,nextx;
	int id;
	int sum=0;
	int i,k;
	for(i=0;i<=n;i++){
		sum=0;
		double tmp=w*1.0/(h1+h2+2*i*h);
		nowx=h1*tmp;id=0;
		memset(cnt,0,sizeof(cnt));
		while(nowx<w){
			k=check(id,nowx);
			if(k==0||cnt[k])break;
			sum+=p[k].val;
			nowx=nowx+h*tmp;
			id=1-id;
			cnt[k]++;
		}
		if(nowx>=w)ans=max(ans,sum);
	}
	for(i=0;i<=n;i++){
		sum=0;
		double tmp=w*1.0/(h1+h+h-h2+2*i*h);
		nowx=h1*tmp;id=0;
		memset(cnt,0,sizeof(cnt));
		while(nowx<w){
			k=check(id,nowx);
			/*if(i==2){
				
				printf("%lf &&&&%d %d %lf %lf\n",w/tmp,k,p[k].val,nowx,tmp);
			}*/  
			if(k==0||cnt[k])break;
			                     
			sum+=p[k].val;
			nowx=nowx+h*tmp;
			id=1-id;
			cnt[k]++;
		}
	//	printf("%d %lf %d\n",i,nowx,sum);
		if(nowx>=w)ans=max(ans,sum);
	}
}
int main()
{
	int i,j,k;
	char str[10];
	while(scanf("%d%d%d",&h1,&h2,&n)!=EOF){
		cnt1=cnt2=0;
		int val,l,r;
		for(i=1;i<=n;i++){
			scanf("%d%s%d%d",&p[i].val,str,&p[i].l,&p[i].r);
			if(str[0]=='F'){
				p[i].id=0;
			}else {
				p[i].id=1;
			}
		}
		ans=0;
		cal();
		h1=h-h1;h2=h-h2;
		for(i=1;i<=n;i++){
			p[i].id=1-p[i].id;
		}
		//printf("*****\n");
		cal();
		printf("%d\n",ans);
	}
	return 0;
}
			

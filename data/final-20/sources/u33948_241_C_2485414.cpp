#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const double eps=1e-8;
struct note{int v,l,r;} a[205][2],A[205];
int hl,hr,cnt,m,l,r,v,ans,n[2];
char tmp,type;
inline double abs(double a){return a>0?a:-a;}
bool get(double k,double x,int p,double H)
{
	if (p) H=100-H; return abs(H*k-x)<eps;
}
void cal(double k,double x,int p)
{
	int i[2],res=0; i[0]=i[1]=0; double tmp=x; int tmpp=p;
//	printf("%lf %d %lf %lf\n",1/k,p,x,k*100);
	while (1){
		if (a[i[p]][p].r+eps>x) return;
		while (i[p]<=n[p] && a[i[p]][p].r+eps<x) i[p]++;
//		printf("%d %d\n",i[0],i[1]);
		if (i[p]>n[p] || a[i[p]][p].l>x+eps) return;
		res+=a[i[p]][p].v;
		if (x<100000 && get(k,100000-x,p,hr)) break;
		x+=k*100,p^=1;
		}
	if (res>ans) ans=res;
//	printf("%d %lf %d  %d %d  %lf %lf %d %d\n",tmpp,tmp,res,i[0],i[1],k,100000-x,p,hr);
}
bool cmp(const note i,const note j){return i.l<j.l;}
int main()
{
	scanf("%d%d%d",&hl,&hr,&cnt);
	for (int i=1;i<=cnt;i++){
		scanf("%d%c%c%d%d",&v,&tmp,&type,&l,&r);
		if (type=='F') a[++n[0]][0].v=v,a[n[0]][0].l=l,a[n[0]][0].r=r;
		else a[++n[1]][1].v=v,a[n[1]][1].l=l,a[n[1]][1].r=r;
		}
//	printf("%d %d\n",n[0],n[1]);
	for (int i=0;i<n[0];i++) A[i]=a[i+1][0]; std::sort(A,A+n[0],cmp);
	for (int i=0;i<n[0];i++) a[i+1][0]=A[i];
	
	for (int i=0;i<n[1];i++) A[i]=a[i+1][1]; std::sort(A,A+n[1],cmp);
	for (int i=0;i<n[1];i++) a[i+1][1]=A[i];
	
//	for (int i=1;i<=n[0];i++) printf("%d %d %d\n",a[i][0].v,a[i][0].l,a[i][0].r);
//	for (int i=1;i<=n[1];i++) printf("%d %d %d\n",a[i][1].v,a[i][1].l,a[i][1].r);
	int H0=hl,H1=hl;
	for (int i=1;i<=cnt;i++){
		if (i&1) H0=-H0,H1=200-H1;
		else H0=200-H0,H1=-H1;
		double k=100000./abs(H0-hr); cal(k,k*hl,0),cal(k,k*(100-hl),1);
		k=100000./abs(H1-hr); cal(k,k*hl,0),cal(k,k*(100-hl),1);
		}
	printf("%d\n",ans); /*for (;;); */ return 0;
}

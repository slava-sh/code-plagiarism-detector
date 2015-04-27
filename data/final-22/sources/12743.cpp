#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define inf 10000000
#define N_MAX 500100
using namespace std;

struct type
{
	int v;
	int w;
};
struct type_list
{
	int v;
	int w;
	type_list *next;
};
type_list* new_element(int v,int w)
{
	type_list *a=(type_list*)malloc(sizeof(type_list));
	a->v=v;
	a->w=w;
	a->next=NULL;
	return a;
}
type mas[N_MAX];
int pos[N_MAX];
type_list *m[N_MAX],*end[N_MAX];
bool flag[N_MAX];
int len[N_MAX];
int N,M;
int size;
void down(int num);
void up(int num)
{
	if(num==0) return;
	int par=(num-1)/2;
	if(mas[par].w<=mas[num].w) return; 
	swap(mas[num],mas[par]);
	pos[mas[num].v]=num;
	pos[mas[par].v]=par;
	up(par);
	down(num);
}
void down(int num)
{
	int l=num*2+1,k;
	int r=num*2+2;
	if(l>=size) return;
	if(mas[l].w<=mas[r].w) k=l;
	else k=r;
	if(r>=size) k=l;
	if(mas[k].w>=mas[num].w) return;
	swap(mas[k],mas[num]);
	pos[mas[num].v]=num;
	pos[mas[k].v]=k;
	up(num);
	down(k);
}
type get_min()
{
	type q=mas[0];
	len[q.v]=q.w;
	mas[0].w=inf;
	swap(mas[0],mas[size-1]);
	pos[mas[0].v]=0;
	pos[mas[size-1].v]=size-1;
	size--;
	down(0);
	return q;
}

//=====================================
void D()
{
	flag[0]=true;
	int j,v,w,u;
	type_list *qq=NULL;
	qq=m[0];
	type q;
	while(qq)
	{
		v=qq->v;
		w=qq->w;
		mas[pos[v]].w=w;
		up(pos[v]);
		down(pos[v]);
		qq=qq->next;
	}
	for(j=1;j<N;j++)
	{
		q=get_min();
		v=q.v;
		flag[v]=true;
		len[q.v]=q.w;
		qq=m[v];
		while(qq)
		{
			u=qq->v;
			if(!flag[u]) 
			{
				w=qq->w;
				mas[pos[u]].w=min(mas[pos[u]].w,len[v]+w);
				up(pos[u]);
			}
			qq=qq->next;
		}
	}
}
int main()
{
	int i,a,b;
	int w;
	type_list *qq=NULL,*ee=NULL;
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d",&N,&M);
	for(i=0;i<M;i++)
	{
		scanf("%d%d%d",&a,&b,&w);
		a--; b--;
		w=12/w;
		qq=new_element(b,w);
		if(m[a]==NULL) m[a]=end[a]=qq;
		else
		{
			end[a]->next=qq;
			end[a]=end[a]->next;
		}
		qq=new_element(a,w);
		if(m[b]==NULL) m[b]=end[b]=qq;
		else
		{
			end[b]->next=qq;
			end[b]=end[b]->next;
		}
	}
	size=N-1;
	for(i=1;i<N;i++) 
	{
		mas[i-1].w=inf;
		mas[i-1].v=i;
		pos[i]=i-1;
	}
	D();
	for(i=1;i<N;i++) printf("%.8lf\n",len[i]/12.0);
	return 0;
}
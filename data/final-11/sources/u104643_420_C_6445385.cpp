#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<string>
#include<ctime>
#include<cmath>
#include<utility>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#define INF 1111111111
#define N 333333
#define eps 1e-9
using namespace std;
typedef long long LL;
int getint()
{
	char ch;
	do
	{
		ch=getchar();
	}while (ch!='-'&&(ch<'0'||ch>'9'));
	int ans=0,f=0;
	if (ch=='-') f=1; else ans=ch-'0';
	while (isdigit(ch=getchar())) ans=ans*10+ch-'0';
	if (f) ans*=-1;
	return ans;
}
struct edge
{
	int t,n;
}e[N*2];
int sum[N*2],cnt[N],h[N];
int n,p,tote;
void adde(int f,int t)
{
	e[++tote].t=t;
	e[tote].n=h[f];
	h[f]=tote;
	return ;
}
void add(int x,int t)
{
	x++;
	for (int i=x;i<=n*2+1;i+=i&-i) sum[i]+=t;
	return ;
}
int query(int x)
{
	x++;
	int ans=0;
	for (int i=x;i;i-=i&-i) ans+=sum[i];
	return ans;
}
LL ans=0;
int main()
{
	n=getint(); p=getint();
	for (int i=1;i<=n;i++)
	{
		int x=getint(),y=getint();
		cnt[x]++; cnt[y]++;
		adde(x,y); adde(y,x);
	}
	for (int i=1;i<=n;i++) add(cnt[i],1);
	for (int i=1;i<=n;i++)
	{
		if (cnt[i]>=p) 
		{
			ans+=n-1;
			continue;
		}
		for (int j=h[i];j;j=e[j].n)
		{
			int t=e[j].t;
			add(cnt[t],-1);
			cnt[t]--;
			add(cnt[t],1);
		}
		ans+=n-1-query(p-cnt[i]-1);
		if (cnt[i]<=p-cnt[i]-1) ans++;
		for (int j=h[i];j;j=e[j].n)
		{
			int t=e[j].t;
			add(cnt[t],-1);
			cnt[t]++;
			add(cnt[t],1);
		}
	}
	cout<<ans/2;
	return 0;
}

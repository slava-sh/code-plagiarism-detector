#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
inline int getnum()
{
	int ans=0,fh=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')fh*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')ans=ans*10+ch-'0',ch=getchar();
	return fh*ans;
}
struct T{
	bool goin;int pos;
}q[210000];
bool canans[210000];
bool isin[210000];
int firstin[210000];
bool nowin[210000];int nowinnum;
int main(int argc, char *argv[])
{
	int n=getnum(),m=getnum();
	for(int i=1;i<=m;i++)
	{
		char ch[4];scanf("%s%d",ch,&q[i].pos);
		q[i].goin=(ch[0]=='+');
		if(q[i].goin&&!isin[q[i].pos])firstin[q[i].pos]=i;
		isin[q[i].pos]=true;
	}
	memset(canans,1,sizeof canans);
	for(int i=1;i<=n;i++)if(isin[i]&&!firstin[i])nowin[i]=true,nowinnum++;
	for(int i=1;i<=m;i++)
	{
		if(q[i].goin)
		{
			if(nowinnum!=0)canans[q[i].pos]=false;
			if(i!=1&&q[i-1].pos!=q[i].pos)canans[q[i].pos]=false;
			nowinnum++;
		}
		else 
		{
			nowinnum--;
			if(nowinnum!=0)canans[q[i].pos]=false;
			if(i!=m&&q[i+1].pos!=q[i].pos)canans[q[i].pos]=false;
		}
	}
	int tans=0;
	for(int i=1;i<=n;i++)
	if(canans[i])tans++;
	printf("%d\n",tans);
	for(int i=1;i<=n;i++)
	if(canans[i])printf("%d ",i);
	puts("");
	return 0;
}

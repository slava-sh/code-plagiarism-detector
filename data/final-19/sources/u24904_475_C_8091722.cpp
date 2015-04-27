#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<time.h>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

int down[1010][1010];
int a[1010][1010];
int tmp[1010][1010];

int mx,my;

int jud(int n,int m,int x,int y)
{
	if(x<1||x>n||y<1||y>m)
		return 0;
	int i,j;
	memset(tmp,0,sizeof(tmp));
	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
			tmp[mx+i][my+j]=1;
	i=mx,j=my;
	while(1)
	{
		if(i+x<n&&a[i+x][j])
		{
			for(int k=0;k<y;k++)
				tmp[i+x][j+k]=1;
			i++;
		}
		else if(j+y<m&&a[i][j+y])
		{
			for(int k=0;k<x;k++)
				tmp[i+k][j+y]=1;
			j++;
		}
		else
			break;
	}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)if(tmp[i][j]-a[i][j])
			return 0;
	return 1;
}

int gao(int n,int m)
{
	mx=21000000,my=mx;
	int i,j,k;

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)if(a[i][j])
		{
			if(mx>i||(mx==i&&my>j))
				mx=i,my=j;
		}
	int x,y;
	x=y=1;

	while(mx+x<n&&a[mx+x][my])
		x++;
	while(my+y<m&&a[mx][my+y])
		y++;
	if(mx+x>=n)
	{
		if(jud(n,m,x,1))
			return x;
		return 2100000000;
	}
	for(j=0;j<m;j++)if(a[mx+x][j])
		break;
	if(j>=m)
	{
		if(jud(n,m,x,1))
			return x;
		return 2100000000;
	}
	if(jud(n,m,x,my+y-j))
		return x*(my+y-j);
	return 2100000000;
}

int main()
{
	int n,m,i,j,k;
	char ss[2100];
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%s",ss);
		for(j=0;j<m;j++)if(ss[j]=='X')
			a[i][j]=1;
	}
	int ans=2100000000;
	ans=min(ans,gao(n,m));
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			tmp[j][i]=a[i][j];
	memcpy(a,tmp,sizeof(a));
	ans=min(ans,gao(m,n));
	if(ans==2100000000)
		ans=-1;
	printf("%d\n",ans);
}
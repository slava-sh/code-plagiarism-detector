#include<cstdio>
#include<algorithm>
using namespace std;
bool map[1050][1050];
bool cun[1050][1050];
int n,m;
char dr;
int f(int shang,int zuo,int r,int c)
{
	int i,j;
	for(i=shang;i<shang+r;i++)
	{
		for(j=zuo;j<zuo+c;j++)
		{
			if(!map[i][j])
				return -1;
			map[i][j]=0;
		}
	}
	int a=shang+r-1;
	int b=zuo+c-1;
	while(1)
	{
		for(i=0;i<c;i++)
		{
			if(!map[a+1][b-i])
				break;
		}
		if(i>=c)
		{
			a++;
			for(i=0;i<c;i++)
				map[a][b-i]=0;
			continue;
		}
		for(i=0;i<r;i++)
		{
			if(!map[a-i][b+1])
				break;
		}
		if(i>=r)
		{
			b++;
			for(i=0;i<r;i++)
				map[a-i][b]=0;
			continue;
		}
		break;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(map[i][j])
				return -1;
		}
	}
	r*=c;
	return r;
}
int main()
{
	int i,j;
	int a,b;
	int r,c;
	int ansa,ansb;
	scanf("%d%d",&n,&m);
	int zuo=m+1,you=0,shang=n+1,xia=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			dr=getchar();
			while(dr!='X' && dr!='.')
				dr=getchar();
			if(dr=='X')
			{
				map[i][j]=1;
				zuo=min(zuo,j);
				you=max(you,j);
				shang=min(shang,i);
				xia=max(xia,i);
			}
		}
	}
	if(!map[shang][zuo] || !map[xia][you])
	{
		printf("-1\n");
		return 0;
	}
	for(i=shang;i<=xia;i++)
	{
		for(j=zuo;j<=you;j++)
		{
			if(!map[i][j])
				break;
		}
		if(j<=you)
			break;
	}
	if(i>xia)
	{
		a=xia-shang+1;
		b=you-zuo+1;
		a=min(a,b);
		printf("%d\n",a);
		return 0;
	}
	a=zuo;
	while(map[shang][a+1])
		a++;
	b=shang;
	while(map[b+1][zuo])
		b++;
	int aa=a;
	c=0;
	while(map[b+1][a])
	{
		c++;
		a--;
	}
	a=aa;
	int bb=b;
	r=0;
	while(map[b][a+1])
	{
		r++;
		b--;
	}
	b=bb;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cun[i][j]=map[i][j];
		}
	}
	if(r)
		ansa=f(shang,zuo,r,a-zuo+1);
	else
		ansa=-1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			map[i][j]=cun[i][j];
		}
	}
	if(c)
		ansb=f(shang,zuo,b-shang+1,c);
	else
		ansb=-1;
	if(ansa==-1)
		printf("%d\n",ansb);
	else if(ansb==-1)
		printf("%d\n",ansa);
	else
		printf("%d\n",min(ansa,ansb));
	return 0;
}

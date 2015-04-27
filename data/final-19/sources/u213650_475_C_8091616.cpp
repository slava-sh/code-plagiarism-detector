#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define me(x) memset(x,0,sizeof(x))
#define sy system("pause")
using namespace std;
int n,m,tot;
char map[1005][1005],ma2[1005][1005];
bool canst(int x,int y,int p,int q)
{
	int i,j;
	for (i=x;i<p;i++) for (j=y;j<q;j++) if (map[i][j]=='.') return 0;
	return 1;
}
bool cangodown(int x,int y,int p,int q)
{
	int i;
	if (p==n) return 0;
	for (i=y;i<q;i++) if (map[p][i]=='.') return 0;
	return 1;
}
bool cangoright(int x,int y,int p,int q)
{
	int i;
	if (q==m) return 0;
	for (i=x;i<p;i++) if (map[i][q]=='.') return 0;
	return 1;
}
int check()
{
	int i,j,p=0,x,y,d,now;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++) if (map[i][j]=='X') {p=1; break;}
		if (p) break;
	}
	x=i; y=j;
	while(j<m&&map[i][j]=='X') j++;
	if (j==m) d=1;
	else
	{
		p=x;
		while(p<n&&map[p][j]!='X') p++;
		if (p==n) d=1;
		else
		{
			if (map[p][y]=='.') return -1;
			d=0;
			while(p+d<n&&map[p+d][y]=='X') d++;
		}
	}
	if (!canst(x,y,x+d,j)) return -1;
	now=d*(j-y);
	i=x+d;
	for(;;)
	{
		if (j==m||map[x][j]=='.')
		{
			if (cangodown(x,y,i,j))
			{
				x++;
				i++;
				now+=j-y;
			}
			else break;
		}
		else
		{
			if (cangoright(x,y,i,j))
			{
				y++;
				j++;
				now+=d;
			}
			else break;
		}
	}
	if (now==tot) return d*(j-y);
	return -1;
}
int main()
{
	int i,j,ans1,ans2,ans;
	char c;
	scanf("%d%d",&n,&m);
	tot=0;
	for (i=0;i<n;i++)
	for (j=0;j<m;j++)
	{
		do
		{
			c=getchar();
		}while(c!='.'&&c!='X');
		if (c=='X') tot++;
		map[i][j]=c;
	}
	ans1=check();
	for (i=0;i<n;i++)
	for (j=0;j<m;j++) ma2[j][i]=map[i][j];
	for (i=0;i<n;i++)
	for (j=0;j<m;j++) map[j][i]=ma2[j][i];
	i=n; n=m; m=i;
	ans2=check();
	if (ans1==-1) ans=ans2;
	else if (ans2==-1) ans=ans1;
	else ans=ans1<ans2?ans1:ans2;
	printf("%d",ans);
	return 0;
}

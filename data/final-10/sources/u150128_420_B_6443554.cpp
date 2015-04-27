#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int maxn=100086;
int z[maxn],n,m,num,order[maxn][2],last[maxn],ans[maxn],len,in[maxn];
bool flag,ok[maxn];
char s[2];

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",s);
		scanf("%d",&num);
		if(s[0]=='-')
		{
			if(z[num]==0)z[num]=-1;
			order[i][0]=-1;
			order[i][1]=num;
		}
		else
		{
			if(z[num]==0)z[num]=1;
			order[i][0]=1;
			order[i][1]=num;
		}
	}
	num=0;
	for(int i=1;i<=n;i++)
	{
		if(z[i]==0)ans[++len]=i;
		else
		{
			if(z[i]==-1)
			{
				in[i]=1;
				num++;
			}
			ok[i]=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(order[i][0]==-1)
		{
			num--;
			in[order[i][1]]=0;
			if(num)ok[order[i][1]]=0;
			last[order[i][1]]=i;
			if((i!=m)&&(order[i+1][1]!=order[i][1]))ok[order[i][1]]=0;
		}
		else
		{
			in[order[i][1]]=1;
			if(num)ok[order[i][1]]=0;
			if(last[order[i][1]]!=i-1)ok[order[i][1]]=0;
			num++;
			last[order[i][1]]=i;
		}
	}
	for(int i=1;i<=n;i++)if(ok[i])ans[++len]=i;
	sort(ans+1,ans+1+len);
	printf("%d\n",len);
	if(len)
	{
		for(int i=1;i<len;i++)printf("%d ",ans[i]);
		printf("%d",ans[len]);
		printf("\n");
	}
	
	//system("pause");
	return 0;
}

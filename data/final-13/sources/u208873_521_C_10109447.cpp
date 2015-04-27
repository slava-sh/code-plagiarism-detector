#include<cstdio>
const int N = 105000;
const int Mod = 1000000007;
int jc[N],inv[N];
int n,m;
char dr[N];
void jia(int &x,int y)
{
	x+=y;
	if(x>=Mod)
		x-=Mod;
}
void cheng(int &x,int y)
{
	long long t=x;
	t*=y;
	t%=Mod;
	x=t;
}
int power(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)
			cheng(res,x);
		cheng(x,x);
		y>>=1;
	}
	return res;
}
int zuhe(int x,int y)
{
	if(x<y)
		return 0;
	int ans=jc[x];
	cheng(ans,inv[y]);
	cheng(ans,inv[x-y]);
	return ans;
}
int main()
{
	int i;
	scanf("%d%d",&n,&m);
	scanf("%s",dr+1);
	jc[0]=inv[0]=1;
	for(i=1;i<=n;i++)
	{
		jc[i]=jc[i-1];
		cheng(jc[i],i);
		inv[i]=power(jc[i],Mod-2);
	}
	int ans=0;
	int val=zuhe(n-1,m);
	int zeng=9;
	for(i=n;i>=1;i--)
	{
		int now=dr[i]-'0';
		cheng(now,val);
		jia(ans,now);
		now=zuhe(i-2,m);
		cheng(now,zeng);
		jia(val,now);
		cheng(zeng,10);
	}
	printf("%d\n",ans);
	return 0;
}

#include<stdio.h>
#include<set>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=8000010;

int lft[maxn],rht[maxn],siz[maxn];
bool ini[maxn];

void build(int n,int l,int r)
{
    lft[n]=l,rht[n]=r;
    if(l==r)
    {
	siz[n]=ini[l];
	return;
    }
    int mid=(l+r)>>1;
    build(n<<1,l,mid);
    build((n<<1)+1,mid+1,r);
    siz[n]=siz[n<<1]+siz[(n<<1)+1];
}

int getpos(int n,int k)
{
    siz[n]--;
    if(lft[n]==rht[n])
	return lft[n];
    if(k<=siz[n<<1])
	return getpos(n<<1,k);
    return getpos((n<<1)+1,k-siz[n<<1]);
}
void upd(int n,int k)
{
    if(lft[n]==rht[n])
    {
	siz[n]++;
	return;
    }
    siz[n]++;
    int mid=(lft[n]+rht[n])>>1;
    if(k<=mid)
	upd(n<<1,k);
    else
	upd((n<<1)+1,k);
}
int now[2000010],ans[1000010];
int main()
{
    int n,m,i,j,k;
    scanf("%d%d",&n,&m);

    for(i=m+1;i<=m+n;i++)
	ini[i]=true,now[i]=i-m;
    int head=m;
    build(1,1,n+m);
    while(m--)
    {
	int x,y;
	scanf("%d%d",&x,&y);
	
	swap(x,y);
	int pos=getpos(1,x);
	int who=now[pos];
	now[pos]=0;

	if(ans[who])
	{
	    if(ans[who]-y)
	    {
		puts("-1");
		return 0;
	    }
	}
	else
	    ans[who]=y;
	now[head]=who;
	upd(1,head);
	head--;
    }
    memset(now,0,sizeof(now));
    for(i=1;i<=n;i++)
	now[ans[i]]++;
    for(i=1;i<=n;i++)if(now[i]>1)
    {
	puts("-1");
	return 0;
    }
    for(i=1,j=1;i<=n;i++)if(!ans[i])
    {
	while(now[j])
	    j++;
	ans[i]=j;
	now[j]=1;
    }
    for(i=1;i<=n;i++)
	printf("%d ",ans[i]);
    puts("");
}

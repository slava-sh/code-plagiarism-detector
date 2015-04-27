#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
#define FO(it,c) for ( __typeof( (c).begin() ) it=(c).begin();it!=(c).end();it++ )

typedef long long ll;
ll bit[300005];
void add(int a,ll ad)
{
    while (a<300005)
    {
        bit[a]+=ad;
        a+=(a&(-a));
    }
}
ll sum(int a)
{
    if (a<=0)return 0;
    ll ret=0;
    while (a>0)ret+=bit[a],a-=(a&(-a));
    return ret;
}

int a,b;
vector<int> v[300005];
int deg[300005];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&a,&b);
    int t1,t2;
    memset(deg,0,sizeof deg);
    for (int i=0;i<a;i++)
    {
        scanf("%d%d",&t1,&t2);
        if (t1>t2)v[t1].push_back(t2);
        else v[t2].push_back(t1);
        deg[t1]++,deg[t2]++;
    }
//printf("YA\n");
    ll ans=0;
    ll zeroes=0;
    for (int i=1;i<=a;i++)
    {
        FO(it,v[i])
        {
            add(deg[*it],-1);
            deg[*it]--;
            if (deg[*it]!=0)add(deg[*it],1);
            else zeroes++;
        }
        ll tmp=sum(b-deg[i]-1)+zeroes;
        //printf("deg[%d]= %d\n",i,deg[i]);
        if (b-deg[i]-1<0)tmp-=zeroes;
        ans+=i-1-tmp;
        if (deg[i]!=0)add(deg[i],1);
        else zeroes++;
        //printf("%d\n",i);
        FO(it,v[i])
        {
            if (deg[*it]!=0)add(deg[*it],-1);
            else zeroes--;
            deg[*it]++;
            add(deg[*it],1);
        }
        //printf("%I64d\n",ans);
    }
    printf("%I64d\n",ans);
    return 0;
}

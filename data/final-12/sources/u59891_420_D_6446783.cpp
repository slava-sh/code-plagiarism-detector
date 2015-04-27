#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long i64;

int n,m,lim;
const int maxn = 2100000;
int pos[maxn],rep[maxn];

int c[maxn],s[maxn];
void up(int x,int k)
{
    for(int i=x;i<=lim;i+=(i&-i))
        c[i]+=k;
}
int cal(int x)
{
    int ret=0;
    for(int i=x;i>0;i-=(i&-i))
        ret+=c[i];
    return ret;
}

int half(int xx,int yy,int k)
{
    int x=1,y=n+m;
    while(y>x)
    {
        int m=x+(y-x)/2;
        if(cal(m)>=yy)
            y=m;
        else
            x=m+1;
    }
    if(s[y]>0&&s[y]!=xx)
        return -1;
    if(s[y]==0)
    {
        if(pos[xx]>0)
            return -1;
        if(y<=m&&rep[y-m]>0)
            return -1;
        pos[xx]=y-m;
        rep[y-m]=xx;
    }
    up(y,-1);
    up(m-k,1);
    s[m-k]=xx;
    return 0;
}

int x[maxn],y[maxn];
bool solve()
{
    for(int i=0;i<m;++i)
        if(half(x[i],y[i],i)==-1)
            return false;
    return true;
}

int main()
{
    cin>>n>>m;
    lim=n+m;
    for(int i=1;i<=n;++i)
        up(i+m,1);
    for(int i=0;i<m;++i)
        scanf("%d %d",&x[i],&y[i]);
    if(!solve())
    {
        puts("-1");
        return 0;
    }
    for(int i=1,j=1;i<=n;++i)if(pos[i]==0)
    {
        while(rep[j]>0)
            ++j;
        pos[i]=j;
        rep[j]=i;
    }
    for(int i=1;i<n;++i)    printf("%d ",rep[i]);
    printf("%d\n",rep[n]);
    return 0;
}
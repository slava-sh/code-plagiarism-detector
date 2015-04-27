#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#define Mod (1000000007LL)
#define eps (1e-10)
#define Pi (acos(-1.0))
using namespace std;
int d[300100];
int n,p;
int s[300100];
struct Node
{
    int a,b;
    long long v;
}node[300100];
map<long long,int> f;
int x;
long long ans;
int main()
{
    while(~scanf("%d%d",&n,&p))
    {
        f.clear();ans=0;
        memset(d,0,sizeof(d));
        memset(s,0,sizeof(s));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&node[i].a,&node[i].b);
            if(node[i].a>node[i].b) swap(node[i].a,node[i].b);
            node[i].v=(long long)(n+1)*(long long)(node[i].a)+(long long)(node[i].b);
            f[node[i].v]++;
            d[node[i].a]++;d[node[i].b]++;
        }
        for(int i=1;i<=n;i++)
        {
            s[d[i]]++;
        }
        for(int i=1;i<=n;i++)
        {
            s[i]+=s[i-1];
        }
        for(int i=1;i<=n;i++)
        {
            x=max(0,p-d[i]);
            ans+=(long long)(n-s[x-1]);
            if(2*d[i]>=p) ans--;
        }
        //printf("%I64d\n",ans);
        ans/=2LL;
        for(int i=1;i<=n;i++)
        {
            if(d[node[i].a]+d[node[i].b]<p) continue;
            if(d[node[i].a]+d[node[i].b]-f[node[i].v]<p) ans--;
            f[node[i].v]=0;
        }
        printf("%I64d\n",ans);
    }

    return 0;
}

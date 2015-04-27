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

const int inf = 300010;

int c[310000];
void up(int x)
{
    for(int i=x;i<=inf;i+=(i&-i))
        c[i]++;
}
int cal(int x)
{
    int ret=0;
    for(int i=x;i>0;i-=(i&-i))
        ret+=c[i];
    return ret;
}

vector<int>g[310000];
int n,p;
int a[310000],b[310000];
int cnt[310000];

int main()
{
    scanf("%d %d",&n,&p);
    for(int i=1;i<=n;++i)
    {
        scanf("%d %d",&a[i],&b[i]);
        cnt[a[i]]++;
        g[a[i]].push_back(i);
        cnt[b[i]]++;
        g[b[i]].push_back(i);
    }

    long long ans=0;
    for(int i=1;i<=n;++i)if(cnt[i]>0)
        up(cnt[i]);

    for(int i=1;i<=n;++i)
    {
        if(cnt[i]>=p)
        {
            ans+=n-1;
            continue;
        }

        int q=p-cnt[i]-1;
        ans+=cal(n)-cal(q);
        if(cnt[i]>q)
            ans--;

        for(int j=0;j<g[i].size();++j)
        {
            int k=a[g[i][j]]+b[g[i][j]]-i;
            if(cnt[k]>q)
                ans--;
            cnt[k]--;
            if(cnt[k]>q)
                ans++;
        }
        for(int j=0;j<g[i].size();++j)
        {
            int k=a[g[i][j]]+b[g[i][j]]-i;
            cnt[k]++;
        }
    }
    cout<<ans/2<<endl;
    return 0;
}

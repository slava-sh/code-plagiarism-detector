//Immanuel
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#define INF 0x3f3f3f3f
#define eps 1e-8
using namespace std;
typedef long long LL;
map <int,int> cc[300005];
map <int,int>::iterator it;
int cnt[300005];
int bit[300005];
int n,p;

int main()
{

    scanf("%d%d",&n,&p);
    for(int i=0;i<n;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ++cc[x][y];
        ++cc[y][x];
        ++cnt[x]; ++cnt[y];
    }
    for(int i=1;i<=n;++i) ++bit[cnt[i]];
    for(int i=1;i<=n;++i) bit[i]+=bit[i-1];
    LL ans=0;
    for(int i=1;i<=n;++i)
    {
        ans+=bit[n]-(p-cnt[i]-1>=0?bit[p-cnt[i]-1]:0);
        if(cnt[i]*2>=p) --ans;
        for(it=cc[i].begin();it!=cc[i].end();++it)
        {
            if(cnt[i]+cnt[it->first]>=p&&cnt[i]+cnt[it->first]-it->second<p) --ans;
        }
    }
    printf("%I64d\n",ans/2);
    return 0;
}

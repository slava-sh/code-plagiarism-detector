#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <utility>
#include <stack>
#include <deque>

#define foru(i,l,r) for(int i=l; i<=r; i++)
#define ford(i,r,l) for(int i=r; i>=l; i--)

using namespace std;

const int maxn = 300100;
int cnt [maxn], head [maxn], lt [maxn], x[maxn], y[maxn], adj[maxn*2], dem[maxn];
int n, p;

int main()
{
   // freopen("test.inp","r",stdin); freopen("test.out","w",stdout);
    scanf("%d%d",&n,&p);
    memset(cnt,0,sizeof(cnt));
    memset(head,0,sizeof(head));
    foru(i,1,n)
    {
        scanf("%d%d",&x[i],&y[i]);
        cnt[x[i]]++; cnt[y[i]]++;
        head[x[i]]++; head[y[i]]++;
    }
    foru(i,2,n+1)
        head[i]+=head[i-1];
    foru(i,1,n)
        {
            adj[head[x[i]]]=y[i]; head[x[i]]--;
            adj[head[y[i]]]=x[i]; head[y[i]]--;
        }
    foru(i,1,n)
        dem[cnt[i]]++;
    ford(i,n+1,0)
        dem[i]+=dem[i+1];
    foru(i,1,n)
        lt[i]=cnt[i];
    long long kq = 0;
    foru(u,1,n)
    {
        int res=dem[max(0,p-cnt[u])];
        if (cnt[u]*2>=p)
            res--;
        foru(j,head[u]+1,head[u+1])
            if (lt[adj[j]]==p-cnt[u]&&adj[j]!=u)
            {
                res--;
                lt[adj[j]]--;
            } else lt[adj[j]]--;
        kq+=res;
        foru(j,head[u]+1,head[u+1])
            lt[adj[j]]=cnt[adj[j]];
    }
    cout<<kq/2;
    fclose(stdin); fclose(stdout);
    return 0;
}

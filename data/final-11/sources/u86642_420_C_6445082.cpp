#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#define clr(A) memset(A,0,sizeof(A))
#define mm 300005
using namespace std;
typedef long long LL;
typedef pair<int,int > P;
typedef unsigned int ULL;

vector<int> by[mm];
map<int,int> mp[mm];
int a[mm];
int b[mm];
int c[mm];
 int n,p;
void modify(int x,int dx){
   for(;x;x-=x&(-x)) c[x]+=dx;
}

LL getsum(int x){
    if(x<=0) x=1;
    LL res = 0;
     for(;x<n+2;x+=x&(-x)) res+=(LL)c[x];
     return res;
}

int main()
{
    //freopen("BUAA.in","r",stdin);
    scanf("%d%d",&n,&p);
    for(int i = 0;i<=n;i++)
    if(!mp[i].empty()) mp[i].clear();
    for(int i = 1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(x>y) swap(x,y);
        a[x]++,a[y]++;
        mp[x][y]++;
    }
    LL ans =0;
    for(int i = n;i>0;i--){
        ans+=(LL)getsum(p-a[i]+1);
        map<int,int>::iterator it;
        for(it = mp[i].begin();it!=mp[i].end();it++){
            int y = it->first,dx = it->second;
            if(a[y]>=p-a[i]&&a[i]+a[y]-dx<p) ans--;
        }
        modify(a[i]+1,1);
    }
    printf("%I64d\n",ans);
    return 0;
}

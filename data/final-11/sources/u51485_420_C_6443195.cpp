#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>
#include <queue>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
using namespace std;

const int N = 300100;
const long long INF = 2000000000000000000LL;

#define PII pair<int,int> 
#define MP make_pair
#define FI first
#define SE second

map<PII, int> mp;

int deg[N], tree[N], n, m;
vector<int> a[N];

void update(int k, int v)
{
    while(k)
    {
        tree[k]+=v;
        k-=k&(-k);
    }
}

int get(int k)
{
    int ret=0;
    while(k<N)
    {
        ret+=tree[k];
        k+=k&(-k);
    }
    return ret;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++){
        int x, y;
        scanf("%d%d", &x, &y);
        if(x>y)swap(x,y);
        mp[MP(x,y)]++;
        deg[x]++; deg[y]++;
        a[y].push_back(x);
    }
    long long ans = 0;
    for(int y=1, x, sz; y<=n; y++){
        sz = a[y].size();
        for(int i=0; i<sz; i++){
            x = a[y][i];
            update(deg[x], -1);
            deg[x]--;
            update(deg[x], 1);
        }

        if(deg[y]>=m)
            ans += y-1;
        else
            ans += get(m-deg[y]);

        for(int i=0; i<sz; i++){
            x = a[y][i];
            update(deg[x], -1);
            deg[x]++;
            update(deg[x], 1);
        }
        update(deg[y], 1);
    }
    cout<<ans<<endl;
    return 0;
}

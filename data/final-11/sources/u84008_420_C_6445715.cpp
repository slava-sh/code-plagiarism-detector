#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
using namespace std;
vector<pair<int,int> > v;
vector<int> g[300001];
int in[300001],deg[300001];
vector<int> graph[300001];
vector<int> d[300001];
int main()
{
    int n,p;
    scanf("%d%d",&n,&p);
    for(int i=0,a,b;i<n;++i){
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
        ++in[a];
        ++in[b];
    }
    for(int i=1;i<=n;++i)
        g[in[i]].push_back(i);
    for(int i=1;i<=n;++i){
        sort(graph[i].begin(),graph[i].end());
        int c=1;
        for(int j=1;j<graph[i].size();++j)
            if(graph[i][j]!=graph[i][j-1]){
                d[i].push_back(in[graph[i][j-1]]-c);
                c=1;
            }else
                ++c;
        if(graph[i].size()>0)
            d[i].push_back(in[graph[i].back()]-c);
        graph[i].resize(unique(graph[i].begin(),graph[i].end())-graph[i].begin());
    }
    for(int i=1;i<=n;++i)
        ++deg[in[i]];
    for(int i=1;i<=n;++i)
        deg[i]+=deg[i-1];
    long long res=0;
    for(int i=0;i<=n;++i){
        int rem=p-i;
        for(int j=0;j<g[i].size();++j){
            res+=deg[n]-(rem>0?deg[rem-1]:0);
            if(i>=rem)
                --res;
            //res-=d[g[i][j]].end()-lower_bound(d[g[i][j]].begin(),d[g[i][j]].end(),rem);
            for(int k=0;k<graph[g[i][j]].size();++k)
                if(in[graph[g[i][j]][k]]>=rem && d[g[i][j]][k]<rem)
                    --res;
        }
    }
    cout<<res/2;
    return 0;
}
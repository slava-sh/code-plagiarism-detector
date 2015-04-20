#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <time.h>
#define LL long long

using namespace std;


int n, m, a[6000];
int met[5001][5001];
vector<vector<pair<int, int> > > adj;
vector<int> one, two;
int d[5001];
int it=0;
void go(int x){
    priority_queue<pair<long long, int> > q;
    q.push(make_pair(0,x));
    for (int i=1;i<=n;++i) d[i]=200000000;
    d[x]=0;
    while (!q.empty()){
        long long w=q.top().first, v=q.top().second; q.pop();
        if (d[v]!=w) continue;
        for (int i=0;i<adj[v].size();++i){
            int to=adj[v][i].first, cost=adj[v][i].second;
            if (d[to]>d[v]+cost){
                d[to]=d[v]+cost;
                q.push(make_pair(d[to],to));
            }
        }
    }
}

int main(){
    freopen("secure.in","r",stdin);
    freopen("secure.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    t=clock();
    for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) met[i][j]=200000000;
    for (int i=1;i<=n;++i){
        cin >> a[i];
        if (a[i]==1) one.push_back(i);
        if (a[i]==2) two.push_back(i);
    }
    for (int i=1;i<=m;++i){
        int x, y, cost;
        cin >> x >> y >> cost;
        met[x][y]=min(met[x][y],cost);
        met[y][x]=met[x][y];
    }
    adj.resize(n+1);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            if (met[i][j]!=200000000){
                adj[i].push_back(make_pair(j,met[i][j]));
                //adj[j].push_back(make_pair(i,met[i][j]));
            }
    random_shuffle(one.begin(), one.end());
    random_shuffle(two.begin(),two.end());
    int ans=200000000, x, y;
    for (int i=0;i<one.size();++i){
        ++it;
        int cur=one[i];
        go(cur);
        for (int j=0;j<two.size();++j){
            if (ans>d[two[j]]){
                ans=d[two[j]];
                x=cur; y=two[j];
            }
        }
        if (it==500){
            it=0;

                if (ans==200000000) {
                    cout << -1;
                    return 0;
                }
                cout << x << " " << y << " " << ans;
                return 0;

        }
    }
    if (ans==200000000){
        cout << -1;
        return 0;
    }
    cout << x << " " << y << " " << ans;
    return 0;
}

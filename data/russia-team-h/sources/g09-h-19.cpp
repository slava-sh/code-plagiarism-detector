#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<set>
#define LL long long 
#define Pi 3.14159265358
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

#define pb push_back
#define mp make_pair
#define MAXN 200100
#define INF 1000000000
long long ans, ans1, ans2=INF;
LL N, M, d[MAXN]; vector<LL> G[MAXN], C[MAXN];
set< pair<LL, LL> > T;

void solve(LL cvero)
{
     //cout<<cvero<<" asd ";
    LL i, j, k, val, x;

    for(i = 1; i <= N; i++) d[i] = INF;
    d[cvero]=0;
    while(T.size())T.erase(*T.begin());
    T.insert( mp(0, cvero) );

    while( T.size())
    {
        val = (*T.begin()).first;
        x = (*T.begin()).second;
        T.erase(*T.begin());
        for(i = 0; i < G[x].size(); i++)
         if(d[ G[x][i] ] > val + C[x][i] )
            d[ G[x][i] ] = val + C[x][i], T.insert(mp(d[G[x][i]],G[x][i]));
    }
}

int main(void)
{
freopen("secure.in","r",stdin);
       freopen("secure.out","w",stdout);

    LL i, a, b, c;
    LL mas[10001];
    cin>>N;
    cin>>M;
    for(i=1;i<=N;i++)cin>>mas[i];
    for(i = 1; i <M; i++)
        scanf("%d %d %d\n", &a, &b, &c), G[b].pb(a), C[b].pb(c), G[a].pb(b), C[a].pb(c);
    for(i=1;i<=N;i++){
    if(mas[i]==1)
    solve(i);

    for(int j = 1; j <= N; j++)
    { if(mas[j]==2){
                    if(ans2>d[j]){ ans2=d[j]; ans1=j; ans=i;}
                    }
                    }}
       if(ans2!=INF){
                     cout<<ans<<" "<<ans1<<" "<<ans2;
                     }
       else cout<<-1;
        cout<<endl;
//system("pause");
    return 0;
}


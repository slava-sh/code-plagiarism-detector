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
#define MM 1000000007
#define pr priority_queue
#define LL long long 
#define Pi 3.14159265358
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define vc vector<int> 
using namespace std;
const LL INF = 100000000000ll;
LL ans, ans1, ans2=INF;
LL d[5005][5005]; 
vector < pair < int , int > > g[100051];
pr < pair < LL , int > > q[100051];
int a[5005];
LL n, m, k, i, j, x, y, z, res, papu, axda, kacha, to, len, v, cur;
main(){
       freopen("secure.in","r",stdin);
       freopen("secure.out","w",stdout);
       scanf("%d",&n);
       scanf("%d",&m);
       for(i=1;i<=n;i++){
                         scanf("%d",&a[i]);
                         if(a[i]==1) axda++;
                         else if(a[i]==2 )axda--;
                         }
       for(i=1;i<=m;i++){
                         scanf("%d%d%d",&x,&y,&z);
                         g[x].pb(mp(y,z));
                         g[y].pb(mp(x,z));
                         }
       if(axda>=0)kacha=1;
       else kacha=2;
       for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
       d[i][j]=INF; 
          
       for(papu=1;papu<=n;papu++)
        {
         if(a[papu]==kacha)
          {
           LL s=papu;
           d[papu][papu]=0;
           q[papu].push(mp(0,s)); 
           while(q[papu].size())
            {
             v=q[papu].top().se;
             cur=-1*q[papu].top().fi;
             if(a[v]==(kacha)%2+1)
              {
               if(ans2>d[papu][v])
                {
                 if(axda<0)
                  {
                   ans=v;
                   ans1=papu;
                   ans2=d[papu][v];
                  }        
                 else
                  {        
                   ans=papu;
                   ans1=v;
                   ans2=d[papu][v];
                  }
                }
               break;
              }
             q[papu].pop();
             if(cur>d[papu][v])
             continue;
             for(j=0;j<g[v].size();j++)
              {
               to=g[v][j].fi;
               len=g[v][j].se;
               if(d[papu][v]+len<d[papu][to])
                {
                 d[papu][to]=d[papu][v]+len;  
                 q[papu].push(mp(-1*d[papu][to],to));
                }
              }
            }
          }
        }
        if(ans2==INF || ans==0 || ans1==0)cout<<-1;
        else
        cout<<ans<<" "<<ans1<<" "<<ans2;
        //system("pause");
        return 0;
        }

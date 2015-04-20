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
vector < pair < LL , LL > > g[100001];
int a[100001];
LL n, m, k, i, j, x, y, z, res, axda;
main(){
       freopen("secure.in","r",stdin);
       freopen("secure.out","w",stdout);
       scanf("%d",&n);
       scanf("%d",&m);
       for(register int i=1;i<=n;i++){
                         scanf("%d",&a[i]);
                         if(a[i]==1){
                                     axda++;
                                     }
                         else if(a[i]==2)axda--;
                         }
       for(register int i=1;i<=m;i++){
                         scanf("%d",&x);
                         scanf("%d",&y);
                        scanf("%d",&z);
                         g[x].pb(mp(y,z));
                         g[y].pb(mp(x,z));
                         }
                         int kacha=0;
                         if(axda>=0)kacha=1;
                         else kacha=2;
                         
                         
                         
                          pr < pair < LL , LL > > q;
               LL d[100001], p[100001]; 
               
               
               
       for(register int papu=1;papu<=n;papu++){
              
               if(a[papu]==kacha){
       for(register int i=1;i<=n;i++){
                         d[i]=INF;
                         p[i]=0;
                         }
                         int s=papu;
       d[papu]=0;
       while(!q.empty())q.pop();
       q.push(mp(0,s));
       while(!q.empty())
       {
		long long v=q.top().se;
        long long cur=-1*q.top().fi;
        
        if(a[v]==(kacha)%2+1){
                    if(ans2>d[v]){
                                  if(axda<0){
                                             ans=v;
                                             ans1=papu;
                                             ans2=d[v];
                                             }         else{        
                                 ans=papu;
                                 ans1=v;
                                 ans2=d[v];}
                                 }
                                 break;
                    }
        
        
        
        
		q.pop();
		if(cur>d[v])
        continue;
        for(register int j=0;j<g[v].size();j++)
         {
          int to=g[v][j].fi;
		  long long len=g[v][j].se;
		  if(d[v]+len<d[to])
           {
		    d[to]=d[v]+len;
		    p[to]=v;
		    q.push(mp(-1*d[to],to));
		   }
		 } 
 	   }
     }}
                         if(ans2==INF || ans==0 || ans1==0)cout<<-1;
                         else
                         cout<<ans<<" "<<ans1<<" "<<ans2;
                        // system("pause");
                        return 0;
      }

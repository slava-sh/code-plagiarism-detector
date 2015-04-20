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
LL n, m, k, i, j, x, y, z, res;
int main(){
           freopen("secure.in","r",stdin);
       freopen("secure.out","w",stdout);
       cin>>n;
       cin>>m;
       for(i=1;i<=n;i++){
                         scanf("%d",&a[i]);
                         }
       for(i=1;i<=m;i++){
                         scanf("%d",&x);
                         scanf("%d",&y);
                        scanf("%d",&z);
                         g[x].pb(mp(y,z));
                         g[y].pb(mp(x,z));
                         }
                         //cout<<endl;
       for(int papu=1;papu<=n;papu++){
               pr < pair < LL , LL > > q;
               LL d[100001], p[100001]; 
               if(a[papu]==1){
       for(i=1;i<=n;i++){
                         d[i]=INF;
                         }
                         int s=papu;
       d[papu]=0;
       q.push(mp(0,s));
       while(!q.empty())
       {
		LL v=q.top().second;
        LL cur=-1*q.top().first;
		q.pop();
		if(cur>d[v])
        continue;
        for(j=0;j<g[v].size();j++)
         {
          LL to=g[v][j].first;
		  LL len=g[v][j].second;
		  if(d[v]+len<d[to])
           {
		    d[to]=d[v]+len;
		    p[to]=v;
		    q.push(mp(-1*d[to],to));
		   }
		 } 
 	   }
       for(i=1;i<=n;i++){
                         if(d[i]!=EOF && a[i]==2 && ans2>d[i]){
                                      ans=papu;
                                      ans1=i;
                                      ans2=d[i];
                                      }
                         }
                         //cout<<endl;
                         }
                         }
                         if(ans2==EOF || ans==0 || ans1==0)cout<<-1;
                         else
                         cout<<ans<<" "<<ans1<<" "<<ans2;
                         //system("pause");
                        return 0;
      }

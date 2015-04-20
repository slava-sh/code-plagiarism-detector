#include<iostream>
#include<map>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<fstream>
#include<math.h>
#include<utility>
#define INF 1000000001
using namespace std;
struct o{
       int x,y;
       };
long long n,m,sum=0; long b[1000001]={0};

vector <o> a[1000000];
bool used[100001]={0};
long d[10000]={0};
  vector <o> h;
   bool f (o a,o b){
          return a.y>b.y;
          }
void dfs(int v){
      used[v]=1;
    for (int k=0;k<a[v].size();++k)
        {
             if (!used[a[v][k].x] && d[a[v][k].x]>d[v]+a[v][k].y){
                d[a[v][k].x]=d[v]+a[v][k].y;
                o rt; rt.x=a[v][k].x; rt.y=d[a[v][k].x];
                h.push_back(rt);
                push_heap(h.begin(),h.end(),f);        
                                }
         }
         if (h.size()==0) return;
         while (h.size()){
         o p=h.front();
         pop_heap(h.begin(),h.end(),f);
         h.pop_back();
         if  (!used[p.x]){
          dfs(p.x);
          break;
          }
          }
         return;
     }
     vector <int> rt;
int main(){
freopen("secure.in","r",stdin);
freopen("secure.out","w",stdout);
//freopen("input.txt","r",stdin);
////freopen("output.txt","w",stdout);
   cin>>n>>m; long c=3;
   long pas1=0,pas2=0; long s1=0,s2=0;
   for (int k=1;k<=n;++k){
        cin>>b[k];
        if (b[k]==1) rt.push_back(k);
        if (b[k]==1) ++s2; if(b[k]==2)++s1;
        }
        long long poi;
        if (s2>s1) poi=2;else poi=1;
        for (int k=1;k<=m;++k)
         {long a1,b,z;
         cin>>a1>>b>>z;
              o a2;
              a2.x=b; a2.y=z;
                a[a1].push_back(a2);
                a2.x=a1;
                a[b].push_back(a2); 
                 }
                 long maxc=INF;
                 for (int v1=0;v1<rt.size();++v1){
                     int v=rt[v1];
               make_heap(h.begin(),h.end(),f); 
            for (int i=1;i<=n;++i)  d[i]=INF,used[i]=0; 
             d[v]=0;  
             dfs(v);
             for (int k=1;k<=n;++k)
                  if (b[k]==2 && d[k]<INF) 
                  {
                      if (maxc>d[k]) pas1=v,pas2=k;        
                  maxc=min(maxc,d[k]);
             }
             }
             if (maxc==INF) cout<<-1;else
             cout<<pas1<<' '<<pas2<<' '<<maxc;
 return 0;
}

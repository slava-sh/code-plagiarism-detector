#include<algorithm>
#include<iostream>
#include<utility>
#include<memory.h>
#include<cstdio>
#include<cstring>
#include<vector>
#include<list>
#include<set>  
#include<map>   
#define tr(con,it) for(typeof(con.begin()) it=con.begin();it!=con.end();it++)
#define For(N,i) for(int i=0;i<N;i++)
#define f first
#define s second
#define mp make_pair
#define inf  1<<30 
#define input  "graph.in"
#define output "graph.out"
#define N 500100
#define M 2000000
using namespace std;
int Q[13][N];
int h,k,x,r;
int    to[M],E[M],w[M];
int    G[N],d[N];
bool   used[M];
int n,m,ok;   
int Map[5];
int main() {
    Map[4]=3; Map[3]=4; Map[2]=6; Map[1]=12;
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);      
    scanf("%d%d",&n,&m);
    for (int i=1,a,b,c;i<=m;i++) {
        scanf("%d%d%d",&a,&b,&c); 
        c=Map[c];
        to[i]=G[a];    G[a]=i;    E[i]=b;        w[i]=c;
        to[m+i]=G[b];  G[b]=m+i;  E[m+i]=a;      w[m+i]=c;
   }

   Q[0][0]=Q[0][1]=1; 
  /* memset(d,inf,sizeof(d)); */  for(int i=0;i<=n;i++)  d[i]=inf; d[1]=0;
   while( h <= Q[k][0] ) {
         x=0;
         for(int i=0;i<=12;i++)   
             if(Q[i][0]) x=1;
             if(x==0 ) break;
              h++; 
      if(h>Q[k][0]) {
         Q[k][0]=0;
         h=0; k++;
         k%=13;
         continue; // goto H; 
      }
      if(!used[Q[k][h]]) {
         used[Q[k][h]]=true;
         x=G[Q[k][h]];

      while(x>0) {
        if (!used[E[x]]) {
          r=(k+w[x])%13;
          Q[r][0]++;
          Q[r][Q[r][0]]=E[x];
          d[E[x]]=min(d[E[x]],d[Q[k][h]]+w[x]);
        }
        x=to[x];
      }
    }
   // H:;
  }
    cout.precision(20);


    for(int i=2;i<=n;i++)  printf("%.20lf\n",((double)d[i]/12));
//    for(int i=2;i<=n;i++) cout<<(double)d[i]/12<<endl;



    return 0;

}


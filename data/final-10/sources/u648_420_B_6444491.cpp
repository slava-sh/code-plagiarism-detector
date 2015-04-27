#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include <ctime>
#include<cassert>
#include <pthread.h>


using namespace std;

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MP make_pair
#define pb push_back


#define maxn 300005
#define maxt 100
#define maxv 1000000

#define inf  1000000000
#define   M  1000000007

typedef long long  LL;

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<pi> vpi;


int f[maxn];
int ops[maxn];

int main()
{
   int i,j,k,T,n,m,cs=0;
   int x=-1;
   int cnt=0;

   scanf("%d%d",&n,&m);
   for(i=0;i<m;i++)
   {
      char op[5];
      scanf("%s%d",op,&k);
      if(op[0]=='+')
      {
         ops[i]=+k;
      }
      else
      {
         if(f[k]==0)
            x=k,cnt++;
         ops[i]=-k;
      }
      f[k]=1;
   }

   int ans=0;
   for(i=1;i<=n;i++) if(f[i]==0) ans++;

   if(cnt==0 && ops[0]>0) x=ops[0];

   int ok=1;

   if(x>0)
   {
      int login=cnt;
      bool logged=false;
      if(cnt) logged=true;

      for(i=0;i<m;i++)
      {
         k=abs(ops[i]);
         if(ops[i]>0)
         {
            login++;
            if(k==x) logged=true;
         }
         else
         {
            login--;
            if(k==x) logged=false;
         }
          if(logged==false && login>0) ok=0;
      }

      if(ok) f[x]=0,ans++;
   }
   printf("%d\n",ans);
   int p=0;
   for(i=1;i<=n;i++)
   {
      if(f[i]) continue;
      if(p) printf(" ");
      printf("%d",i);
      p=1;
   }
   puts("");





	return 0;
}

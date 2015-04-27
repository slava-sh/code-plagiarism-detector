#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <sstream>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
 
using namespace std;
 
#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define fin(name) freopen(name, "r", stdin)
#define fout(name) freopen(name, "w", stdout)
#define sf(x) scanf("%d",&(x))
#define pf(x) printf("%d",(x))
#define sfl(x) scanf("%l64d",&(x))
#define pfl(x) printf("%l64d",(x))
#define end printf("\n")
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int inf = (int) 1e9, maxn = (int) 1e5 + 1;
const double eps = (double) 1e-8;
const int mod = (int) 1000000009;
 
//cout<<fixed<<setprecision(10);


int main()
{ 
 char g[100001];
 int n,m,k=0,id[100001],l=-1,b[100001],pl[100001];
 bool a[100001];
 memset(a,0,sizeof a);
 memset(b,0,sizeof b);
 cin>>n>>m;
 for (int i=1;i<=m;i++)
 {
  cin>>g[i];
  cin>>id[i];
  if (b[id[i]]==0)
  {
   if (g[i]=='-')
   {
    b[id[i]]=1;
    k++;
   }
   else
    b[id[i]]=-1;
  }
 }
 for (int i=1;i<=n;i++)
 {
  if (b[i]==0)
   b[i]=1;
  if (b[i]==1)
   a[i]=1;
 }
 bool t=0;
 for (int i=1;i<=m;i++)
 {
  if (i==1 && g[1]=='+' && k==0)
  {
   t=1;
   k++;
   l=id[1];
   continue;
  }
  if (id[i]==l && g[i]=='-' && k>1)
  {
   k--;
   l=-1;
  }
  else
  if (id[i]==l && g[i]=='+' && k>0)
  {
   k++;
   l=-1;
  }   
  else
  if (b[id[i]]==1 && g[i]=='-')
  {
   k--; 
   if ((i<m && id[i+1]!=id[i]) || (k>0))
   {   
    b[id[i]]=-1;
    a[id[i]]=0;
   }
  }
  else
  if (b[id[i]]==1 && g[i]=='+')
  {
   k++; 
   if (k>1)
   {
    b[id[i]]=-1;
    a[id[i]]=0;
   }
  }   
  else
  if ((id[i]==l && g[i]=='-'))
  {
   k--;
   if (i<m && id[i+1]!=id[i])
   {
    l=-1;
   }   
  }
  else
  if (id[i]==l && g[i]=='+')
  {
   k++;
  } 
  else
  if (g[i]=='+')
  {
   k++;
  }
  else
  if (g[i]=='-')
  {
   k--;
  }
 }
 if (l!=-1)
  a[l]=1;
 int o=0;
 for (int i=1;i<=n;i++)
  if (a[i]==1)
   o++;
 cout<<o<<endl;
 for (int i=1;i<=n;i++)
  if (a[i]==1)
   cout<<i<<" "; 
 return 0;
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <ctime>
 
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
#define sfl(x) scanf("%lld",&(x))
#define pfl(x) printf("%lld",(x))
#define enter printf("\n")
#define space printf(" ")
#define fi(st,n) for(int i=(st);i<=(n);i++)
#define fj(st,n) for(int j=(st);j<=(n);j++)
#define clean(a) memset((a),0,sizeof (a));
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int inf = (int) 1e9, maxn = (int) 1e5 + 1;
const double eps = (double) 1e-8;

 //fin("in.txt");
 //fout("out.txt");
 
// cout<<fixed<<setprecision(10);

ll n,m,mod,a[1001],b[2][502][1002],l,x,y;
ll ans;
string st;

int main()
{ 
 cin>>n>>m>>mod;
 clean(a);
 for (int i=1;i<=m;i++)
 {
  cin>>st;
  for (int j=1;j<=n;j++)
  {
   a[j]+=bool(st[j-1]=='1');
  }
 }
 if (m==n)
 {
  cout<<1;
  return 0;
 }
 l=n-m; 
 clean(b);
 b[0][0][0]=1;
 x=0;
 int k=0,w;
 for (int i=1;i<=n;i++)
 {
  k+=(2-a[i]);
  y=x;
  x=!x;
  clean(b[x]);
  for (int q=0;q<=l;q++)
  {
   w=k-2*q;
   if (w>=0 && w<=l)
   {
    if (a[i]==1)
    {
     b[x][q][w]=0;
     if (q>0 && w<l && b[y][q-1][w+1]>0)
      b[x][q][w]=b[y][q-1][w+1]*(w+1);
     if (w>0 && l-q-w+1>0 && b[y][q][w-1]>0)
      b[x][q][w]=b[x][q][w]+b[y][q][w-1]*(l-q-w+1);
     b[x][q][w]%=mod;
    }
    else
    if (a[i]==0)
    {
     b[x][q][w]=0;
     if (q>1 && w<l-1 && b[y][q-2][w+2]>0)
      b[x][q][w]=b[y][q-2][w+2]*( ((w+2)*(w+1))/2);
     if (w>1 && (l-q-w+2>1) && (l-q-w+2<=l) && b[y][q][w-2]>0)
      b[x][q][w]=b[x][q][w]+b[y][q][w-2]*(((l-q-w+2)*(l-q-w+1))/2);
     if (l-w-q+1>0 && w>0 && q>0 && b[y][q-1][w]>0)
      b[x][q][w]=b[x][q][w]+b[y][q-1][w]*(w*(l-w-q+1));
     b[x][q][w]%=mod;
    }
    else
     b[x][q][w]=b[y][q][w];
   }
  }
 }
 cout<<b[x][l][0];
 return 0;
}
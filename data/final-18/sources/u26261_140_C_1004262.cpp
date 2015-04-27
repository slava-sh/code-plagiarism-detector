#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int,int> ipair;
typedef pair<string,string> spair;

#define PB push_back
#define MP make_pair
#define SIZE(X) ((int)X.size())
#define LENGTH(X) ((int)X.length())
#define two(X) (1<<(X))
#define twoL(X) ((1ll)<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)

template<class T> void checkmin(T &a,T b) {if (b<a) a=b;}
template<class T> void checkmax(T &a,T b) {if (b>a) a=b;}
template<class T> T sqr(T x) {return x*x;}
template<class T> T gcd(T a,T b) {if (a<0) return gcd(-a,b); if (b<0) return gcd(a,-b); return (b==0)?a:gcd(b,a%b);}
template<class T> void out(vector<T> A,int n=-1) {if(n==-1)n=SIZE(A);if(n>SIZE(A))n=SIZE(A);cout<<"{";for(int i=0;i<n;i++)cout<<A[i]<<" ";cout<<"}"<<endl;}
template<class T> void out(T A[],int n) {cout<<"{"; for (int i=0;i<n;i++) cout<<A[i]<<" "; cout<<"}"<<endl;}

string tostring(int v) {ostringstream sout; sout<<v; return sout.str();}
string tostring(int64 v) {ostringstream sout; sout<<v; return sout.str();}

int low(int i) {return i&-i;}
int countbit(int i) {return (i==0)?0:(1+countbit(i-low(i)));}
int toint(string s) {istringstream sin(s); int t; sin>>t; return t;}

int64 toint64(string s) {istringstream sin(s); int64 t; sin>>t; return t;}

const double pi=acos(-1.);
const double eps=1e-11;

const int N=200005;

int a[N],c[N],d[N],ed,b[N][5],bb[N][5];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  int n; scanf("%d",&n);
  for (int i=1;i<=n;i++) scanf("%d",&a[i]);
  sort(a+1,a+n+1);
  for (int i=1;i<=n;i++)
    if (a[i]!=a[i-1])
    {
      ed++; c[ed]=a[i]; d[ed]=1;
    }
    else d[ed]++;
  int l,r;
  for (l=0,r=n;l<r;)
  {
    int mid=(l+r+1)/2;
    int tot=0;
    for (int i=0;i<mid;i++) b[i][0]=0;
    for (int i=1;i<=ed;i++) a[i]=min(mid,d[i]);
    int j=1;
    for (int k=1;k<=3;k++)
    {
      for (int i=0;i<mid;i++)
      {
        if (tot>=mid*3) break;
        while (j<=ed)
        {
          if (a[j]==0) j++;
          if (j>ed) break;
          tot++;
          a[j]--;
          b[i][k]=c[j];
          break;
          if (tot>=mid*3) break;
        }
      }
      if (tot>=mid*3) break;
    }
    if (tot>=mid*3)
    {
      l=mid;
      for (int i=0;i<mid;i++)
        for (int j=1;j<4;j++) bb[i][j]=b[i][j];
    }
    else r=mid-1;
  }
  printf("%d\n",l);
  for (int i=0;i<l;i++) printf("%d %d %d\n",bb[i][3],bb[i][2],bb[i][1]);
  return 0;
}

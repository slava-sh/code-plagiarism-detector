// gskhirtladze

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define Pii pair < int , int >
#define tree int t,int l,int r
#define left 2*t,l,(l+r)/2
#define right 2*t+1,(l+r)/2+1,r
#define get(x) scanf("%d",&x)
#define LL long long
#define INF 1000000000
#define eps 0.00000001
#define P7 1000000007
#define P9 1000000009
#define N3 2555
#define N5 262145
#define N6 1048577
#define SS system("pause")

using namespace std;

int tst,all;
void get_ready() {
     //freopen(".in","r",stdin);
     //freopen("txt.out","w",stdout);
     tst=1; //get(tst);
     //get_pr(N5);
 }

int DP[N3][N3];
string D[N3];
int stx,sty,i,j,n,m,ans=INF;

bool solve(int h,int w)
 {
  int x=stx;
  int y=sty;
  int now=0;
  if (DP[x+h][y+w]-DP[x][y+w]-DP[x+h][y]+DP[x][y] != h*w) return false;
  now=h*w;
  while (D[x+h][y] == 'X' || D[x][y+w] == 'X')
   {
    if (D[x+h][y] == 'X' && D[x][y+w] == 'X') return false;
    if (D[x+h][y] == 'X')
     {
      if (DP[x+h+1][y+w]-DP[x][y+w]-DP[x+h+1][y]+DP[x][y] != h*w+w) return false;
      x++; now+=w;
     } else
     {
      if (DP[x+h][y+w+1]-DP[x+h][y]-DP[x][y+w+1]+DP[x][y] != h*w+h) return false;
      y++; now+=h;
     }
     if (x+h >n || y+w > m) return false;
   }
  
  if (now != all) return false;
  return true;
 }


main()
{get_ready();
 while (tst--){
  
  
  cin>>n>>m;
  for (i=0;i<n;i++)
   cin>>D[i];
  for (i=0;i<n;i++)
   for (j=0;j<m;j++)
    if (D[i][j] == 'X') { DP[i+1][j+1]=DP[i][j+1]+DP[i+1][j]-DP[i][j]+1; all++; } else
         DP[i+1][j+1]=DP[i][j+1]+DP[i+1][j]-DP[i][j];
  for (i=0;i<n;i++) { 
   for (j=0;j<m;j++)
    if (D[i][j] == 'X') break;  if (j != m) break;} 
  stx=i,sty=j;
  for (i=0;i<m;i++) { 
   for (j=0;j<n;j++)
    if (D[j][i] == 'X') break; if (j != n) break; }
  swap(i,j);
  if (i != stx || j != sty)
   { cout<<-1<<endl; return 0; }
  int marj=0;
  while (j < m && D[stx][j] == 'X') j++;
  marj=j-sty;
  int qvev=0;
  while (i < n && D[i][sty] == 'X') i++;
  qvev=i-stx;
  ans=INF;;
  for (i=1;i<=n;i++)
   if (solve(i,marj))
    ans=min(ans,i*marj);
  for (j=1;j<=m;j++)
   if (solve(qvev,j))
    ans=min(ans,j*qvev);
  if (ans == INF) ans=-1;
  cout<<ans<<endl;
}}

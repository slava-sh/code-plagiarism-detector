#include<iostream>
#include<set>
#include<map>
#include<string>
#include<stdio.h>
#include<sstream>
#include<algorithm>
#include<sstream>
#include<queue>
#include<cmath>
#include<string.h>
using namespace std ;
#define MAXN 202
int R ;
int n,cutHh[MAXN],cutHt[MAXN] ;
int m,cutTh[MAXN],cutTt[MAXN] ;

int best[MAXN][MAXN] ;
int checkWin(int h,int t)
{
 memset(best,255,sizeof best) ;
 int sz = 0,q[MAXN * MAXN * 2] ;
 best[h][t] = 0 ;
 q[sz++] = h ; q[sz++] = t ;
 for(int i = 0;i < sz;i += 2)
 {
  h = q[i],t = q[i + 1] ;
  int steps = best[h][t] ;
  if(h == 0 && t == 0) return steps ;
  for(int i = 1;i <= n && i <= h;i++)
  {
   int nh = h - i + cutHh[i] ;
   int nt = t + cutHt[i] ;
   if(nh + nt > R) continue ;
   if(best[nh][nt] == -1)
   {
    best[nh][nt] = 1 + steps ;
    q[sz++] = nh ;
    q[sz++] = nt ;
   }
  }
  for(int i = 1;i <= m && i <= t;i++)
  {
   int nh = h + cutTh[i] ;
   int nt = t - i + cutTt[i] ;
   if(nh + nt > R) continue ;
   if(best[nh][nt] == -1)
   {
    best[nh][nt] = 1 + steps ;
    q[sz++] = nh ;
    q[sz++] = nt ;
   }
  }
 }
 return -1 ;
}

int vis[MAXN][MAXN] ;
bool checkDraw(int h,int t)
{
 if(vis[h][t] == 1) return true ;
 if(vis[h][t] == 2) return false ;
 vis[h][t] = 1 ;
 for(int i = 1;i <= n && i <= h;i++)
 {
  int nh = h - i + cutHh[i] ;
  int nt = t + cutHt[i] ;
  if(nh + nt > R) continue ;
  if(checkDraw(nh,nt)) return true ;
 }
 for(int i = 1;i <= m && i <= t;i++)
 {
  int nh = h + cutTh[i] ;
  int nt = t - i + cutTt[i] ;
  if(nh + nt > R) continue ;
  if(checkDraw(nh,nt)) return true ;
 }
 vis[h][t] = 2 ;
 return false ;
}

int memo[MAXN][MAXN] ;
int checkLose(int h,int t)
{
 if(h + t > R) return 0 ;
 if(memo[h][t] != -1) return memo[h][t] ;
 int ret = 0 ;
 for(int i = 1;i <= n && i <= h;i++)
 {
  int nh = h - i + cutHh[i] ;
  int nt = t + cutHt[i] ;
  ret = max(ret,1 + checkLose(nh,nt)) ;
 }
 for(int i = 1;i <= m && i <= t;i++)
 {
  int nh = h + cutTh[i] ;
  int nt = t - i + cutTt[i] ;
  ret = max(ret,1 + checkLose(nh,nt)) ;
 }
 return memo[h][t] = ret ;
}

int main()
{
 int H,T ;
 cin >> H >> T >> R ;
 cin >> n ;
 for(int i = 1;i <= n;i++) cin >> cutHh[i] >> cutHt[i] ;
 cin >> m ;
 for(int i = 1;i <= m;i++) cin >> cutTh[i] >> cutTt[i] ;
 
 int r1 = checkWin(H,T) ;
 if(r1 != -1) printf("Ivan\n%d\n",r1) ;
 else
 {
  memset(vis,0,sizeof vis) ;
  bool r2 = checkDraw(H,T) ;
  if(r2) printf("Draw\n") ;
  else
  {
   memset(memo,255,sizeof memo) ;
   int r3 = checkLose(H,T) ;
   printf("Zmey\n%d\n",r3) ;
  }
 }
 return 0 ;
}

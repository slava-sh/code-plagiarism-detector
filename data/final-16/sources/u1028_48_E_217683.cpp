#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define sqr(a) (a)*(a)
#define D(a,b) sqrt(((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long

int a,b,c,d,i,j,n,m,k,h,t,r;
vector<pii> sm[201][201];
pii head[201],tail[201];
int cnt[201][201],ds[201][201],win[201][201];
queue<pii> q;
int rec(int ci,int cj)
{
    if (ci==r && cj==r) return 0;
    if (ds[ci][cj]==-2) return INF;
    if (ds[ci][cj]!=-1) return ds[ci][cj];
    ds[ci][cj]=-2;
    int ans=-1;
    rept(i,L(sm[ci][cj]))
    {
        int ni=sm[ci][cj][i].x;
        int nj=sm[ci][cj][i].y;
        ans=max(ans,rec(ni,nj)+1);
    }
    if (ans==-1) ans=INF;
    if (ans>=INF) ans=INF;
    return ds[ci][cj]=ans;
}
int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%d%d%d",&h,&t,&r);
    scanf("%d",&n);
    rep(i,n) scanf("%d%d",&head[i].x,&head[i].y);
    scanf("%d",&m);
    rep(i,m) scanf("%d%d",&tail[i].x,&tail[i].y);
    rept(i,r+1)
    {
        rept(j,r+1)
        {
            if (i+j>r) continue;
            rep(ch,n)
            {
                if (ch>i) continue;
                int ni=i-ch+head[ch].x;
                int nj=j+head[ch].y;
                if (ni+nj>r) sm[i][j].pb(mp(r,r)); else
                sm[i][j].pb(mp(ni,nj));
            }
            rep(ct,m)
            {
                if (ct>j) continue;
                int ni=i+tail[ct].x;
                int nj=j-ct+tail[ct].y;
                if (ni+nj>r) sm[i][j].pb(mp(r,r)); else
                sm[i][j].pb(mp(ni,nj));
            }
        }
    }
    rept(i,r+1)
    {
        rept(j,r+1)
        {
            SORT(sm[i][j]);
            sm[i][j].resize(unique(all(sm[i][j]))-sm[i][j].begin());
        }
    }
    memset(ds,-1,sizeof(ds));
    memset(win,-1,sizeof(win));
    win[h][t]=1; //win[r][r]=0;
    ds[h][t]=0; //ds[r][r]=0;
    q.push(mp(h,t)); //q.push(mp(r,r));
    while (!q.empty())
    {
        int ci=q.front().x;
        int cj=q.front().y;
        q.pop();
        rept(i,L(sm[ci][cj]))
        {
            int ni=sm[ci][cj][i].x;
            int nj=sm[ci][cj][i].y;
            if (win[ci][cj]==1)
            {
                if (win[ni][nj]!=-1) continue;
                win[ni][nj]=1;
                ds[ni][nj]=ds[ci][cj]+1;
                q.push(mp(ni,nj));
            }
        }
    }
    if (win[0][0]==1)
    {
        puts("Ivan");
        printf("%d\n",ds[0][0]);
        exit(0);
    }
    if (win[r][r]==-1)
    {
        puts("Draw");
        exit(0);
    }
    memset(ds,-1,sizeof(ds));
    int a=rec(h,t);
    if (a==INF)
    {
        puts("Draw");
        exit(0);
    }
    puts("Zmey");
    printf("%d\n",a);
}

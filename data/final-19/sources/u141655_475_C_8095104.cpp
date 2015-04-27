#pragma comment(linker,"/STACK:102400000,102400000")
//#include <bits/stdc++.h>

#include <cstdio>
#include <set>
#include <map>
#include <ctime>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <queue>
#include <vector>

#define dte(x) cout << #x << " = " << x << endl;
#define scaf2(x,y) scaf(x), scaf(y)
#define mkp make_pair
  
using namespace std;
template<typename T>inline void scaf(T&v)
{
    char ch = getchar(); int sgn = 1;
    for(; '-' != ch && (ch < '0' || ch > '9'); ch = getchar()); if ('-' == ch) sgn = -1,v = 0; else v = ch - '0';
    for(ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar()) v = (v << 1) +(v << 3) + ch - '0'; v *= sgn;
}
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> PII;
const int maxN = 1e3 + 10;
const int mod = 1e9 + 7;
const double eps = 1e-4;
//const double pi = acos(-1.0);

#define sum(x1,y1,x2,y2) (g[x2][y2]-g[x1-1][y2]-g[x2][y1-1]+g[x1-1][y1-1])

int n,m,g[maxN][maxN],answer=INT_MAX;
char str[maxN][maxN];

int dfs(int x,int y,int wx,int wy)
{
    if(sum(x,y+1,x+wx-1,y+wy)==wx*wy) return wx+dfs(x,y+1,wx,wy);
    if(sum(x+1,y,x+wx,y+wy-1)==wx*wy) return wy+dfs(x+1,y,wx,wy);
    return 0;
}

int main()
{
    scanf("%d%d",&n,&m);
    int flag=0,px,py;
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(str[i][j]=='X')
            {
                if(!flag) {flag=1;px=i;py=j;}
                g[i][j]=g[i-1][j]+g[i][j-1]-g[i-1][j-1]+1;
            }
            else g[i][j]=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
        }
    int tmp,wx,wy;
    for(tmp=px;str[tmp][py]=='X';tmp++);
    wx=tmp-px;
    for(int i=py;str[px][i]=='X';i++)
        if(dfs(px,py,wx,i-py+1)+wx*(i-py+1)==g[n][m])answer=min(answer,wx*(i-py+1));
    for(tmp=py;str[px][tmp]=='X';tmp++);
    wy=tmp-py;
    for(int i=px;str[i][py]=='X';i++)
        if(dfs(px,py,i-px+1,wy)+(i-px+1)*wy==g[n][m])answer=min(answer,(i-px+1)*wy);
    if(answer<=n*m) printf("%d\n",answer);
    else printf("-1\n");
    return 0;
}
/*
4 4
....
XXXX
..XX
....

....
..xx
x.xx
....

*/

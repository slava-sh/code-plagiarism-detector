#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

int H,T,R,n,m;
int h[2][300],t[2][300];
bool draw=false;
int zm=0;
int d[300][300],c[300][300];
int q[2][200000];
int b=0,e=1;

void dfs(int a,int b)
{
    c[a][b]=1;
    for (int i=1;i<=min(n,a);i++)
        if ((a+b-i+h[0][i]+t[0][i])<=R){
            if (c[a-i+h[0][i]][b+t[0][i]]==1) draw=true;
            if (c[a-i+h[0][i]][b+t[0][i]]==0) dfs(a-i+h[0][i],b+t[0][i]);
        }
    for (int i=1;i<=min(m,b);i++)
        if ((a+b-i+h[1][i]+t[1][i])<=R){
            if (c[a+h[1][i]][b-i+t[1][i]]==1) draw=true;
            if (c[a+h[1][i]][b-i+t[1][i]]==0) dfs(a+h[1][i],b-i+t[1][i]);
        }
    c[a][b]=2;
}

void bfs()
{
    for (int i=0;i<300;i++)
        for (int j=0;j<300;j++) d[i][j]=100500;
    d[H][T]=0;
    q[0][0]=H;q[1][0]=T;
    int u[2];
    while (d[0][0]==100500&&b!=e){
        u[0]=q[0][b];u[1]=q[1][b];
        b++;
        if (b==200000) b=0;
        for (int i=1;i<=min(n,u[0]);i++)
            if ((u[0]+u[1]-i+h[0][i]+t[0][i])<=R){
                if (d[u[0]-i+h[0][i]][u[1]+t[0][i]]==100500){
                    d[u[0]-i+h[0][i]][u[1]+t[0][i]]=d[u[0]][u[1]]+1;
                    q[0][e]=u[0]-i+h[0][i];
                    q[1][e]=u[1]+t[0][i];
                    e++;
                    if (e==200000) e=0;
                }else{
                    if ((!draw)&&d[u[0]-i+h[0][i]][u[1]+t[0][i]]<=d[u[0]][u[1]]){
                        d[u[0]-i+h[0][i]][u[1]+t[0][i]]=d[u[0]][u[1]]+1;
                        q[0][e]=u[0]-i+h[0][i];
                        q[1][e]=u[1]+t[0][i];
                        e++;
                        if (e==200000) e=0;
                    }
                }
            }else zm=d[u[0]][u[1]]+1;
        for (int i=1;i<=min(m,u[1]);i++)
            if ((u[0]+u[1]-i+h[1][i]+t[1][i])<=R){
                if (d[u[0]+h[1][i]][u[1]-i+t[1][i]]==100500){
                    d[u[0]+h[1][i]][u[1]-i+t[1][i]]=d[u[0]][u[1]]+1;
                    q[0][e]=u[0]+h[1][i];
                    q[1][e]=u[1]-i+t[1][i];
                    e++;
                    if (e==200000) e=0;
                }else{
                    if ((!draw)&&d[u[0]+h[1][i]][u[1]-i+t[1][i]]<=d[u[0]][u[1]]){
                        d[u[0]+h[1][i]][u[1]-i+t[1][i]]=d[u[0]][u[1]]+1;
                        q[0][e]=u[0]+h[1][i];
                        q[1][e]=u[1]-i+t[1][i];
                        e++;
                        if (e==200000) e=0;
                    }
                }
            }else zm=d[u[0]][u[1]]+1;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>H>>T>>R;
    cin>>n;
    for (int i=1;i<=n;i++) scanf("%d%d",&h[0][i],&t[0][i]);
    cin>>m;
    for (int i=1;i<=m;i++) scanf("%d%d",&h[1][i],&t[1][i]);
    for (int i=0;i<300;i++)
        for (int j=0;j<300;j++) c[i][j]=0;
    dfs(H,T);
    bfs();
    if (d[0][0]==100500){
        if (draw) printf("Draw\n");
        else printf("Zmey\n%d\n",zm);
    }else printf("Ivan\n%d\n",d[0][0]);
    return 0;
}

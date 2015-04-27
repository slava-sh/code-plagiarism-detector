#include<bits/stdc++.h>
using namespace std;
char G[1005][1005];
int ok(int U,int D,int L,int R)
{
    if(G[U][R+1]=='X'&&G[D+1][L]=='X')  return 0;
    if(G[U][R+1]=='X'){
        for(int i=U;i<=D;i++)
            if(G[i][R+1]!='X')
                return 0;
        return ok(U,D,L+1,R+1);
    }
    if(G[D+1][L]=='X'){
        for(int i=L;i<=R;i++)
            if(G[D+1][i]!='X')
                return 0;
        return ok(U+1,D+1,L,R);
    }
    for(int i=U;i<=D;i++)
        if(G[i][R+1]=='X')
            return 0;
    for(int i=L;i<=R;i++)
        if(G[D+1][i]=='X')
            return 0;
    return 1;
}
int main()
{
    //freopen("c.txt","r",stdin);
    int n,m,i,j;
    while(~scanf("%d%d",&n,&m)){
        for(i=1;i<=n;i++)
            scanf("%s",G[i]+1);
        int cnt=0,flag=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++){
                if(G[i-1][j]!='X'&&G[i][j-1]!='X'&&G[i][j]=='X')  cnt++;
                if(G[i][j]=='X'&&G[i][j+1]=='X'&&G[i+1][j]=='X'&&G[i+1][j+1]=='.')  flag|=1;
                if(G[i][j]=='.'&&G[i][j+1]=='X'&&G[i+1][j]=='X'&&G[i+1][j+1]=='X')  flag|=1;
            }
        if(cnt>1||flag)  {printf("-1\n");continue;}
        int I,J;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                if(G[i][j]=='X'){
                    I=i,J=j;
                    goto mark1;
                }
        mark1: 1;
        int R,D;
        for(R=J;G[I][R]=='X';R++);R--;
        for(D=I;G[D][J]=='X';D++);D--;
        int ans=100000000;
        for(i=J;i<=R;i++)
            if(ok(I,D,J,i)){
                ans=min(ans,(D-I+1)*(i-J+1));
                break;
            }
        for(i=I;i<=D;i++)
            if(ok(I,i,J,R)){
                ans=min(ans,(i-I+1)*(R-J+1));
                break;
            }
        printf("%d\n",ans==100000000?-1:ans);
    }
    return 0;
}

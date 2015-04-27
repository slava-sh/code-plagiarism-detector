#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 1010
#define each(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;
typedef long long LL;
char map[maxn][maxn];
int col[maxn][maxn];
int nRow,nCol,all;
int movex[]={1,0,0,-1};
int movey[]={0,1,-1,0};
int s[maxn][maxn];
void read()
{
    scanf("%d %d",&nRow,&nCol);
    for(int i=1;i<=nRow;++i)
    {
        scanf("%s",map[i]+1);
        for(int j=1;j<=nCol;++j)
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(map[i][j]=='X');
    }
}
void BFS(int a,int b,int c)
{
    static int x[maxn*maxn],y[maxn*maxn];
    int front=0,rear=1;
    x[rear]=a,y[rear]=b,col[a][b]=c;
    while(front<rear)
    {
        ++front;
        for(int i=0;i<4;++i)
        {
            int px=x[front]+movex[i],py=y[front]+movey[i];
            if(map[px][py]=='X'&&!col[px][py])
            {
                col[px][py]=c;
                ++rear,x[rear]=px,y[rear]=py;
            }
        }
    }
    all=rear;
}
int getsum(int a,int b,int c,int d)
{
    return s[c][d]-s[a-1][d]-s[c][b-1]+s[a-1][b-1];
}
int calc(int row,int col,int x,int y)
{
    if(getsum(x,y,x+row-1,y+col-1)!=row*col)
        return 1<<30;
    if(map[x+row][y]=='X'&&map[x][y+col]=='X')
        return 1<<30;
    if(map[x+row][y]!='X'&&map[x][y+col]!='X')
        return 0;
    if(map[x+row][y]=='X')
        return col+calc(row,col,x+1,y);
    else
        return row+calc(row,col,x,y+1);
}
void work()
{
    int cnt=0,px,py;
    for(int i=1;i<=nRow;++i)
        for(int j=1;j<=nCol;++j)
            if(map[i][j]=='X'&&!col[i][j])
                BFS(i,j,++cnt),px=i,py=j;
    if(cnt>1)
    {
        printf("-1\n");
        return ;
    }
    int row,col,ans=1<<30;
    for(row=1;map[px+row-1][py]=='X';++row);
    for(col=1;map[px][py+col-1]=='X';++col);
    --row,--col;
    for(int i=1;i<=col;++i)
        if(calc(row,i,px,py)+row*i==all)
        {
            ans=min(ans,row*i);
            break;
        }
    for(int i=1;i<=row;++i)
        if(calc(i,col,px,py)+i*col==all)
        {
            ans=min(ans,i*col);
            break;
        }
    printf("%d\n",ans==1<<30?-1:ans);
}
int main()
{
    read();
    work();
    return 0;
}

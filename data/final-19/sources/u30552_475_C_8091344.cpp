

#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<map>
#include<bitset>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define MS0(x) memset(x,0,sizeof(x))


typedef long long LL;
using namespace std;

int n,m;

char s[1100][1100],ss[1100][1100];
int ans=-1;

void de(int x1,int y1,int x2,int y2){
    FOR(i,x1,x2)FOR(j,y1,y2)ss[i][j]='.';
}
int kind(int x1,int y1,int x2,int y2){
    FOR(i,x1,x2)FOR(j,y1,y2)if(ss[i][j]!='X')return 0;
    return 1;
}

void GO(int x,int y,int xx,int yy){
    while(kind(x+xx,y,x+xx,y+yy-1) || kind(x,y+yy,x+xx-1,y+yy))
    {
        if(kind(x+xx,y,x+xx,y+yy-1))
        {
            de(x+xx,y,x+xx,y+yy-1);
            x++;
        }
        if(kind(x,y+yy,x+xx-1,y+yy))
        {
            de(x,y+yy,x+xx-1,y+yy);
            y++;
        }
    }
}

void work1(int x,int y){
    FOR(i,0,1010)FOR(j,0,1010)ss[i][j]='.';
    FOR(i,1,n)FOR(j,1,m)ss[i][j]=s[i][j];

    int yy=y,xx=-1;
    while(s[x][yy+1]=='X')yy++;
    FOR(i,1,n)if(ss[i][yy+1]=='X'){
        xx=i;
        break;
    }

    if(xx<x&&xx!=-1)return;

    int x1=x;
    while(ss[x1+1][y]=='X')x1++;
    if(xx>x1)return;

    if(xx==-1)xx=1;else xx=x1-xx+1;
    yy=yy-y+1;
    FOR(i,x,x+xx-1)FOR(j,y,y+yy-1)if(ss[i][j]!='X')return;
    FOR(i,x,x+xx-1)FOR(j,y,y+yy-1)ss[i][j]='.';

    GO(x,y,xx,yy);
    FOR(i,1,n)FOR(j,1,m)if(ss[i][j]=='X')return;

    if(ans==-1||xx*yy<ans)ans=xx*yy;
}


void deal(int x,int y){
    work1(x,y);
    FOR(i,0,1010)FOR(j,0,1010)ss[i][j]=s[j][i];
    FOR(i,0,1010)FOR(j,0,1010)s[i][j]=ss[i][j];

    swap(n,m);
    work1(y,x);
    cout<<ans<<endl;
    exit(0);
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n)scanf("%s",s[i]+1);

    FOR(i,1,n)FOR(j,1,m)if(s[i][j]=='X')deal(i,j);
}











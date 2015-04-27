#include<stdio.h>
#include<algorithm>
using namespace std;
bool G[1000][1000] ;
int nownum,m,n ;

bool check(int a,int b,int c,int d)
{
    for(int i=a;i<=c;i++) for(int j=b;j<=d;j++)
        if(!G[a][b]) return false ;
    return true ;
}

bool go(int a,int b,int c,int d)
{
    if(nownum==0) return true ;
    if(c<n-1 && G[c+1][b] && d<m-1 && G[a][d+1]) return false ;
    if(c<n-1 && G[c+1][b])
    {
        if(!check(c+1,b,c+1,d)) return false ;
        nownum-=d-b+1 ;
        if(go(a+1,b,c+1,d)) return true ;
    }
    else if(d<m-1 && G[a][d+1])
    {
        if(!check(a,d+1,c,d+1)) return false ;
        nownum-=c-a+1 ;
        if(go(a,b+1,c,d+1)) return true ;
    }
    return false ;
}

main()
{
    int st1=-1,st2=-1,no=0,num=0 ;
    scanf("%d %d",&n,&m) ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    {
        char c ;
        scanf("%c",&c) ;
        while(c!='X' && c!='.') scanf("%c",&c) ;
        if(c=='X')
        {
            G[i][j]=1 ; num++ ;
            if(st1==-1) {st1=i ; st2=j ;}
            else if(i>st1 && j<st2) no=1 ;
        }
        else G[i][j]=0 ;
    }
    if(no) {printf("-1") ; return 0 ;}
    int right,down ;
    for(right=st2;right<m && G[st1][right];right++) ; right-- ;
    for(down=st1;down<n && G[down][st2];down++) ; down-- ;
    if(!check(st1,st2,down,right)) {printf("-1") ; return 0 ;}
    int ans=2100000000 ;
    for(int i=st1;i<=down;i++)
    {
        nownum=num-(i-st1+1)*(right-st2+1) ;
        if(go(st1,st2,i,right)==1)
        {
            ans=(i-st1+1)*(right-st2+1) ;
            break ;
        }
    }
    for(int i=st2;i<=right;i++)
    {
        nownum=num-(i-st2+1)*(down-st1+1) ;
        if(go(st1,st2,down,i)==1)
        {
            ans=min(ans,(i-st2+1)*(down-st1+1)) ;
            break ;
        }
    }
    if(ans!=2100000000) printf("%d\n",ans) ;
    else printf("-1\n") ;
}

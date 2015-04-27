#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1007;

int s[maxn][maxn];
int a[maxn][maxn];
char buf[maxn];
int m,n,X0,Y0;

int sum(int x1, int y1, int x2, int y2){
    return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}

bool ok(int i, int j, int x, int y){
    if(i>m || j>n) return 0;
    int i2=i+x-1, j2=j+y-1;
    return(i2<=m && j2<=n && sum(i,j,i2,j2)==x*y);
}

bool go(int hh, int ww, int x, int y, bool extendH, int sum1, int &finalX){
    bool goDown, goRight;
    goDown = ok(x+1,y,hh,ww);
    goRight = ok(x,y+1,hh,ww);
    if(goDown && goRight){
        //extend
        if(extendH){
            return go(hh+1,ww,x,y,extendH,sum1,finalX);
        }else{
            return go(hh,ww+1,x,y,extendH,sum1,finalX);
        }
    }else if(goDown){
        return go(hh,ww,x+1,y,extendH,sum1+ww,finalX);
    }else if(goRight){
        return go(hh,ww,x,y+1,extendH,sum1+hh,finalX);
    }else{
        //stop and check
        int total = sum1 + hh*ww;
        if(total<s[m][n]) return 0;

        if(extendH) finalX = hh;
        else finalX = ww;

        return 1;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&m,&n);
    reset(s,0);
    X0=-1;
    for(int i=1; i<=m; ++i){
        scanf("%s",buf+1);
        for(int j=1; j<=n; ++j){
            a[i][j]=(buf[j]=='X');
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
            if(a[i][j] && X0==-1){
                X0=i; Y0=j;
            }
        }
    }

    int w=1,h=1;
    while(X0+h<=m && a[X0+h][Y0]==1) ++h;
    while(Y0+w<=n && a[X0][Y0+w]==1) ++w;

    int res=oo;
    int x,x2;
    if(go(1,w,X0,Y0,1,0,x) && go(x,w,X0,Y0,1,0,x2)){
        if(x==x2) res=min(res,x*w);
    }
    if(go(h,1,X0,Y0,0,0,x) && go(h,x,X0,Y0,0,0,x2)){
        if(x==x2) res=min(res,h*x);
    }

    if(res==oo) puts("-1");
    else printf("%d\n",res);

    return 0;
}

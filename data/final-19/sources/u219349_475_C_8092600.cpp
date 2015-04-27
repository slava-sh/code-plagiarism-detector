#include <iostream>
#include <cstdio>
using namespace std;

int N,M, a[1010][1010], sum[1010][1010],x,y,total;

int summ(int x1, int y1, int x2, int y2){
    return sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
}

bool paint(int w, int h){
    int cnt=w*h;
    int x2=x+h-1;
    int y2=y+w-1;
    if (summ(x,y,x2,y2)!=w*h)
        return 0;

    int x1=x, y1=y;

    while (summ(x2+1,y1,x2+1,y2)==w || summ(x1,y2+1,x2,y2+1)==h){
        if (summ(x2+1,y1,x2+1,y2)==w){
            cnt+=w;
            x1++;
            x2++;
        }

        if (summ(x1,y2+1,x2,y2+1)==h){
            cnt+=h;
            y1++;
            y2++;
        }

    }

    if (cnt!=total)
        return 0;
    return 1;

}

int main(){
    scanf("%d %d",&N,&M);

    int i,j,w,h; char c;
    for (i=1; i<=N; i++)
        for (j=1; j<=M; j++){
            cin >> c;
            if (c=='X')
                a[i][j]=1, total++;
            if (a[i][j]==1 && x==0)
                x=i,y=j;
        }


    for (i=1; i<=N; i++)
        for (j=1; j<=M; j++)
            sum[i][j]=a[i][j]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];


    w=1; int res=(1<<30);
    for (i=y+1; a[x][i]==1; i++)
        w++;

    for (j=1; x+j-1<=N; j++)
        if (paint(w,j))
            res=min(res,w*j);

    h=1;
    for (i=x+1; a[i][y]==1; i++)
        h++;

    for (j=1; y+j-1<=M; j++)
        if (paint(j,h))
            res=min(res,j*h);

    if (res==(1<<30))
        cout << -1;
    else
        cout << res;

    return 0;
}

#include<math.h>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<stdio.h>
#include<map>
#include<set>
#include<string>
#include<assert.h>
#include<vector>
#include<ctime>
#include<queue>
#include<deque>
#include<sstream>
#include<stack>
#include<sstream>
#define MA(a,b) ((a)>(b)?(a):(b))
#define MI(a,b) ((a)<(b)?(a):(b))
#define AB(a) (-(a)<(a)?(a):-(a))
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define ep 0.0000000001
#define pi 3.1415926535897932384626433832795
#define na(x) ((x)<P?(x):(x)-P)
using namespace std;
const int N=509;
int n,m,k,x,y;
long long M,D[N*2+10][N*2+10];
int a[N][N];
int b[N],d[N];
int main()
{
    cin>>n>>m>>M;
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
                char C='@';
                while (C!='0' && C!='1') C=getchar();
            a[i][j]=C-'0';
            b[i]+=a[i][j];
            d[j]+=a[i][j];
            if (d[j]>2) {cout<<0<<endl; return 0;}
        }
        if (b[i]!=2) {cout<<0<<endl; return 0;}
    }
    for (int i=1;i<=n;i++)
        if (d[i]==1) x++; else
        if (d[i]==0) y++;
    if (x+y*2!=(n-m)*2) {cout<<0<<endl; return 0;}
    if (y>0 && n-m<2)  {cout<<0<<endl; return 0;}
    D[0][0]=1;
    for (int i=0;i<N*2;i++)
    for (int j=0;j<N*2;j++)
    {
        if (i>1) D[i][j]=(D[i][j]+D[i-2][j+2]*(i*(i-1)/2))%M;
        if (i>0 && j>0) D[i][j]=(D[i][j]+D[i-1][j]*i*j)%M;
        if (j>1) D[i][j]=(D[i][j]+D[i][j-2]*(j*(j-1)/2))%M;
    }
    cout<<D[y][x]<<endl;

    return 0;
}

#include<cmath>
#include<cstdio>
#include<cctype>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define for1(i,a,b) for(i=(a);i<(b);i++)
#define for2(i,a,b) for(i=(a);i>(b);i--)
#define same(a) memset((a),0,sizeof(a));
#define ll long long

int cmpint(const void*a,const void *b)
{
    return ((int*)a)[0]-((int*)b)[0];
}


int a[100005][2];
int b[100005][3];
int ans=0;

int downmove(int child,int n){
    int k,l,i;
    while(1){
        i=child;
        k=child*2+1;
        l=child*2+2;
        if(k>=n) break;
        if(l>=n||a[k][1]>=a[l][1]) child=k;
        else child=l;
        if(a[i][1]>=a[child][1]) break;
        k=a[i][1];a[i][1]=a[child][1];a[child][1]=k;
        k=a[i][0];a[i][0]=a[child][0];a[child][0]=k;
    }
    return 0;
}

int heapsort(int n){
    int i,j;
    for(i=n/2;i>=0;i--)
        downmove(i,n);
    return 0;
}


int work(int n){
    heapsort(n);
    int i,j,t;
    t=8;
    if(n<t) t=n;
    while(1){
       // for1(i,0,n) printf("s=%d %d\n",a[i][0],a[i][1]);
        if(a[0][1]==0) break;
        b[ans][0]=a[0][0];
        a[0][1]--;

        if(a[1][1]==0&&a[2][1]==0) break;
        i=1;if(a[2][1]>a[1][1]) i=2;
        b[ans][1]=a[i][0];
        a[i][1]--;

        j=3-i;
        for1(i,3,t)
          if(a[i][1]>a[j][1]) j=i;
        // printf("%d %d %d\n",j,a[j][0],a[j][1]);
        if(a[j][1]==0) break;
        b[ans][2]=a[j][0];
        a[j][1]--;

        for2(i,6,-1)
          for1(j,0,3)
            if(a[i][0]==b[ans][j]){
                downmove(i,n);
                break;
            }

        ans++;
    }
}

int main()
{
    int i,j,n,m,k,l,o,p;
    same(a);
    same(b);
    scanf("%d",&n);
    for1(i,0,n) {
        scanf("%d",&a[i][0]);
        a[i][1]=1;
    }
    qsort(a,n,sizeof(int)*2,cmpint);
    j=0;
    for1(i,1,n){
        if(a[i][0]==a[j][0])
           a[j][1]++;
        else {
            j++;
            a[j][0]=a[i][0];
            a[j][1]=1;
        }
    }
    j++;
    n=j;
    //for1(i,0,n) printf("%d %d\n",a[i][0],a[i][1]);
    if(n<3) printf("0\n");
    else{
        work(n);
        printf("%d\n",ans);
        for1(i,0,ans) {
            if(b[i][0]<b[i][1]){
                k=b[i][0];
                b[i][0]=b[i][1];
                b[i][1]=k;
            }
            if(b[i][0]<b[i][2]){
                k=b[i][0];
                b[i][0]=b[i][2];
                b[i][2]=k;
            }
            if(b[i][1]<b[i][2]){
                k=b[i][1];
                b[i][1]=b[i][2];
                b[i][2]=k;
            }
            printf("%d %d %d\n",b[i][0],b[i][1],b[i][2]);
        }
    }
    return 0;
}

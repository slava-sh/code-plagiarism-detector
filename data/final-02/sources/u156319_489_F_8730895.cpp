#include<cstdio>
using namespace std;
int f[2][505][505];//前i行 j行空 k行1方案数
int c[505][505];
char s[505][505];
long long n,m,p;
int num[505];
int main(){
    scanf("%I64d%I64d%I64d",&n,&m,&p);
    c[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%s",s[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[j][i]=='1') num[i]++;
        }
    }
    int tot2=0,tot1=0;
    for(int i=1;i<=n;i++) if(num[i]==0) tot2++;else if(num[i]==1) tot1++;
    f[(m)&1][tot2][tot1]=1;
    for(int i=m+1;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                f[i&1][j][k]=0;
            }
        }
        for(int j=0;j<=n;j++){
            for(int k=n-j;k>=0;k--){
                if(f[(i-1)&1][j][k]){
                    //i>1
                    if(j>1){
                        f[i&1][j-2][k+2]+=f[(i-1)&1][j][k]*1LL*c[j][2]%p;
                        if(f[i&1][j-2][k+2]>=p) f[i&1][j-2][k+2]%=p;
                    }
                    //j>1
                    if(k>1){
                        f[i&1][j][k-2]+=f[(i-1)&1][j][k]*1LL*c[k][2]%p;
                        if(f[i&1][j][k-2]>=p) f[i&1][j][k-2]%=p;
                    }
                    //i>0 j>0
                    if(j>0&&k>0){
                        f[i&1][j-1][k]+=f[(i-1)&1][j][k]*1LL*k*j%p;
                        if(f[i&1][j-1][k]>=p) f[i&1][j-1][k]%=p;
                    }
                }
            }
        }
    }
    printf("%d\n",f[n&1][0][0]);
//  while(1);
    return 0;
}
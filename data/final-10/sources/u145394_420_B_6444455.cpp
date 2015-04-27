#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#define N 100005
#define Mod 1000000007
using namespace std;
typedef long long LL;
int a[N];
int f[N] , c[N];
bool v[N] , b[N] , d[N];
int n , m , online;

void Solve(){
     int i , j , k;
     memset(v,0,sizeof(v));
     memset(f,0,sizeof(f));
     cin >> n >> m;
     char s[5];
     for (i=1;i<=m;++i){
         scanf("%s%d",s,&a[i]);
         if (s[0] == '+') c[i] = 1; else c[i] = 0;
         ++f[a[i]];
         v[a[i]] = 1;
     }
     memset(b,0,sizeof(b));
     memset(d,0,sizeof(d));
     int leader = a[1];
     for (i=1;i<=m;++i)
         if (c[i] == 1) b[a[i]] = 1 , d[a[i]] = 1; else {
                  if (b[a[i]] == 0){
                              if (!d[a[i]]) leader = a[i];
                  } else b[a[i]] = 0;
         }
     bool flag = 1;
     memset(b,0,sizeof(b));
     b[leader] = 1; online = 1;
     for (i=1;i<=m;++i){
         if (c[i] == 1){
                  if (!b[a[i]]) ++online; b[a[i]] = 1; 
         }else
            if (b[a[i]] == 1) b[a[i]] = 0 , --online;
         if (b[leader] == 0 && online) flag = 0;
     }
     if (flag) v[leader] = 0;
     int ans = 0;
     for (i=1;i<=n;++i)
         if (!v[i]) ++ans;
     printf("%d\n",ans);
     for (i=1;i<=n;++i)
         if (!v[i])
            if (ans > 1) printf("%d ",i) , --ans;  else printf("%d\n",i);
     
}

int main(){
    int test;
    Solve();
    cin >> n;
    return 0;
}

#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<set>
#define LL long long 
#define Pi 3.14159265358
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
LL n, m, k, i, j,ans;
LL a[400001];
main(){
       freopen("sochi.in","r",stdin);
       freopen("sochi.out","w",stdout);
       cin>>n;
       cin>>k;
       for(i=1;i<=n;i++)cin>>a[i];
       for(i=1;i<=n;i++)ans=max(ans,a[i]);
      for(i=1;i<=n;i++){
                         if(a[i]>2*k)m=a[i]+m-2*k;
                         }
       cout<<max(m+2*k,ans);
       //system("pause");
       }

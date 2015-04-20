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
LL n, m, k, i, j;
LL a[400001];
pair < int , int > p;
main(){
       freopen("sochi.in","r",stdin);
       freopen("sochi.out","w",stdout);
       cin>>n;
       cin>>k;
       for(i=1;i<=n;i++)cin>>a[i]; 
       sort(a+1,a+n+1);
       reverse(a+1,a+n+1);
       m=a[1];
       p=mp(a[1],a[1]);
       for(i=2;i<=n;i++){
                         if(max(p.fi,p.se)<=k)break;
                         if(p.se>=k){
                                     p.se=a[i]-k;
                                     }
                         else p.fi=a[i]-k;
                         m=m+a[i]-2*k;
                         }
                         cout<<m;
      // system("pause");
       }


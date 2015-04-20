#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue> 
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define inf 2000000000
#define For(i,s,n) for (int i=s;i<=n;i++)
#define FOR(i,s,n) for (int i=s;i<n;i++)
#define Ford(i,s,n) for (int i=s;i>=n;i--)
#define MD 1000000007


typedef long long ll;

using namespace std;
ll n,m,a[1000000];
int main(){
    freopen("che.in","r",stdin); freopen("che.out","w",stdout);
    cin>>n>>m;
    For(k,1,n){
               cin>>a[k];
               }
    ll res=0,j=2,k=1;
    while(k<=n){
                if (a[j]-m>a[k]){ res+=n-j+1; k++; }
                else j++;
                if (j>n) break;
                }
    cout<<res<<endl;
    return 0;
}

















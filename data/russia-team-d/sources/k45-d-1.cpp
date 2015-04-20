#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define sz(A) (int(A.size()))

using namespace std;
typedef long long ll;
int n;ll k;
ll a[111111];

bool can(ll x){
    ll res=0;
    for(int i=1;i<=n;++i){
        //if(a[i]<x)return 0;
        res+=max(x,a[i]-res);
    }
    return res<=k;
}
int main(){
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    int i;
    cin>>n>>k;
    for(i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll l=0,r=a[1]+1;
    while(r-l>1){
        ll m=(l+r)/2;
        if(can(m))l=m;
        else r=m;
    }
    cout<<l;
    return 0;
}

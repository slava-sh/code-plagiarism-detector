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
long long a[333333],r;
int n;
long long ans=0;
int main(){
    freopen("che.in","r",stdin);
    freopen("che.out","w",stdout);
    int i,j;
    cin>>n>>r;
    for(i=1;i<=n;++i){
        cin>>a[i];
    }

    for(i=1;i<=n;++i){
        int pos=upper_bound(a+1,a+n+1,a[i]+r)-a;
        //cout<<i<<' '<<pos<<endl;
        ans+=n-pos+1;
    }
    cout<<ans;

    return 0;
}

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
int n,d;
int a[111111];

int main(){
    freopen("sochi.in","r",stdin);
    freopen("sochi.out","w",stdout);
    int i,j,k;
    int len=0;
    cin>>n>>d;
    for(i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    bool was=0;
    for(i=n;i>=1;--i){
        if(a[i]<3*d)break;
        len+=a[i];
        was=1;
    }
    if(was)len-=(n-i-1)*2*d;

    for(j=1;j<=2;++j){
        if(i>=1 && a[i]>=d*2){
            if(was)len+=a[i]-d-d;
            else len+=a[i]-d;
            --i;
        }
    }
    cout<<max(len,a[n]);


    return 0;
}

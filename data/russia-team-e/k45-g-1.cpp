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
int main(){
    freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==1 && m==1){cout<<0;return 0;}
    int ans1=2*int(1e9),ans2=2*int(1e9);
    if(n!=1)ans1=(n-2+3)/4;
    if(m!=1)ans2=(m-2+3)/4;
    cout<<min(ans1,ans2);


    return 0;
}

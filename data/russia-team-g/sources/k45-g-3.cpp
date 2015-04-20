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
    if(n>2 && m>2){cout<<1;return 0;}

    int ans1=2*int(1e9),ans2=2*int(1e9);
    if(n==2)ans1=0;
    else if(n>2)ans1=(n-3)/4+1;
    if(m==2)ans2=0;
    else if(m>2)ans2=(m-3)/4+1;

    cout<<min(ans1,ans2);


    return 0;
}

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
ll n,m;
int main(){
    freopen("prizes.in","r",stdin); freopen("prizes.out","w",stdout);
    cin>>n>>m;
    if (n>m) swap(n,m);
    if (n<=2&&m<=2) cout<<0<<endl; else cout<<1<<endl;
    return 0;
}
















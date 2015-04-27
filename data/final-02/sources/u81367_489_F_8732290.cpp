#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 505

LL dp[SIZE][SIZE];

int n,m;
LL mod;

int cnt[SIZE];
char str[SIZE];

LL func( int totake,pint var ){

    if ( totake == n ){
        return 1;
    }

    LL&ret = dp[totake][var.X];

    if ( ret != -1 )return ret;

    ret = 0;
    if ( var.X >= 2 ){
        ret += LL(var.X)*(var.X-1)/2 * func( totake+1, MP(var.X-2,var.Y+2) );
        ret %= mod;
    }
    if ( var.X>=1 && var.Y>=1 ){
        ret += LL( var.X ) * LL(var.Y) * func(totake+1, MP(var.X-1,var.Y) );
        ret %= mod;
    }
    if ( var.Y>= 2 ){
        ret += LL(var.Y)*(var.Y-1)/2 *func(totake+1, MP(var.X,var.Y-2) );
        ret %= mod;
    }
    ret %= mod;
    //cout<<totake<<" "<<var.X<<" "<<var.Y<<" "<<ret<<endl;

    return ret;
}

int main(){

   

    scanf("%d %d %I64d",&n,&m,&mod);

    NEG(dp);

    for (int i=0;i<m;++i){
        scanf("%s",str);
        for (int j=0;str[j];++j){
            if ( str[j] == '1' ){
                cnt[j]++;
            }
        }
    }

    pint var=MP(0,0);

    for (int i=0;i<n;++i){
        if ( cnt[i] == 0 ){
            var.X++;
        }else if ( cnt[i] == 1 ){
            var.Y++;
        }
    }
    //cout<<m<<" "<<var.X<<" "<<var.Y<<endl;
    printf("%I64d\n",func(m,var));
    return 0;
}

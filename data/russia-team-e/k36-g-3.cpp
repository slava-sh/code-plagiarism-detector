#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <time.h>
#include <cassert>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
int main () {
    int i,j,n,m,c=0;
    freopen ("prizes.in", "r", stdin);
    freopen ("prizes.out", "w", stdout);

    cin >> n>>m;
    if(n>m)swap(n,m);
    if(n==1){
        if(m>=3)m-=3,c++;
        if(m>=4)c+=m/4;
        m=0;
    }
    else{
        if(n>=3)n-=3,c++;
        if(n>=4)c+=n/4;
    }
    cout<<c<<endl;
    return 0;
}

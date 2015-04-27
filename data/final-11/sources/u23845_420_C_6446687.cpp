#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <climits>

using namespace std;

#define MAXN 500010

typedef long long ll;
typedef pair<int,int> ii;

map<ii,int> mymap;
map<ii,int>::iterator it;
int cnt[MAXN];

int main(){
    int n,k;
    scanf(" %d %d",&n,&k); 
    
    int a,b;
    for(int i = 0 ; i < n ; i++){
    scanf(" %d %d",&a,&b);
    a--;b--;
    if(a > b) swap(a,b);
    
    mymap[ii(a,b)]++;
    cnt[a]++;
    cnt[b]++;
    }
    
    
    ll ans1 = 0LL;
    ll x  = 0LL;
    for(it = mymap.begin() ; it != mymap.end() ; it++){
    ii aux = it->first;
    a = aux.first;
    b = aux.second;
    if(cnt[a] + cnt[b] >= k){
        x++;
    }
    
    if(cnt[a] + cnt[b] - it->second >= k)
        ans1++;
    }   
    sort(cnt,cnt + n);
    ll ans2 = 0LL;
    for(int i = 0 ; i < n ; i++){
    int ini = i + 1;
    int fim = n - 1;
    int ans = n;
    while(ini <= fim){
        int mid = (ini + fim)/2;
        if(cnt[mid] + cnt[i] >= k){
        ans = mid;
        fim = mid - 1;
        }
        else ini = mid + 1;
    }   
    ans2 += ll(n - ans);
    }
    printf("%I64d\n",ans1+ans2-x);
    return 0;
}

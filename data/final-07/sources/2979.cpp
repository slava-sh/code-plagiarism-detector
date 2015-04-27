#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

pair <int, int> p[10010];
set <pair <int, int> > ans;

void dfs(int low, int high){
    if(low >= high) return;
    
    int mid = (high + low) / 2;
    int x = p[mid].first;
    int i;
    for(i=low;i<=high;i++) ans.insert(make_pair(x,p[i].second));
    
    int low2 = mid, high2 = mid;
    while(low2 > low && p[low2].first == x) low2--;
    while(high2 < high && p[high2].first == x) high2++;
    dfs(low,low2); dfs(high2,high);
}

int main(void){
    int N,i;
    
    scanf("%d",&N);
    REP(i,N) scanf("%d%d",&p[i].first,&p[i].second);
    sort(p,p+N);
    REP(i,N) ans.insert(p[i]);
    dfs(0,N-1);
    
    printf("%d\n",ans.size());
    foreach(ans,itr){
        int x = (itr->first);
        int y = (itr->second);
        printf("%d %d\n",x,y);
    }
    
    return 0;
}

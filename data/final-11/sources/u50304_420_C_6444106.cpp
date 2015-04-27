#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define mp make_pair

const int N = 300005;
map<pair<int,int>, int> M;
int a[N], b[N], tot[N];
int main(){
    int n, p, i;
    scanf("%d%d",&n,&p);
    for(i=1;i<=n;++i){
        scanf("%d%d",&a[i],&b[i]);
        if(a[i]>b[i]) swap(a[i],b[i]);
        M[mp(a[i],b[i])]++;
        tot[a[i]]++;
        tot[b[i]]++;
    }


    long long ans = 0;
    for(map<pair<int,int> ,int>::iterator e = M.begin(); e != M.end(); ++e){
        int res = tot[e->first.first]+tot[e->first.second];
        if(res >= p && res - e->second < p) ans--;
    }

    sort(tot+1, tot+n+1);
    int now = n;
    for(i=1;i<=n;++i){
        now = max(now, i);
        while(tot[i]+tot[now] >= p && now>i) --now;
        ans += n-now;
    }
    cout << ans << endl;


    return 0;
}

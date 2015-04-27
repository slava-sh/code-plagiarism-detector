#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
#define MOD 1000000007ll

int N,K;
char buf[100010];
int a[100010];

ll ten[100010];
ll f[100010],inv[100010],finv[100010];

ll comb(int N, int K){
    if(!(0 <= K && K <= N)) return 0;
    return f[N] * finv[K] % MOD * finv[N-K] % MOD;
}

int main(void){
    int i;
    
    cin >> N >> K;
    scanf("%s", buf);
    
    ten[0] = 1;
    for(i=1;i<100005;i++) ten[i] = ten[i-1] * 10 % MOD;
    inv[1] = 1;
    for(i=2;i<100005;i++) inv[i] = (MOD - MOD/i) * inv[MOD%i] % MOD;
    f[0] = finv[0] = 1;
    for(i=1;i<100005;i++){
        f[i] = f[i-1] * i % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
    
    REP(i,N) a[i] = buf[i] - '0';
    
    ll ans = 0;
    REP(i,N) ans = (ans + a[i] * comb(i, K) % MOD * ten[N-1-i]) % MOD;
    
    ll tmp = 0;
    for(i=N-2;i>=0;i--){
        tmp = (tmp + comb(i, K-1) * ten[N-2-i]) % MOD;
        ans = (ans + tmp * a[i]) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}

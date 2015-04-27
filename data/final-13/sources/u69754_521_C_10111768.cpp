#include <iostream>
#include <utility>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <numeric>
#include <list>
#include <stack>
#include <cmath>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <unordered_map>
using namespace std;

typedef  long long LL;
const int Mod = 1e9 + 7;

const int N = 1e5 + 5;

int n,k;
LL sum[N],a[N],p10[N];

LL PowMod(LL x,int n) {
    LL ret = 1;
    while(n > 0) {
        if(n & 1) ret = ret * x % Mod;
        x = x * x % Mod;
        n >>= 1;
    }
    return ret;
}
LL C(int n,int k) {
    LL ret = 1;
    if(n < k) return 0;
    for(int i = n,j = 1;j <= k;j++,i--) ret = ret * i % Mod;
    for(int i = 1;i <= k;i++) {
        ret = ret * PowMod(i,Mod-2) % Mod;
    }
    return ret;
}
int main(){
    
    scanf("%d %d",&n,&k);
    string s;
    cin>>s;
    p10[0] = 1;
    for(int i = 1;i <= n;i++) p10[i] = p10[i-1] * 10 % Mod;
    for(int i = 0;i < s.length();i++) {
        sum[i + 1] = a[i + 1] = s[i] - '0';
        sum[i + 1] += sum[i];
    }
    if(k == 0) {
        //cout << sum[n] << endl;
        LL ret = 0;
        for(int i = 1;i <= n;i++) {
            ret = ret * 10 % Mod;
            ret = ret + a[i];
            ret %= Mod;
        }
        cout<<ret<<endl;
        return 0;
    }
    LL preC = C(n - 2,k - 1),preCC = C(n-1,k);
    LL ret = 0;
    for(int L = 1;L <= N;L++) {
        if(n - L < k) break;
        if(L > 1) {
            //update preC and preCC
            preC = preC * PowMod(n - (L-1) - 1,Mod-2) %Mod * (n - L - 1 - (k - 1) + 1)%Mod;
            preCC = preCC * PowMod(n - (L-1),Mod-2) % Mod * (n - L - k + 1) % Mod;
        }
        ret = ret + preC * sum[n - L] % Mod * p10[L-1] % Mod;
        ret %= Mod;
        ret = ret + preCC * a[n - L + 1] % Mod * p10[L - 1] % Mod;
        ret %= Mod;
        
    }
    cout<<ret<<endl;
    return 0;
}
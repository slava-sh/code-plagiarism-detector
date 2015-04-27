#include <bits/stdc++.h>
using LL = long long;

const int N = 100000 + 5;
const int MOD = (int) 1e9+7;

int A[N],n,K;
char str[N];
int sum[N];
int F[N],Finv[N],Inv[N];

void init() {
    Inv[1] = 1;
    for (int i = 2; i < N; ++ i) {
        Inv[i] = (LL) (MOD-MOD/i) * Inv[MOD%i] % MOD;
    }
    F[0] = Finv[0] = 1;
    for (int i = 1; i < N; ++ i) {
        F[i] = (LL) F[i-1] * i % MOD;
        Finv[i] = (LL) Finv[i-1] * Inv[i] % MOD;
    }
}

int comb(int a,int b) {
    if (b < 0 || b > a) return 0;
    return (LL) F[a] * Finv[b] % MOD * Finv[a-b] % MOD;
}

int work() {
    int ret = 0;
    for (int i = 1; i <= n; ++ i) {
        sum[i] = sum[i-1] + A[i];
    }
    for (int len = 1,base = 1; len <= n; ++ len,base = (LL) base * 10 % MOD) {
        int s = (LL) sum[n-len] * base % MOD;
        ret += (LL) s * comb(n-len-1,K-1) % MOD;
        ret %= MOD;

        s = (LL) A[n-len+1] * base % MOD;
        ret += (LL) s * comb(n-len,K) % MOD;
        ret %= MOD;
    }
    return ret;
}

int main() {
    init();
    scanf("%d%d",&n,&K);
    scanf("%s",str+1);
    for (int i = 1; i <= n; ++ i) {
        A[i] = str[i] - '0';
    }
    printf("%d\n",work());
}

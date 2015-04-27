#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<bitset>
using namespace std;
#define PII pair<int,int>
#define X first
#define Y second
#define PB push_back
#define CLR(a) memset(a, 0, sizeof(a))
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FOE(i,a,b) for (int i=(a);i<=(b);i++)
#define FIT(i,a) for (__typeof__((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define TRA(i,a,b) for (int i = (a); i != -1; i = (b)[i])
#define INF (1 << 30)
#define EPS (1e-9)
#define REP(i,n) FOR(i,0,n)
#define LL long long
#define N 510
int n, m, MOD, s;
int a[N];
int pre[N], nx[N], v[N], c[N], mat[2][N], sz;
int dp[N][N];
char ss[N];

int find(LL x, LL y){
        //printf("%d %d %d\n", x, y, dp[x][y]);
        if (x == 2 && y == 0) return 1;
        if (x == 1 && y == 0) return 0;
        if (dp[x][y] != -1) return dp[x][y];
        LL ret = 0;
        //printf("%d %d %d\n", x, y, x >= 1 && y >= 1);
        if (x && y) ret = (ret + x * y * find(x, y - 1)) % MOD;
        //printf("%d %d %d\n", x, y, ret);
        if (x >= 2) ret = (ret + x * (x - 1) * find(x - 2, y) / 2) % MOD;
        if (y >= 2) ret = (ret + y * (y - 1) * find(x + 2, y - 2) / 2) % MOD;
        return dp[x][y] = ret;
}

int main(){
        scanf("%d%d%d", &n, &m, &MOD);
        FOR(i,0,m){
                scanf("%s", ss);
                FOR(j,0,n) if (ss[j] - '0') a[j]++;
        }
        int t[3] = {0};
        FOR(i,0,n) t[2 - a[i]]++;
        if (n == m) { puts("1"); return 0; }
        memset(dp, -1, sizeof(dp));
        printf("%d\n", find(t[1], t[2]));
        return 0;
}

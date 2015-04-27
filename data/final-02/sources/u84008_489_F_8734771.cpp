#include <iostream>
#include <bitset>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, m, mod, one, two;
char need[512], s[512];
int dp[512][512];
int R, C;
int calc(int i, int n1){
    if (i == C)
        return n1 == 0;
    int n2 = (2 * C - 2 * i - n1) / 2;
    int &ret = dp[i][n1];
    if (ret != -1)
        return ret;
    ret = 0;
    if (n1 > 1){
        ret += (ll)n1*(n1 - 1) / 2 * calc(i + 1, n1 - 2) % mod;
        ret %= mod;
    }
    if (n2 > 1){
        ret += (ll)n2*(n2 - 1) / 2 * calc(i + 1, n1 + 2) % mod;
        ret %= mod;
    }
    if (n1>0 && n2>0){
        ret += (ll)n1*n2* calc(i + 1, n1) % mod;
        ret %= mod;
    }
    return ret;
}
int main()
{
    scanf("%d%d%d", &n, &m, &mod);
    memset(dp, -1, sizeof(dp));
    memset(need, 2, sizeof(need));
    for (int i = 0; i < m; ++i){
        scanf("%s", s);
        for (int j = 0; j < n; ++j){
            need[j] -= s[j] == '1';
            if (need[j] < 0){
                puts("0");
                return 0;
            }
        }
    }
    vector<int> z;
    for (int i = 0; i < n; ++i)
    if (need[i] != 0)
        z.push_back(need[i]);
    C = n - m;
    n = z.size();
    R = n;
    for (int i = 0; i < n; ++i){
        need[i] = z[i];
        one += need[i] == 1;
        two += need[i] == 2;
    }
    if (R == 0){
        puts("1");
        return 0;
    }
    printf("%d\n", calc(0, one));
    return 0;
}
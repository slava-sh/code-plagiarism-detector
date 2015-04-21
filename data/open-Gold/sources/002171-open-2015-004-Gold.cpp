#include <iostream>
#include <cstdio>

using namespace std;

long long a[200001];
long long b[200001];
long long dp[3001][3001];
const long long INF = 1e17 + 7;

int main(){
    freopen("input.txt", "r", stdin);
    int n, k;
    long long c, d;
    cin >> n >> k >> d >> c;
    a[0] = b[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            dp[i][j] = INF;
        }
    }
    dp[1][1] = (b[1] - a[1]) * c;
    for (int i = 2; i <= n; i++){
        for (long long j = 1; j <= n; j++){
            dp[i][j] = min(dp[i][j], c * (b[i] - a[i]) + min(dp[i - 1][j] + (a[i] - b[i - 1]) * c, dp[i - 1][j - 1] + ((j - 1) / k - (j - 2) / k) * d));
        }
    }
    int mn = INF;
    for (int i = 1; i <= n; i++){
        if (dp[n][i] < mn){
            mn = dp[n][i];
        }
    }
    cout << mn;
    return 0;
}

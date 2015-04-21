#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long a[200001];
long long b[200001];
long long cost[200001];
long long dp[3001][3001];
const long long INF = 1e17 + 7;

int main(){
    freopen("input.txt", "r", stdin);
    int n, k;
    long long c, d;
    cin >> n >> k >> c >> d;
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i < n; i++){
        cost[i] = a[i] - b[i - 1];
    }
    cost[0] = 0;
    sort(cost + 1, cost + n);
    for (int i = 2; i < n; i++){
        cost[i] = cost[i - 1] + cost[i];
    }
    for (int i = 1; i < n; i++){
        cost[i] *= d;
    }
    for (int i = 0; i < n; i++){
        cost[i] += ((n - i - 1) / k) * c;
    }
    long long mn = cost[0];
    for (int i = 1; i < n; i++){
        if (cost[i] < mn) mn = cost[i];
    }
    for (int i = 0; i < n; i++){
        mn += (b[i] - a[i]) * d;
    }
    cout << mn;
    return 0;
}


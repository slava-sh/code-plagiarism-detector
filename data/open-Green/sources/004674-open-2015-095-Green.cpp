#include <iostream>

using namespace std;

#define min(a, b) ((a) < (b) ? (a) : (b))

#define ll long long

int d[1000009];
int cnt = 0;

int dp[1000009][11];

int F(int N, int k)
{
    if (k == 1) return (N+1)/2;
    if (dp[N][k] != 0) return dp[N][k];

    int tmp = N;
    for (int i = 0; i < cnt; i++) {

        if (N%d[i] == 0) {
            tmp = min(tmp, ((d[i]+1)/2)*F(N/d[i], k-1) );
        }

    }

    dp[N][k] = tmp;
    return tmp;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    int k;
    cin >> N >> k;

    while (N%2==0) {
        N /= 2;
    }

    for (int i = 1; i <= N; i++) {
        if (N%i==0) d[cnt++] = i;
    }

    cout << F(N, k);

    /*
    int t = 0;
    while (N%2LL == 0){
        N /= 2LL;
        t++;
    }

    if (t >= k) {
        cout << N/(1LL<<t);
    }

    int p = k-t;

    for (ll q = 3; q*q <= N; q++) {
        if (N%q == 0) {

        }
    }
    */
}

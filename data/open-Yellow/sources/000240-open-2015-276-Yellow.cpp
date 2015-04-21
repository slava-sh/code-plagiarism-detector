#include <bits/stdc++.h>
#define dout if (true) cout

using namespace std;

typedef long long ll;

int n, q;

int road[111111];
int ans = 1;
int a, b;

int calc(int a, int b) {
    int ans = 1;
    for (int i = a; i <= b; i++) {
        if (road[i] != road[i-1])
            ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> road[i];
    }
    road[0] = road[1];
    for (int i = 1; i <= n; i++) {
        if (road[i] != road[i-1])
            ans++;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        road[0] = road[n+1] = road[n+2] = road[n+3] = road[n+4] = b;
        int prec = calc(max(a-3, 1), b+3);
        road[a] = b;
        int now = calc(max(a-3, 1), b+3);
        ans += now-prec;
        cout << ans << endl;
    }
}


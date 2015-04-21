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

void print() {
    for (int i = 1; i <= n; i++)
        cout << road[i];
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> road[i];
    }
    for (int i = 2; i <= n; i++) {
        if (road[i] != road[i-1])
            ans++;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        int old = calc(max(a-3, 2), min(a+3, n));
        //print();
        //cout << "OLD: " << old << endl;

        road[a] = b;
        int now = calc(max(a-3, 2), min(a+3, n));
        //print();
        //cout << "NOW: " << now << endl;

        ans += now-old;
        cout << ans << endl;
    }
}


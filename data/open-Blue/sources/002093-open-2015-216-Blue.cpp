#include <cstdio>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 1e5;
const int MOD = 1e9 + 7;
const int PWR = 31;

int hsh[N], n, maybe[N], cur;
int ready_hsh[2000][2000];
ll power[N];
queue <int> q;

bool cmp(int i1, int i2, int l) {
    return (ready_hsh[i1][l] == ready_hsh[i2][l]);
    ll hsh1 = ((hsh[i1 + l - 1] - hsh[i1 - 1] + MOD) * power[n - i1]) % MOD;
    ll hsh2 = ((hsh[i2 + l - 1] - hsh[i2 - 1] + MOD) * power[n - i2]) % MOD;
    return (hsh1 == hsh2);
}

int main() {
    power[0] = 1;
    for (int i = 1; i < N; i++) {
        power[i] = (power[i - 1] * PWR) % MOD;
    }
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int l;
    cin >> l;
    string s;
    cin >> s;
    n = s.length();
    hsh[0] = 0;
    for (int i = 1; i <= n; i++) {
        hsh[i] = (hsh[i - 1] + power[i] * (s[i - 1] - 'a') * (s[i - 1] - 'a')) % MOD;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i + j - 1 > n) {
                break;
            }
            ready_hsh[i][j] = ((hsh[i + j - 1] - hsh[i - 1] + MOD) * power[n - i]) % MOD;
        }
    }
    int lim = min(n, l);
    for (int i = 1; i <= lim; i++) {
        if (n % i != 0) {
            continue;
        }
        bool ok = true;
        for (int j = 1; j <= n; j += i) {
            if (cmp(1, j, i) == false) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << 1 << "\n";
            cout << s.substr(0, i) << "\n";
            return 0;
        }
    }
    for (int l1 = 1; l1 <= lim; l1++) {
        for (int i2 = l1 + 1; i2 <= n; i2++) {
            for (int l2 = 1; l2 <= lim; l2++) {
                if (i2 + l2 - 1 > n) {
                    break;
                }
                while (!q.empty()) {
                    q.pop();
                }
                cur++;
                maybe[1] = cur;
                q.push(1);
                while (!q.empty()) {
                    int x = q.front();
                    q.pop();
                    if (x == n + 1) {
                        break;
                    }
                    int p1 = x + l1;
                    if (p1 <= n + 1 && maybe[p1] != cur && cmp(1, x, l1)) {
                        maybe[p1] = cur;
                        q.push(p1);
                    }
                    int p2 = x + l2;
                    if (p2 <= n + 1 && maybe[p2] != cur && cmp(i2, x, l2)) {
                        maybe[p2] = cur;
                        q.push(p2);
                    }
                }
                if (maybe[n + 1] == cur) {
                    cout << 2 << "\n";
                    cout << s.substr(0, l1) << "\n";
                    cout << s.substr(i2 - 1, l2) << "\n";
                    return 0;
                }
            }
        }
    }
    cout << 3 << "\n";
    cout << "a" << "\n";
    cout << "b" << "\n";
    cout << "c" << "\n";
    return 0;
}
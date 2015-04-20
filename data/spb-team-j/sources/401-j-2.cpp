#include <bits\stdc++.h>

using namespace std;

const int MAXN = 2 * 1e5;
const int INF = 1e9;

int mas[MAXN], pr[MAXN];

int main(void) {
    freopen ("seq.in", "r", stdin);
    freopen ("seq.out", "w", stdout);
    int n, h;
    cin >> n >> h;
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
        pr[i] = ((i) ? pr[i - 1] : 0) + mas[i];
    }
    int l_b = n - h;
    int ans = INF;
    for (int i = n - 1; i >= 0 && l_b >= 0; i--) {
        if (mas[i] > h) {
            l_b = i - h;
        }
        else if (mas[i] > i - l_b + 1) {
            l_b = i - mas[i] + 1;
        }
        else if (i == l_b){
            ans = min (ans, (h + 1) * h / 2 - pr[l_b + h - 1] + ((l_b) ? pr[l_b - 1] : 0));
            l_b--;
        }
    }
    cout << ((ans == INF) ? -1 : ans);
}

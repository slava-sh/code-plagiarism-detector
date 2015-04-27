#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <memory.h>
#include <set>
#include <map>
#include <cstring>

using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pdd pair<double, double>
#define mp make_pair
#pragma comment(linker, "/STACK:64000000")
int n, m, i, j, k;
const int maxn = 18;
const int maxm = 110;
const int maxmask = (1 << maxn) - 1;
const int infi = 1e9 + 7 + 1e7;
const ll infl = 1e18;
const double eps = 1e-6;
const int mod = 1000;
const int alp = 26;

pii ar[300500];
int sum[300500];
vector <int> arz[300500];
int s1[300500];
int s2[300500];
int getsum(int r) {
    int res = 0;
    for (; r >= 0; r = ((r & (r + 1)) - 1)) {
        res += sum[r];
    }
    return res;
}
int getsum(int l, int r) {
    return getsum(r) - getsum(l - 1);
}
void upd(int i, int d) {
    for (;i <= n; i = (i | (i + 1))) {
        sum[i] += d;
    }
    return;
}

int main () {
  //  freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    cin >> n >> k;
    int a, b;
    for (i = 0; i < n; ++i) {
        cin >> a >> b;
        --a, --b;
        ar[i] = mp(a, b);
        arz[a].push_back(i);
        arz[b].push_back(i);
    }
    for (i = 0; i < n; ++i) {
        s1[i] = arz[i].size();
        ++s2[s1[i]];
    }
    for (i = 0; i <= n; ++i) {
        upd(i, s2[i]);
    }
    ll res = 0;
    for (i = 0; i < n; ++i) {
        if (s1[i] >= k) {
            res += (ll)(n - 1);
            continue;
        }
        upd(s1[i], -1);
        for (j = 0; j < arz[i].size(); ++j) {
            int to = arz[i][j];
            if (ar[to].first == i) {
                int s = s1[ar[to].second];
                upd(s, -1);
                upd(s - 1, 1);
                --s1[ar[to].second];
            }
            else {
                int s = s1[ar[to].first];
                upd(s, -1);
                upd(s - 1, 1);
                --s1[ar[to].first];
            }
        }
        res += (ll)getsum(k - s1[i], n);
        upd(s1[i], 1);
        for (j = 0; j < arz[i].size(); ++j) {
            int to = arz[i][j];
            if (ar[to].first == i) {
                int s = s1[ar[to].second];
                upd(s, -1);
                upd(s + 1, 1);
                ++s1[ar[to].second];
            }
            else {
                int s = s1[ar[to].first];
                upd(s, -1);
                upd(s + 1, 1);
                ++s1[ar[to].first];
            }
        }
    }
    cout << res / 2;
        
    return 0;
}
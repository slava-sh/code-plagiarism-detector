#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <queue>


using namespace std;

#define M 1000000009
#define P 424243
#define M1 1000000007
#define P1 10007


int n, l;
string s;
vector<pair<pair<long long, long long>, int> > v;
long long h[100000];
long long h1[100000];
bool d[1000];
long long p[100001];
long long p1[100001];


long long gethash(int l, int r) {
    return (h[r] + M - ((l > 0 ? h[l - 1]: 0) * p[r - l + 1]) % M) % M;
}

long long gethash1(int l, int r) {
    return (h1[r] + M1 - ((l > 0 ? h1[l - 1]: 0) * p1[r - l + 1]) % M1) % M1;
}

map<pair<long long, long long>, string> mapi;

int main() {
    cin >> l >> s;
    bool bb = true;
    n = (int)s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'c') {
            bb = false;
        }
        long long hs = 0;
        string t;
        long long hs1 = 0;
        for (int j = i; j >= max(i - l + 1, 0); j--) {
            hs *= P;
            hs += s[j];
            hs %= M;
            hs1 *= P1;
            hs1 += s[j];
            hs1 %= M1;
            t += s[j];
            mapi[make_pair(hs, hs1)] = t;
            v.push_back(make_pair(make_pair(hs, hs1), i - j + 1));
        }
    }
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = (p[i - 1] * P) % M;
    }
    p1[0] = 1;
    for (int i = 1; i <= n; i++) {
        p1[i] = (p1[i - 1] * P1) % M1;
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
        h[i] = ((i > 0 ? h[i - 1]: 0) * P + s[i]) % M;
    }
    for (int i = 0; i < n; i++) {
        h1[i] = ((i > 0 ? h1[i - 1]: 0) * P1 + s[i]) % M1;
    }
    sort(v.begin(), v.end());
    v.resize(distance(v.begin(), unique(v.begin(), v.end())));
    int m = (int)v.size();
   // cout << "opa" << endl;
    for (int i = 0; i < m; i++) {
        if (n % v[i].second == 0) {
            bool b = true;
            for (int j = 0; j < n; j+= v[i].second) {
                if (gethash(j, j + v[i].second - 1) != v[i].first.first || gethash1(j, j + v[i].second - 1) != v[i].first.second) {
                    b = false;
                    break;
                }
            }
            if (b) {
                cout << 1 << endl;
                string g = mapi[v[i].first];
                reverse(g.begin(), g.end());
                cout << g << endl;
                return 0;
            }
        }
    }
    if (bb) {
        cout << 2 << endl;
        cout << 'a' << endl;
        cout << 'b' << endl;
        return 0;
    }
    for (int i = 0; i < min(m, 600); i++) {
        for (int j = max(i + 1, m - 600); j < m; j++) {
            memset(d, 0, sizeof(d));
            for (int k = 0; k < n; k++) {
                if (k + 1 >= v[i].second) {
                    if ((k - v[i].second < 0 || d[k - v[i].second]) && gethash(k - v[i].second + 1, k) == v[i].first.first && gethash1(k - v[i].second + 1, k) == v[i].first.second) {
                        d[k] = 1;
                        continue;
                    }
                }
                if (k + 1 >= v[j].second) {
                    if ((k - v[j].second < 0 || d[k - v[j].second]) && gethash(k - v[j].second + 1, k) == v[j].first.first && gethash1(k - v[j].second + 1, k) == v[j].first.second) {
                        d[k] = 1;
                        continue;
                    }
                }
            }
            if (d[n - 1] == 1) {
                cout << 2 << endl;
                string g = mapi[v[i].first];
                reverse(g.begin(), g.end());
                cout << g << endl;
                g = mapi[v[j].first];
                reverse(g.begin(), g.end());
                cout << g << endl;
                return 0;
            }
        }
    }
    for (int i = max(0, m / 2 - 500); i < m / 2; i++) {
        for (int j = m / 2 + 1; j < min(m, m / 2 + 1 + 500); j++) {
            memset(d, 0, sizeof(d));
            for (int k = 0; k < n; k++) {
                if (k + 1 >= v[i].second) {
                    if ((k - v[i].second < 0 || d[k - v[i].second]) && gethash(k - v[i].second + 1, k) == v[i].first.first && gethash1(k - v[i].second + 1, k) == v[i].first.second) {
                        d[k] = 1;
                        continue;
                    }
                }
                if (k + 1 >= v[j].second) {
                    if ((k - v[j].second < 0 || d[k - v[j].second]) && gethash(k - v[j].second + 1, k) == v[j].first.first && gethash1(k - v[j].second + 1, k) == v[j].first.second) {
                        d[k] = 1;
                        continue;
                    }
                }
            }
            if (d[n - 1] == 1) {
                cout << 2 << endl;
                string g = mapi[v[i].first];
                reverse(g.begin(), g.end());
                cout << g << endl;
                g = mapi[v[j].first];
                reverse(g.begin(), g.end());
                cout << g << endl;
                return 0;
            }
        }
    }
    cout << 3 << endl;
    cout << 'a' << endl;
    cout << 'b' << endl;
    cout << 'c' << endl;
    return 0;
}

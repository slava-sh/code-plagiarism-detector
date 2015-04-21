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

#define M 1000000007
#define P 424243


int n, l;
string s;
vector<pair<long long, int> > v;
long long h[100000];
bool d[1000];
long long p[100001];


long long gethash(int l, int r) {
    return (h[r] + M - ((l > 0 ? h[l - 1]: 0) * p[r - l + 1]) % M) % M;
}

map<long long, string> mapi;

int main() {
    cin >> l >> s;
    n = (int)s.size();
    for (int i = 0; i < n; i++) {
        long long hs = 0;
        string t;
        for (int j = i; j >= max(i - l, 0); j--) {
            hs *= P;
            hs += s[j];
            hs %= M;
            t += s[j];
            mapi[hs] = t;
            v.push_back(make_pair(hs, i - j + 1));
        }
    }
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = (p[i - 1] * P) % M;
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
        h[i] = ((i > 0 ? h[i - 1]: 0) * P + s[i]) % M;
    }
    sort(v.begin(), v.end());
    v.resize(distance(v.begin(), unique(v.begin(), v.end())));
    int m = (int)v.size();
   // cout << "opa" << endl;
    for (int i = 0; i < m; i++) {
        if (n % v[i].second == 0) {
            bool b = true;
            for (int j = 0; j < n; j+= v[i].second) {
                if (gethash(j, j + v[i].second - 1) != v[i].first) {
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
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            memset(d, 0, sizeof(d));
            for (int k = 0; k < n; k++) {
                if (k + 1 >= v[i].second) {
                    if (gethash(k - v[i].second + 1, k) == v[i].first) {
                        d[k] = 1;
                        continue;
                    }
                }
                if (k + 1 >= v[j].second) {
                    if (gethash(k - v[j].second + 1, k) == v[j].first) {
                        d[k] = 1;
                        continue;
                    }
                }
                if ((k == v[i].second - 1 && !d[v[j].second - 1]) || (k == v[j].second - 1 && !d[v[i].second - 1])) {
                    break;
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

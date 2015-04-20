#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <functional>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pnt;

#define mp make_pair
#define fi first
#define se second
#define pb push_back

#define FILE "numbers"

const int INF = 1000 * 1000 * 1000 + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const ld EPS = 1e-9;

int n, m;
vector< pair<string, vector<string> > > a;

string solve(const string &s) {
    for (int i = 0; i < n; ++i) {
        int p = a[i].fi.size();
        if (s.substr(0, p) == a[i].fi) {
            int m = a[i].se.size();
            for (int j = 0; j < m; ++j) {
                int q = a[i].se[j].size();
                if (s.substr(p, q) == a[i].se[j]) {
                    if (s[p + q] != '0') {
                        string res;
                        res += "+";
                        res += a[i].fi;
                        res += "(";
                        res += a[i].se[j];
                        res += ")";
                        int w = 11 - p - q;
                        if (w == 3) {
                            res += s.substr(p + q);
                        } else if (w == 4) {
                            res += s.substr(p + q, 2);
                            res += "-";
                            res += s.substr(p + q + 2);
                        } else if (w == 5) {
                            res += s.substr(p + q, 3);
                            res += "-";
                            res += s.substr(p + q + 3);
                        } else if (w == 6) {
                            res += s.substr(p + q, 2);
                            res += "-";
                            res += s.substr(p + q + 2, 2);
                            res += "-";
                            res += s.substr(p + q + 4);
                        } else if (w == 7) {
                            res += s.substr(p + q, 3);
                            res += "-";
                            res += s.substr(p + q + 3, 2);
                            res += "-";
                            res += s.substr(p + q + 5);
                        }
                        return res;
                    }
                }
            }
        }
    }
    return "Incorrect";
}

int main() {
#ifdef HAKU
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin >> n;
    a.resize(n, pair<string, vector<string> >());
    for (int i = 0; i < n; ++i) {
        cin >> a[i].fi;
        int m;
        cin >> m;
        a[i].se.resize(m);
        for (int j = 0; j < m; ++j)
            cin >> a[i].se[j];
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        cout << solve(s) << "\n";
    }
    return 0;
}

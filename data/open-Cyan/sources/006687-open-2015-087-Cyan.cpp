#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstring>
#include <iomanip>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

const long double EPS = 0.00000001;

vector<vector<pair<int,int> > > v;
vector<pair<int,int> > t;

long double gety (pair<int, int> &p1, pair<int, int> &p2, int x) {
    //cout << fixed << setprecision(5) << endl;
    //cout << p1.F << " " << p1.S << " " << p2.F << " " << p2.S << " " << x << endl;
    //cout << "ANS: " << 0.0 + p1.S + (x - p1.F + 0.0) * ((p2.S - p1.S + 0.0) / (p2.F - p1.F)) << endl;
    return 0.0 + p1.S + (x - p1.F + 0.0) * ((p2.S - p1.S + 0.0) / (p2.F - p1.F));
}

bool cf (vector<pair<int,int> > &v1, vector<pair<int,int> > &v2) {
    int f1 = 0;
    int f2 = 0;
    int r = 0;
    if (v1[0].S > v2[0].S) r |= 1;
    else if (v1[0].S < v2[0].S) r |= 2;
    long double lp;
    while (true) {
        //cout << f1 << " " << f2 << endl;
        if (v1[f1+1].F == v2[f2+1].F) {
            if (v1[f1+1].S > v2[f2+1].S) {
                r |= 1;
            } else if (v1[f1+1].S < v2[f2+1].S) {
                r |= 2;
            }
            if (r == 3) return true;
            f1++;
            f2++;
            if (f1 == v1.size()-1) break;
        } else if (v1[f1+1].F < v2[f2+1].F) {
            lp = gety(v2[f2], v2[f2+1], v1[f1+1].F) - v1[f1+1].S;
            if (abs(lp) < EPS) {
                f1++;
                continue;
            }
            if (lp > 0) {
                r |= 2;
            } else r |= 1;
            if (r == 3) return true;
            f1++;
        } else {
            lp = gety(v1[f1], v1[f1+1], v2[f2+1].F) - v2[f2+1].S;
            if (abs(lp) < EPS) {
                f2++;
                continue;
            }
            if (lp > 0) {
                r |= 1;
            } else r |= 2;
            if (r == 3) return true;
            f2++;
        }
    }
    return r == 3;
}

int gcf (vector<pair<int,int> > &v1, vector<pair<int,int> > &v2) {
    int f1 = 0;
    int f2 = 0;
    if (v1[0].S > v2[0].S) return 1;
    else if (v1[0].S < v2[0].S) return 2;
    long double lp;
    while (true) {
        if (v1[f1+1].F == v2[f2+1].F) {
            if (v1[f1+1].S > v2[f2+1].S) {
                return 1;
            } else if (v1[f1+1].S < v2[f2+1].S) {
                return 2;
            }
            f1++;
            f2++;
            if (f1 == v1.size()-1) break;
        } else if (v1[f1+1].F < v2[f2+1].F) {
            lp = gety(v2[f2], v2[f2+1], v1[f1+1].F) - v1[f1+1].S;
            if (abs(lp) < EPS) {
                f1++;
                continue;
            }
            if (lp > 0) {
                return 2;
            } else return 1;
            f1++;
        } else {
            lp = gety(v1[f1], v1[f1+1], v2[f2+1].F) - v2[f2+1].S;
            if (abs(lp) < EPS) {
                f2++;
                continue;
            }
            if (lp > 0) {
                return 1;
            } else return 2;
            f2++;
        }
    }
    return 0;
}

bool lolcomp (pair<int,int> a, pair<int,int> b) {
    if (a.F > b.F) return true;
    if (a.F < b.F) return false;
    int d = gcf(v[a.S], v[b.S]);
    if (d == 0) return a.S < b.S;
    if (d == 1) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int A,B;
    cin >> A >> B;
    int n;
    cin >> n;
    v.resize(n);
    int l;
    int d1,d2;
    for (int i = 0; i < n; i++) {
        cin >> l;
        l++;
        for (int j = 0; j < l; j++) {
            cin >> d1 >> d2;
            if (j > 1) {
                if (abs((0.0 + d2 - v[i][j-1].S) / (d1 - v[i][j-1].F) - (0.0 + v[i][j-1].S - v[i][j-2].S) / (v[i][j-1].F - v[i][j-2].F)) < EPS) {
                    v[i].back().F = d1;
                    v[i].back().S = d2;
                    continue;
                }
            }
            v[i].pb(mp(d1,d2));
        }
        t.pb(mp(v[i][0].S, i));
    }
    sort(t.begin(), t.end(), lolcomp);
    for (int i = 1; i < n; i++) {
        if (cf(v[t[i-1].S], v[t[i].S])) {
            cout << "No\n";
            cout << t[i].S + 1 << " " << t[i-1].S + 1 << endl;
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}

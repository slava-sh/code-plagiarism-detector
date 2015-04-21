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
vector<pair<int,pair<int,int> > > t;

long double gety (pair<int, int> &p1, pair<int, int> &p2, int x) {
//    cout << fixed << setprecision(5) << endl;
//    cout << p1.F << " " << p1.S << " " << p2.F << " " << p2.S << " " << x << endl;
//    cout << "ANS: " << 0.0 + p1.S + (x - p1.F + 0.0) * ((p2.S - p1.S + 0.0) / (p2.F - p1.F)) << endl;
    return 0.0 + p1.S + (x - p1.F + 0.0) * ((p2.S - p1.S + 0.0) / (p2.F - p1.F));
}

bool cf (vector<pair<int,int> > &v1, vector<pair<int,int> > &v2) {
    int f1 = 0;
    int f2 = 0;
    while (true) {
        //cout << f1 << " " << f2 << endl;
        if (v1[f1+1].F == v2[f2+1].F) {
            if (v1[f1+1].S < v2[f2+1].S) {
                return true;
            }
            f1++;
            f2++;
            if (f1 == v1.size()-1) break;
        } else if (v1[f1+1].F < v2[f2+1].F) {
            if (gety(v2[f2], v2[f2+1], v1[f1+1].F) - v1[f1+1].S > EPS) {
                return true;
            }
            f1++;
        } else {
            if (v2[f2+1].S - gety(v1[f1], v1[f1+1], v2[f2+1].F) > EPS) {
                return true;
            }
            f2++;
        }
    }
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
            v[i].pb(mp(d1,d2));
        }
        t.pb(mp(v[i][0].S, mp(v[i][1].S, i)));
    }
    sort(t.rbegin(), t.rend());
    for (int i = 1; i < n; i++) {
        if (cf(v[t[i-1].S.S], v[t[i].S.S])) {
            cout << "No\n";
            cout << t[i].S.S + 1 << " " << t[i-1].S.S + 1 << endl;
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}

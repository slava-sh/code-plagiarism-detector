#include <bits/stdc++.h>
#define DEBUG false
#define dout if (DEBUG) cout
#define x second
#define y first
#define x0 aa
#define y0 ab
#define x1 ba
#define y1 bb

using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-11; // UNUSED ATM

string s;

int a, b;
int n, m;
int t1, t2;

void swap(vector<vector<pair<int, int>>> &v, int a, int b) {
    // possibly incorrect
    vector<pair<int, int>> tmp = v[a];
    v[a] = v[b];
    v[b] = tmp;
}

ld ur(pair<int, int> l, pair<int, int> r, int x) {
    return l.y + (r.y-l.y)*ld(x-l.x)/(r.x-l.x);
}

void info(pair<int, int> p) {
    dout << p.x << ' ' << p.y << endl;
}

bool intersects(pair<int, int> & pl1, pair<int, int> & pr1, pair<int, int> & pl2, pair<int, int> & pr2) {
    info(pl1);
    info(pr1);
    dout << "---" << endl;
    info(pl2);
    info(pr2);
    ld l1, l2, r1, r2;

    if (pr1.x < pl2.x || pr2.x < pl1.x)
        return false;

    if (pl1.x > pl2.x) {
        l1 = pl1.y;
        l2 = ur(pl2, pr2, pl1.x);
    } else {
        l1 = ur(pl1, pr1, pl2.x);
        l2 = pl2.y;
    }

    if (pr1.x < pr2.x) {
        r1 = pr1.y;
        r2 = ur(pl2, pr2, pr1.x);
    } else {
        r1 = ur(pl1, pr1, pr2.x);
        r2 = pr2.y;
    }

    dout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << endl;

    bool rv = (l1 < l2 && r1 > r2) || (l1 > l2) && (r1 < r2);

    dout << "RV: " << rv << endl;

    return rv;
}

bool isHigher(vector<pair<int, int>> &top, vector<pair<int, int>> &bot) {
    // O(n^2) (maybe binsearch for O(n*logn))

    for (int i = 0; i < top.size()-2; i++) {
        for (int j = 0; j < bot.size()-2; j++) {
            pair<int, int> &tl = top[i];
            pair<int, int> &tr = top[i+1];
            pair<int, int> &bl = bot[j];
            pair<int, int> &br = bot[j+1];
            dout << "call int for: " <<  i << ' ' << j << endl;
            if (intersects(tl, tr, bl, br)) {
                return false;
            }
        }
    }
    return true;
}

bool check(vector<vector<pair<int, int>>> &v, int a, int b) {
    //dout << "check: " << a << ' ' << b << endl;
    if (v[a][0].y > v[b][0].y) {
        return isHigher(v[a], v[b]);
    } else {
        bool is1 = isHigher(v[a], v[b]);
        bool is2 = isHigher(v[b], v[a]);
        //dout << "a > b = " << is1 << "\nb > a = " << is2 << endl;
        if (is1)
            return true;
        if (is2) {
            swap(v, a, b);
            return true;
        }
        return false;
    }
}

bool cmp(vector<pair<int, int>> &a, vector<pair<int, int>> &b) {
    return a[0].y > b[0].y;
}

void print(vector<vector<pair<int, int>>> v) {
    for (auto i: v) {
        for (auto j: i)
            dout << j.x << ' ' << j.y << endl;
        dout << "---" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin >> a >> b;
    cin >> n;
    vector<vector<pair<int, int>>> v(n); // (y, x)
    for (int i = 0; i < n; i++) {
        cin >> m;
        for (int j = 0; j <= m; j++) {
            cin >> t1 >> t2;
            v[i].push_back({t2, t1});
        }
        v[i].push_back({i+1, i+1});
    }



    if (DEBUG) {
        dout << "BEFORE SORT:" << endl;
        print(v);
        sort(v.begin(), v.end(), cmp);
        dout << "AFTER SORT && BEFORE SWAP:" << endl;
        print(v);
        swap(v, 0, 1);
        dout << "AFTER SWAP:" << endl;
        print(v);
        swap(v, 0, 1);
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n-1; i++) {
        if(!check(v, i, i+1)) {
            cout << "No" << endl;
            cout << v[i][v[i].size()-1].x << ' ' << v[i+1][v[i+1].size()-1].x << endl;
            exit(0);
        }
    }
    cout << "Yes" << endl;
}

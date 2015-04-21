#include <bits/stdc++.h>
#define dout if (true) cout
#define x second
#define y first

using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-11;

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

bool isHigher(vector<pair<int, int>> &top, vector<pair<int, int>> &bot) {
    // O(n^2) (maybe binsearch for O(n*logn))
    for (int i = 0; i < top.size(); i++) {
        //dout << "isHigher(top): " << i << endl;
        for (int j = 0; j < bot.size()-1; j++) {
            pair<int, int> &left = bot[j];
            pair<int, int> &right = bot[j+1];

            if (top[i].x >= left.x && top[i].x <= right.x) {
                //dout << "for " << i << ' ' << j << " first check passed" << endl;
                if (top[i].y + EPS < left.y + (right.y-left.y)*ld(top[i].x-left.x)/ld(right.x-left.x))
                    return false;
            }
        }
    }
    return true;
}

bool check(vector<vector<pair<int, int>>> &v, int a, int b) {
    //dout << "check: " << a << ' ' << b << endl;
    if (v[a][0].y > v[b][0].y) {
        bool is = isHigher(v[a], v[b]);
        if (!is) swap(v, a, b);
        return is;
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
    }
    sort(v.begin(), v.end(), cmp);

    /*for (auto i: v) {
        for (auto j: i)
            dout << j.x << ' ' << j.y << endl;
        dout << "---" << endl;
    }*/

    for (int i = 0; i < n-1; i++) {
        if (!check(v, i, i+1)) {
            cout << "No" << endl;
            cout << i+1 << ' ' << i+2 << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}

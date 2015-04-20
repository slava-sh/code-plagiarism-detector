#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

#define mp make_pair

using namespace std;

int main() {
    freopen("names.in", "r", stdin);
    freopen("names.out", "w", stdout);
    int n;
    cin >> n;

    vector<pair<pair<string, string>, string> > a(n);
    map<string, int> q;
    string b, c, d;
    for (int i = 0; i < n; ++i) {
        cin >> b >> c >> d;
        a[i] = mp(mp(b, c), d);
        q[b]++;
        q[c]++;
        q[d]++;
    }

    for (int i = 0; i < n; ++i) {
        if (q[a[i].first.first] != 1) {
            swap(a[i].first.first, a[i].second);
            swap(a[i].first.second, a[i].second);
        }
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); ++i) {
        cout << a[i].first.first << ' ' << a[i].first.second << ' ' << a[i].second << endl;
    }

    return 0;
}

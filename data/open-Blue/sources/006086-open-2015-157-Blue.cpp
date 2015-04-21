#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;

typedef long long ll;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l;
    cin >> l;

    string s;
    cin >> s;

    int n = (int)s.length();

    set<char> q;
    for (char c: s) {
        q.insert(c);
    }

    if (l < n) {
        cout << q.size() << endl;
        for (char c: q) {
            cout << c << endl;
        }
    } else {
        cout << 1 << endl;
        cout << s << endl;
    }
}

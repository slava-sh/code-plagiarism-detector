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
        if (q.size() == 2 && n % 2 == 0 && l > 1) {
            bool ok = true;
            string t = "ab";
            for (int i = 0; i < n; i += 2) {
                string cur = "";
                cur += s[i];
                cur += s[i + 1];
                if (cur != t) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << 1 << endl;
                cout << "ab" << endl;
            }

            ok = true;
            t = "ba";
            for (int i = 0; i < n; i += 2) {
                string cur = "";
                cur += s[i];
                cur += s[i + 1];
                if (cur != t) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << 1 << endl;
                cout << "ba" << endl;
            }
        }
        cout << q.size() << endl;
        for (char c: q) {
            cout << c << endl;
        }
    } else {
        cout << 1 << endl;
        cout << s << endl;
    }
}

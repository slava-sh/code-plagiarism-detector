
#include <bits/stdc++.h>
#define dout if (false) cout

using namespace std;

typedef long long ll;

ll n;
string s;
set<char> sc;

bool test(int beg, int len) {
    string cur;
    bool canbe[22222], bad;
    for (int i = 0; i < 22222; i++)
        canbe[i] = false;
    for (int i = 0; i < len; i++) {
        cur += s[beg+i];
    }
    //cout << "CUR: " << cur << " (" << len << ")" << endl;
    for (int i = 0; i <= s.size()-len; i++) {
        if (i && !canbe[i-1])
            continue;
        bad = false;
        for (int j = i; j < i+len; j++)
            if (cur[j-i] != s[j]) {
                bad = true;
                break;
            }
            if (!bad) {
                for (int x = i; x < i+len; x++)
                    canbe[x] = true;
            }
    }
    return canbe[s.size()-1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        sc.insert(s[i]);

    if (n >= s.size()) {
        cout << 1 << endl;
        cout << s << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j+i <= s.size(); j++) {
            if (test(j, i)) {
                //cout << j << ' ' << i << endl;
                cout << 1 << endl;
                for (int x = j; x < j+i; x++)
                    cout << s[x];
                cout << endl;
                return 0;
            }
        }
    }
    cout << sc.size() << endl;
    for (auto i: sc)
        cout << i << endl;

}



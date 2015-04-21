
#include <bits/stdc++.h>
#define dout if (false) cout

using namespace std;

typedef long long ll;

ll n;
string s;
set<char> sc;

bool test(int beg, int len) {
    string cur;
    for (int i = 0; i < len; i++) {
        cur += s[beg+i];
    }

    //cout << "CUR: " << cur << endl;

    for (int i = 0; i <= s.size()-len; i+=len) {
        for (int j = i; j < i+len; j++)
            if (cur[j-i] != s[j])
                return false;
    }
    return true;
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
            if (s.size()%i == 0 && test(j, i)) {
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



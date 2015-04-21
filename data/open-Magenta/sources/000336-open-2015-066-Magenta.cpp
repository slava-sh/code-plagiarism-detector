#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define prev prev_
#define next next_

int f(int x) {
    if (x == 0) {
        return 0;
    }
    return 1 + f(x / 2);
}

int main() {
    srand(time(NULL));
    string s = "DL";
    int i = 0;
    while (true) {
        cout << s[f(i++) % 2] << endl;
        string t;
        cin >> t;
        if (t == "Y" || t == "E") {
            return 0;
        }
    }
    return 0;
}

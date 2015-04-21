#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define prev prev_
#define next next_

int main() {
    srand(time(NULL));
    string s = "UDLR";
    while (true) {
        cout << s[rand() % 4] << endl;
        string t;
        cin >> t;
        if (t == "Y" || t == "E") {
            return 0;
        }
    }
    return 0;
}

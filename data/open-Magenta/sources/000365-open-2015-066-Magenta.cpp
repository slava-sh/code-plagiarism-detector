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
    string s = "DL";
    while (true) {
        cout << s[rand() % 2] << endl;
        string t;
        cin >> t;
        if (t == "Y" || t == "E") {
            return 0;
        }
    }
    return 0;
}

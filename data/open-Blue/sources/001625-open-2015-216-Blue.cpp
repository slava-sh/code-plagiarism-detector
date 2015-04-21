#include <cstdio>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int l;
    cin >> l;
    string s;
    cin >> s;
    int n = s.length();
    int lim = min(n, l);
    for (int i = 1; i <= lim; i++) {
        int k = 0;
        bool ok = true;
        for (int j = 0; j < n; j++) {
            if (s[j] != s[k]) {
                ok = false;
                break;
            }
            k++;
            if (k == i) {
                k = 0;
            }
        }
        if (ok) {
            cout << 1 << "\n";
            cout << s.substr(0, i) << "\n";
            return 0;
        }
    }
    cout << 2 << "\n";
    cout << "a" << "\n";
    cout << "b" << "\n";
    return 0;
}
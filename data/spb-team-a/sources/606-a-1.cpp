#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("abcd.in", "r", stdin);
    freopen("abcd.out", "w", stdout);
    int t;
    string s;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> s;
        int a, b, c;
        c = s[0] - '0';
        a = c;
        c = s[1] - '0';
        a = (a * 10) + c;
        c = s[2] - '0';
        b = c;
        c = s[3] - '0';
        b = (b * 10) + c;
        if ((a * a + b * b) % 7 == 1) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
    }
    return 0;
}

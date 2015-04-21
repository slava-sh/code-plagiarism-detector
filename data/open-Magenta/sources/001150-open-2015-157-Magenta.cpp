#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int w = 1;
    int x = 1;
    char c;
    do {
        if (x < w) {
            x++;
            cout << 'R' << endl;
            cout.flush();
        } else {
            cout << 'D' << endl;
            cout.flush();
            w++;
            x = 1;
        }
        cin >> c;
    } while (c != 'Y' && c != 'E');
    assert(c == 'Y');
}

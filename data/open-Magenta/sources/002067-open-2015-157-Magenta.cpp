#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int w = 1, h = 300;
    int x = 1;
    char c;
    do {
        if (x < w) {
            x++;
            cout << 'R' << endl;
            cout << x << endl;
            cout.flush();
        } else {
            while (x != 1) {
                x--;
                cout << 'L' << endl;
                cout.flush();
                cin >> c;
            }
            h--;
            cout << 'U' << endl;
            cout.flush();
            w = 300 / h;
        }
        cin >> c;
    } while (c != 'Y' && c != 'E');
    assert(c == 'Y');
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int w = 1, h = 6000;
    int x = 1, y = 1;
    char c;
    do {
        if (x < w) {
            x++;
            cout << 'R' << endl;
            cout.flush();
        } else {
            y++;
            cout << 'D' << endl;
            cout.flush();
            w++;
            h = 6000 / w;
            x = 1;
        }
        cout << w << ' ' << h << endl;
        cin >> c;
    } while (c != 'Y' && c != 'E');
    assert(c == 'Y');
}

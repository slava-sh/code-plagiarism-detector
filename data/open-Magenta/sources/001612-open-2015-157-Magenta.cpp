#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int w = 6000, h = 1;
    int x = 1;
    char c;
    do {
        if (x <= w) {
            x++;
            cout << 'R' << endl;
            cout.flush();
        } else {
            h++;
            while (x != 1) {
                x--;
                cout << 'L' << endl;
                cout.flush();
                cin >> c;
            }
            cout << 'U' << endl;
            cout.flush();
            w = 6000 / h;
        }
        //cout << w << ' ' << h << endl;
        cin >> c;
    } while (c != 'Y' && c != 'E');
    //} while (w != 1);
    assert(c == 'Y');
}

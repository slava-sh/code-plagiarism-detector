#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int w = 1, h = 6000;
    int x = 1;
    char c;
    int cnt = 0;
    do {
        if (x < w) {
            x++;
            cout << 'R' << endl;
            cout.flush();
        } else {
            cout << 'D' << endl;
            cout.flush();
            w *= 2;
            x = 1;
        }
        cin >> c;
        //cout << w << ' ' << h << endl;
        //cnt++;
    } while (c != 'Y' && c != 'E');
    //cout << cnt << endl;
    assert(c == 'Y');
}

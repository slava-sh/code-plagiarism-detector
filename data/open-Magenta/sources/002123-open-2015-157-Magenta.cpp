#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    const int s = 6000;
    int w = 1, h = s;
    int x = 1;
    char c;
    do {
        if (x < w) {
            x++;
            cout << 'R' << endl;
            cout.flush();
        } else {
            h--;
            cout << 'U' << endl;
            cout.flush();
            w = s / h;
            x = 1;
        }
        cin >> c;
    } while (c != 'Y' && c != 'E');
    assert(c == 'Y');
}

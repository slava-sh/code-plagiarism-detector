#include <iostream>
#include <cstdio>

using namespace std;

int w, h, n;
char a[510][510];
int x, y;
int pr = 1e9, sl = 1e9;
int slX, slY, prX, prY;

int abs(int k) {
    return k < 0 ? -k : k;
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> w >> h >> n;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'V') {
                x = i;
                y = j;
            }
        }

    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            if (a[i][j] == 'T') {
                if (sl > abs(x - i) + abs(y - j)) {
                    sl = abs(x - i) + abs(y - j);
                    slX = i;
                    slY = j;
                }
                if (j < w - 1)
                    if (a[i][j + 1] == 'T')
                        if (pr > abs(x - i) + min(abs(y - j), abs(y - j - 1))) {
                            pr = abs(x - i) + min(abs(y - j), abs(y - j - 1));
                            prX = i;
                            prY = abs(y - j) < abs(y - j - 1) ? j : j + 1;
                        }

                if (i < h - 1)
                    if (a[i + 1][j] == 'T')
                        if (pr > abs(y - j) + min(abs(x - i), abs(x - i - 1))) {
                            pr = abs(y - j) + min(abs(x - i), abs(x - i - 1));
                            prY = j;
                            prX = abs(x - i) < abs(x - i - 1) ? i : i + 1;
                        }

            }

    if (sl + 2 * n - 1 < pr + n) {
        for (int i = x; i < slX; ++i)
            cout << "S";
        for (int i = slX; i < x; ++i)
            cout << "N";
        for (int i = y; i < slY; ++i)
            cout << "E";
        for (int i = slY; i < y; ++i)
            cout << "W";

        if (slX != 0) {
            for (int i = 1; i < n; ++i)
                cout << "NS";
        } else if (slX != h - 1) {
            for (int i = 1; i < n; ++i)
                cout << "SN";
        } else if (slY != 0) {
            for (int i = 1; i < n; ++i)
                cout << "WE";
        } else {
            for (int i = 1; i < n; ++i)
                cout << "EW";
        }

    } else {
        for (int i = x; i < prX; ++i)
            cout << "S";
        for (int i = prX; i < x; ++i)
            cout << "N";
        for (int i = y; i < prY; ++i)
            cout << "E";
        for (int i = prY; i < y; ++i)
            cout << "W";

        if (prX > 0)
            if (a[prX - 1][prY] == 'T') {
                for (int i = 1; i < n / 2; ++i)
                    cout << "NS";
                cout << "N";
                if (n % 2)
                    cout << "SN";
                return 0;
            }
        if (prX < h - 1)
            if (a[prX + 1][prY] == 'T') {
                for (int i = 1; i < n / 2; ++i)
                    cout << "SN";
                cout << "S";
                if (n % 2)
                    cout << "NS";
                return 0;
            }
        if (prY < w - 1)
            if (a[prX][prY + 1] == 'T') {
                for (int i = 1; i < n / 2; ++i)
                    cout << "EW";
                cout << "E";
                if (n % 2)
                    cout << "WE";
                return 0;
            }
        if (prY > 0)
            if (a[prX][prY - 1] == 'T') {
                for (int i = 1; i < n / 2; ++i)
                    cout << "WE";
                cout << "W";
                if (n % 2)
                    cout << "EW";
                return 0;
            }
    }

    return 0;
}

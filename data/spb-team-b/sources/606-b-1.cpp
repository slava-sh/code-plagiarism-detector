#include <iostream>
#include <cstdio>

using namespace std;

int n, mas[1010], mas2[1011][1011];

int main() {
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= 1010; i++) {
        for(int j = 1; j <= 1010; j++) {
            mas2[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++) {
        cin >> mas[i];
        for(int j = 1; j <= mas[i]; j++) {
            mas2[i][j] = 1;
        }
    }
    int ans = 0;
    int a = 1;
    int b = 1;
    while(mas2[a][b] == 1) {
        if (mas2[a][b] == 1) {
            ans++;
        }
        a++;
        b++;
    }
    a = 1;
    b = 1;
    cout << ans << endl;
    while(mas2[a][b] == 1) {
        if (mas2[a][b] == 1) {
            cout << a << " " << b << endl;
        }
        a++;
        b++;
    }
    return 0;
}

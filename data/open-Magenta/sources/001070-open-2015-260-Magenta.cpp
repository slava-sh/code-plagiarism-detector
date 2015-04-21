#include <bits/stdc++.h>

using namespace std;

int main(){
    int x = 1, y = 1, pow2 = 1;
    char w;
    for(int i = 1; i <= 13; i++) {
        pow2 *= 2;
        if(x == 1) {
            while(x != pow2 || y != 1) {
                int a = pow2 / x;
                int b = pow2 / 2 / x + 1;
                if (y > a)
                    while (y > a) {
                        cout << 'D';
                        cin >> w;
                        if(w == 'Y' || w == 'E')
                            return 0;
                        cout.flush();
                        y--;
                    }
                else
                    while (y < a) {
                        cout << 'U';
                        cin >> w;
                        if(w == 'Y' || w == 'E')
                            return 0;
                        cout.flush();
                        y++;
                    }
                while (y > b) {
                    cout << 'D';
                    cin >> w;
                    if(w == 'Y' || w == 'E')
                        return 0;
                    cout.flush();
                    y--;
                }
                if(x == pow2 && y == 1) break;
                cout << 'R';
                cin >> w;
                if(w == 'Y' || w == 'E')
                    return 0;
                cout.flush();
                x++;
            }
            continue;
        }
        if(y == 1) {
            while(y != pow2 || x != 1) {
                int a = pow2 / y;
                int b = pow2 / 2 / y + 1;
                if (x > a)
                    while (x > a) {
                        cout << 'L';
                        cin >> w;
                        if(w == 'Y' || w == 'E')
                            return 0;
                        cout.flush();
                        x--;
                    }
                else
                    while (x < a) {
                        cout << 'R';
                        cin >> w;
                        if(w == 'Y' || w == 'E')
                            return 0;
                        cout.flush();
                        x++;
                    }
                while (x > b) {
                    cout << 'L';
                    cin >> w;
                    if(w == 'Y' || w == 'E')
                        return 0;
                    cout.flush();
                    x--;
                }
                if(y == pow2 && x == 1) break;
                cout << 'U';
                cin >> w;
                if(w == 'Y' || w == 'E')
                    return 0;
                cout.flush();
                y++;
            }
            continue;
        }
    }
}

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
                        cout << 'D' << endl;
                        cout.flush();
                        cin >> w;
                        if(w == 'Y' || w == 'E')
                            return 0;
                        y--;
                    }
                else
                    while (y < a) {
                        cout << 'U' << endl;
                        cout.flush();
                        cin >> w;
                        if(w == 'Y' || w == 'E')
                            return 0;
                        y++;
                    }
                while (y > b) {
                    cout << 'D' << endl;
                    cout.flush();
                    cin >> w;
                    if(w == 'Y' || w == 'E')
                        return 0;
                    y--;
                }
                if(x == pow2 && y == 1) break;
                cout << 'R' << endl;
                cout.flush();
                cin >> w;
                if(w == 'Y' || w == 'E')
                    return 0;
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
                        cout << 'L' << endl;
                        cout.flush();
                        cin >> w;
                        if(w == 'Y' || w == 'E')
                            return 0;
                        x--;
                    }
                else
                    while (x < a) {
                        cout << 'R' << endl;
                        cout.flush();
                        cin >> w;
                        if(w == 'Y' || w == 'E')
                            return 0;
                        x++;
                    }
                while (x > b) {
                    cout << 'L' << endl;
                    cout.flush();
                    cin >> w;
                    if(w == 'Y' || w == 'E')
                        return 0;
                    x--;
                }
                if(y == pow2 && x == 1) break;
                cout << 'U' << endl;
                cout.flush();
                cin >> w;
                if(w == 'Y' || w == 'E')
                    return 0;
                y++;
            }
            continue;
        }
    }
}

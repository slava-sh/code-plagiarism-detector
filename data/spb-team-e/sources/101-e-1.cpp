#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(){
    freopen ("game.in", "r", stdin);
    freopen ("game.out", "w", stdout);
    int n, m, l1, r1, l2, r2;
    int p = 0, v = 0, o = 0;
    cin >> n >> m;
    cin >> l1 >> r1;
    cin >> l2 >> r2;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        if ((x <= r1 && x >= l1) && (x <= r2 && x >= l2))
            ++o;
        if ((x <= r1 && x >= l1) && !(x <= r2 && x >= l2))
            ++p;
        if (!(x <= r1 && x >= l1) && (x <= r2 && x >= l2))
            ++v;
    }

    int a = 0, b = 0;

    for (int i = 0; i < m; ++i){
        if (i % 2 == 0){
            if (o > 0){
                ++a;
                --o;
            } else
                if (p > 0){
                    ++a;
                    --p;
                }
        } else {
            if (o > 0){
                ++b;
                --o;
            } else
                if (v > 0){
                    ++b;
                    --v;
                }
        }
    }

    if (a == b)
        cout << "Draw";
    else
        if (a > b)
            cout << "Petya";
        else
            cout << "Vasya";

    return 0;
}

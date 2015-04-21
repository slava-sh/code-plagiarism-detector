#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#define mp make_pair
#define x first
#define y second
#define point pair<int, int>
#define pb push_back
#define int long long
#define For(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

char a;

main() {
    srand(time(NULL));
    For(j, 0, 200000) {
        For(i, 0, 2000 + rand() % 6000) {
            cout << 'U' << endl;
            cin >> a;
            if (a != 'N') return 0;
            cout << 'R' << endl;
            cin >> a;
            if (a != 'N') return 0;
        }
        cout << 'U' << endl;
        cin >> a;
        if (a != 'N') return 0;
        cout << 'U' << endl;
        cin >> a;
        if (a != 'N') return 0;
    }
}

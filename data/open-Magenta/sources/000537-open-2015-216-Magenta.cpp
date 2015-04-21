#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <fstream>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 6000;

void check() {
    char c;
    cin >> c;
    if (c == 'Y' || c == 'E') {
        exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int dir = 1;
    int k = 1;
    int used = 1;
    int lf = 1;
    int cnt = 0;
    while (true) {
        if (cnt == 10000) {
            break;
        }
        cnt++;
        if (dir == 0) {
            cout << "L\n";
        } else if (dir == 1) {
            cout << "U\n";
        } else if (dir == 2) {
            cout << "R\n";
        } else {
            cout << "D\n";
        }
        cout.flush();
        check();
        lf--;
        if (lf != 0) {
            continue;
        }
        dir++;
        if (dir == 4) {
            dir = 0;
        }
        used++;
        lf = k;
        if (used <= 2) {
            continue;
        }
        used = 1;
        k++;
        lf = k;
    }
    for (int i = 1; i <= 20; i++) {
        int lim = N / i;
        while (lim != 0) {
            cout << "U\n";
            cout.flush();
            check();
            lim--;
        }
        cout << "R\n";
        check();
    }
    for (int i = 1; i <= 20; i++) {
        int lim = N / i;
        while (lim != 0) {
            cout << "R\n";
            cout.flush();
            check();
            lim--;
        }
        cout << "U\n";
        check();
    }
    return 0;
}
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
const int N1 = 30;
const int N2 = 300;
const int N3 = 2000;
const int N4 = 6000;

void check() {
    char c;
    cin >> c;
    if (c == 'Y' || c == 'E') {
        exit(0);
    }
}

void solve1() {
    for (int i = 1; i <= 2; i++) {
        int lim = N1 / i;
        while (lim != 0) {
            cout << "U\n";
            cout.flush();
            check();
            lim--;
        }
        cout << "R\n";
        cout.flush();
        check();
    }
    for (int i = 1; i <= 2; i++) {
        int lim = N1 / i;
        while (lim != 0) {
            cout << "R\n";
            cout.flush();
            check();
            lim--;
        }
        cout << "U\n";
        cout.flush();
        check();
    }
    int dir = 1;
    int k = 1;
    int used = 1;
    int lf = 1;
    int cnt = 0;
    while (true) {
        if (cnt == 36) {
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
}

void solve2() {
    int x = 1;
    int y = 1;
    cout << 1 / (x - y) << "\n";
    for (int i = 1; i <= 5; i++) {
        int lim = N2 / i;
        while (lim != 0) {
            cout << "U\n";
            cout.flush();
            check();
            lim--;
        }
        cout << "R\n";
        cout.flush();
        check();
    }
    for (int i = 1; i <= 5; i++) {
        int lim = N2 / i;
        while (lim != 0) {
            cout << "R\n";
            cout.flush();
            check();
            lim--;
        }
        cout << "U\n";
        cout.flush();
        check();
    }
    int dir = 1;
    int k = 1;
    int used = 1;
    int lf = 1;
    int cnt = 0;
    while (true) {
        if (cnt == 3000) {
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
}

void solve3() {
    for (int i = 1; i <= 17; i++) {
        int lim = N3 / i;
        while (lim != 0) {
            cout << "U\n";
            cout.flush();
            check();
            lim--;
        }
        cout << "R\n";
        cout.flush();
        check();
    }
    for (int i = 1; i <= 17; i++) {
        int lim = N3 / i;
        while (lim != 0) {
            cout << "R\n";
            cout.flush();
            check();
            lim--;
        }
        cout << "U\n";
        cout.flush();
        check();
    }
    int dir = 1;
    int k = 1;
    int used = 1;
    int lf = 1;
    int cnt = 0;
    while (true) {
        if (cnt == 35000) {
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
}

void solve4() {

    for (int i = 1; i <= 20; i++) {
        int lim = N4 / i;
        while (lim != 0) {
            cout << "U\n";
            cout.flush();
            check();
            lim--;
        }
        cout << "R\n";
        cout.flush();
        check();
    }
    for (int i = 1; i <= 20; i++) {
        int lim = N4 / i;
        while (lim != 0) {
            cout << "R\n";
            cout.flush();
            check();
            lim--;
        }
        cout << "U\n";
        cout.flush();
        check();
    }
    int dir = 1;
    int k = 1;
    int used = 1;
    int lf = 1;
    int cnt = 0;
    while (true) {
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
}

int main() {
    ios_base::sync_with_stdio(false);
    solve1();
    solve2();
    solve3();
    solve4();
    return 0;
}
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
    while (true) {
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
    return 0;
}
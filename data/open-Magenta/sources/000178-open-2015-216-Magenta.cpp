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
    srand(time(NULL));
    int dir = 1;
    int k = 1;
    int used = 1;
    int lf = 1;
    while (true) {
        int dir = rand() % 4;
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
    }
    return 0;
}
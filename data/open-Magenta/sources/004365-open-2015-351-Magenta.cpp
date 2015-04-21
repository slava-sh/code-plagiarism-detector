#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 6666, inf = 1011111111;

int n, ans;
char c;

void proc(int cnt, char q) {
    while (cnt--) {
        cout << q << endl;
        cin >> c;
        cout.flush();
        if (c != 'N') {
            exit(0);
        }
    }
}

int main() {
    for (int len = 1; ; len += 2) {
        if (len * len > 2000) {
            while (true) {
                proc(len, 'R');
                proc(1, 'U');
            }
        } else {
            proc(len, 'D');
            proc(len, 'R');
            proc(len, 'U');
            proc(len, 'L');
            proc(1, 'L');
            proc(1, 'U');
        }
    }
    return 0;
}

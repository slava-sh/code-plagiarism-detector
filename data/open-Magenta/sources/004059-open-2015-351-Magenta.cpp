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

void proc(char q) {
    cout << q << endl;
    cin >> c;
    cout.flush();
    if (c != 'N') {
        exit(0);
    }
}

int main() {
    for (int n = 1; ; ++n) {
        /*for (int i = 0; i < n * n; ++i) {
            for (int j = 0; j < n; ++j) {
                proc('R');
            }
            proc('U');
        }*/
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n * n; ++j) {
                proc('R');
            }
            proc('U');
        }
    }
    return 0;
}

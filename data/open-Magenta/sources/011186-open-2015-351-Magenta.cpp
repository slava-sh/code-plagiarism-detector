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
    ++ans;
    cout << q << endl;
    cout.flush();
    cin >> c;
    if (c != 'N') {
        //cout << ans << endl;
        exit(0);
    }
}

int main() {
    for (int n = 1; ; ++n) {
        for (int i = 0; i < n && i < 5000 / n + 5; ++i) {
            for (int j = 0; j < n; ++j) {
                proc('R');
            }
            proc('U');
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n && j < 5000 / n + 5; ++j) {
                proc('R');
            }
            proc('U');
        }
    }
    return 0;
}

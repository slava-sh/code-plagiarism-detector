#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <queue>


using namespace std;

int c[4] = {'R', 'L', 'U', 'D'};

int main() {
    while (true) {
        int a = rand() % 4;
        cout << c[a] << endl;
        cout.flush();
        char c;
        cin >> c;
        cout.flush();
        if (c == 'E' || c == 'Y') {
            return 0;
        }
    }
    return 0;
}

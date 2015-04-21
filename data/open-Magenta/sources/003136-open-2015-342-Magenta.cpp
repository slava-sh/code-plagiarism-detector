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

char c[4] = {'R', 'L', 'U', 'D'};

int main() {
    while (true) {
        int b = rand() % 10;
        for (int i = 0; i < b; i++) {
            rand();
        }
        int a = rand() % 4;
        cout << c[a] << endl;
        char c1;
        cin >> c1;
        cout.flush();
        if (c1 == 'E' || c1 == 'Y') {
            return 0;
        }
    }
    return 0;
}

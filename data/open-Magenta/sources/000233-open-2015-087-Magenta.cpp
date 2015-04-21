#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstring>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

void go (char c) {
    cout << c << endl;
    cout.flush();
    char e;
    cin >> e;
    if (e == 'E') {
        exit(1);
    } else if (e == 'Y') {
        exit(0);
    }
}

int main() {
    int N = 6050;
    for (int i = 1; i < N; i++) {
        int d = (N / i) + 1;
        for (int j = 0; j < d; j++) {
            go('D');
        }
        go('R');
    }
    return 0;
}

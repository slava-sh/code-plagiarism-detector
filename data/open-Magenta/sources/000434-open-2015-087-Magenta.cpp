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

int k = 0;

void go (char c) {
    cout << c << endl;
    cout.flush();
    char e;
    cin >> e;
    k++;
    if (e == 'E') {
        exit(1);
    } else if (e == 'Y') {
        exit(0);
    }
}

int main() {
    for (int N = 2; ; N *= 2) {
        for (int i = 1; i < N; i++) {
            int d = N / i;
            for (int j = 0; j < d; j++) {
                go('D');
            }
            go('R');
        }
    }
//    N = 2000;
//    for (int i = 1; i < N; i++) {
//        int d = N / i;
//        for (int j = 0; j < d; j++) {
//            go('D');
//        }
//        go('R');
//    }
//    N = 6000;
//    for (int i = 1; i < N; i++) {
//        int d = N / i;
//        for (int j = 0; j < d; j++) {
//            go('D');
//        }
//        go('R');
//    }
    return 0;
}

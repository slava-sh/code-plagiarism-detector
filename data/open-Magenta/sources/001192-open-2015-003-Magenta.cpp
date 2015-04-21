#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;

void read() {
    char ch;
    cin >> ch;
    if (ch == 'Y' || ch == 'E') exit(0);
}

int main()
{
    int i = 0;
    while (true) {
        i++;
        cout << "U" << endl;
        read();
        for (int j = 0; j < i; ++j) {
            cout << "R" << endl;
            read();
        }
        for (int j = 0; j < i; ++j) {
            cout << "D" << endl;
            read();
        }
        cout << "R" << endl;
        read();
        i++;
        for (int j = 0; j < i; ++j) {
            cout << "U" << endl;
            read();
        }
        for (int j = 0; j < i; ++j) {
            cout << "L" << endl;
            read();
        }
    }

    return 0;
}


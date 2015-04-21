#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

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
        for (int j = 0; j < i; ++j) {
            cout << "R" << endl;
            read();
        }
        for (int j = 0; j < i; ++j) {
            cout << "U" << endl;
            read();
        }
        i++;
        for (int j = 0; j < i; ++j) {
            cout << "L" << endl;
            read();
        }
        for (int j = 0; j < i; ++j) {
            cout << "D" << endl;
            read();
        }
    }


    return 0;
}

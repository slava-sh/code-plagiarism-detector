#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>

using namespace std;

ifstream fin("prizes.in");
ofstream fout("prizes.out");

int main() {
    int x, y;
    fin >> x >> y;
    if (x == 1 && y == 1) {
        fout << 0;
        return 0;
    }
    if (x == 1 || y == 1) {
        int ans = 0;
        if (max(x, y) - 2)
            ans = 1;
        ans += (max(x, y) - 3) / 4;
        fout << ans;
        return 0;
    }
    if (x == 2 || y == 2) {
        fout << 0;
        return 0;
    }
    if (x > 2 && y > 2) {
        fout << 1;
        return 0;
    }
    return 0;
}

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <functional>
#include <cassert>
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int curdepth, curstage, curmove;
char z[9];

void make_move(char c) {
    printf("%c\n",c);
    fflush(stdout);
    scanf("%s",z);
    if (*z == 'Y' || *z == 'E') exit(0);
}

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);

    while (1) {
        if (curstage == 0) {
            if (curmove == curdepth) {
                ++curstage;
                curmove = 0;
            } else {
                make_move('R');
                ++curmove;
            }
        } else if (curstage == 1) {
            if (curmove == 2*curdepth+1) {
                ++curstage;
                curmove = 0;
            } else {
                make_move('D');
                ++curmove;
            }
        } else if (curstage == 2) {
            if (curmove == 2*curdepth+1) {
                ++curstage;
                curmove = 0;
            } else {
                make_move('L');
                ++curmove;
            }
        } else if (curstage == 3) {
            if (curmove == 2*curdepth+1) {
                ++curstage;
                curmove = 0;
            } else {
                make_move('U');
                ++curmove;
            }
        } else if (curstage == 4) {
            if (curmove == curdepth+1) {
                ++curstage;
                curmove = 0;
            } else {
                make_move('R');
                ++curmove;
            }
        } else if (curstage == 5) {
            make_move('U');
            curstage = 0;
            curmove = 0;
            ++curdepth;
        }
    }

    return 0;
}

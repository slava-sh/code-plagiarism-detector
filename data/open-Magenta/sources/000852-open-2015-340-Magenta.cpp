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

    srand(7368);
    while (1) {
        if (rand() & 1) make_move('U');
        else make_move('R');
    }

    return 0;
}

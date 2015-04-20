#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>

#define problem "prizes"

using namespace std;

int main()
{
    assert(freopen(problem".in", "r", stdin) != NULL);
    assert(freopen(problem".out", "w", stdout));

    int n, m;
    cin >> n >> m;
    int d;
    if(n == 1) {
        d = (m + 1) / 4;
    }else if(m == 1) d = (n + 1) / 4;
    else d = min((n + 1) / 4, (m + 1) / 4);
    if (n > 1 && m > 1 && (n >= 3 || m >= 3)) d = 1;
    cout << d << endl;
    return 0;
}


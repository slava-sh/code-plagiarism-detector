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
    cout << min((n + 1) / 4, (m + 1) / 4) << endl;
    return 0;
}


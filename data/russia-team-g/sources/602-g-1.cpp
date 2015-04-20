#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>

using namespace std;

#define PROBLEMNAME "prizes"

#ifdef LOCAL
# define DBG(fmt, ...) fprintf (stderr, "DBG: " fmt "\n", ## __VA_ARGS__)
#else
# define DBG(...)
#endif // LOCAL

int main()
{
    assert (freopen (PROBLEMNAME ".in", "r", stdin));
#ifndef LOCAL
    assert (freopen (PROBLEMNAME ".out", "w", stdout));
#endif // LOCAL

    int m, n;
    scanf ("%d %d", &m, &n);
    
    if (n == 1)
    {
        printf ("%d\n", (m - 2 + 3) / 4);
        return 0;
    }
    
    if (m == 1)
    {
        printf ("%d\n", (n - 2 + 3) / 4);
        return 0;
    }
    
    if (m == 2 || n == 2)
    {
        printf ("0\n");
        return 0;
    }
    
    printf ("1\n");
    return 0;
}


#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>

using namespace std;

#define PROBLEMNAME "che"

#ifdef LOCAL
# define DBG(fmt, ...) fprintf (stderr, "DBG: " fmt "\n", ## __VA_ARGS__)
#else
# define DBG(...)
#endif // LOCAL

const int maxN = 300500;
int theDistance[maxN];

int main()
{
    assert (freopen (PROBLEMNAME ".in", "r", stdin));
#ifndef LOCAL
    assert (freopen (PROBLEMNAME ".out", "w", stdout));
#endif // LOCAL

    int nPlaces, minDistance;
    scanf ("%d %d", &nPlaces, &minDistance);

    for (int i = 0; i < nPlaces; i++)
        scanf ("%d", &theDistance[i]);
    
    int first = 0, second = 0;
    long long answer = 0;
    
    while (first != nPlaces)
    {
        while (second != nPlaces && theDistance[second] - theDistance[first] <= minDistance)
            second++;
        answer += nPlaces - second;
        first++;
        DBG ("pos %d += %d", first, nPlaces - second);
    }
    
    printf ("%lld\n", answer);

    return 0;
}

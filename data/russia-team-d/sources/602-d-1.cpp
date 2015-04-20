#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>

using namespace std;

#define PROBLEMNAME "fence"

#ifdef LOCAL
# define DBG(fmt, ...) fprintf (stderr, "DBG: " fmt "\n", ## __VA_ARGS__)
#else
# define DBG(...)
#endif // LOCAL

int nGuys, fenceLength;
vector <int> wanted;

bool canDo (int x)
{
    int covered = 0;
    
    for (int i = 0; i < nGuys; i++)
    {
        if (wanted[i] < x) return false;
        if (covered + x > fenceLength) return false;
        
        int leftEnd = covered + x - wanted[i];
        if (leftEnd >= 0)
        {
            covered += x;
            continue;
        }
        
        DBG ("left end %d", leftEnd);
        covered += x + (-leftEnd);
        if (covered > fenceLength)
            covered = fenceLength;
        DBG ("covered %d", covered);
    }
    
    return true;
}

bool canDoWrapped (int x)
{
    bool ans = canDo (x);
    DBG ("%d: %s", x, ans ? "can" : "can not");
    return ans;
}

int main()
{
    assert (freopen (PROBLEMNAME ".in", "r", stdin));
#ifndef LOCAL
    assert (freopen (PROBLEMNAME ".out", "w", stdout));
#endif // LOCAL

    scanf ("%d %d", &nGuys, &fenceLength);
    
    wanted.resize (nGuys);
    for (int i = 0; i < nGuys; i++)
        scanf ("%d", &wanted[i]);
    
    sort (wanted.begin(), wanted.end());
    
    int minCan = 0, maxCan = fenceLength;
    
    while (minCan != maxCan)
    {
        int m = (minCan + maxCan + 1) / 2;
        
        if (canDoWrapped (m))
            minCan = m;
        else
            maxCan = m - 1;
            
        DBG ("considering %d..%d", minCan, maxCan);
    }
    
    printf ("%d\n", minCan);

    return 0;
}

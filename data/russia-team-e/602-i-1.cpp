#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>

using namespace std;

#define PROBLEMNAME "sochi"

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

    int nChunks, d;
    scanf ("%d %d", &nChunks, &d);
    
    int answer = 0;
    int maxChunk = 0;
    
    for (int i = 0; i < nChunks; i++)
    {
        int a;
        scanf ("%d", &a);
        
        if (a > 2 * d)
        {
            answer += a - 2 * d;
            DBG ("attach %d, answer is %d", a - 2 * d, answer);
        }
        
        maxChunk = max (a, maxChunk);
        
        /*else
        {
            if (a > maxChunk)
            {
                secondMaxChunk = maxChunk;
                maxChunk = a;
            }
            else if (a > secondMaxChunk)
            {
                secondMaxChunk = a;
            }
        }*/
    }
    
    if (answer != 0)
        printf ("%d\n", answer + 2 * d);
    else
        printf ("%d\n", maxChunk);
    
    return 0;
}

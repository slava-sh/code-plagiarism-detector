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

int prefixSum[100500];

int main()
{
    assert (freopen (PROBLEMNAME ".in", "r", stdin));
#ifndef LOCAL
    assert (freopen (PROBLEMNAME ".out", "w", stdout));
#endif // LOCAL

    int nChunks, d;
    scanf ("%d %d", &nChunks, &d);
    
    vector <int> sorted (nChunks);
    
    for (int i = 0; i < nChunks; i++)
        scanf ("%d", &sorted[i]);
        
    sort (sorted.rbegin(), sorted.rend());
    
    prefixSum[0] = 0;
    int answer = 0;
    for (int i = 0; i < nChunks; i++)
    {
        prefixSum[i + 1] = prefixSum[i] + sorted[i];
        
        int thisAnswer = 0;
        int nNow = i + 1;
        
        if (nNow == 1)
        {
            thisAnswer = sorted[0];
        }
        else if (nNow == 2)
        {
            thisAnswer = sorted[0] + sorted[1] - 2 * d;
        }
        else
        {
            if (sorted[i] <= d) continue;
            if (sorted[i - 1] < 3 * d) continue;
            thisAnswer = prefixSum[i] - (2 * d) * (i) + sorted[i];
        }
        
        DBG ("%d chunks ans %d", i + 1, thisAnswer);
        answer = max (thisAnswer, answer);
    }
    
    printf ("%d\n", answer);
    
    /*int answer = 0;
    int maxChunk = 2 * d, secondMaxChunk = 2 * d, thirdMaxChunk = 0;
    
    for (int i = 0; i < nChunks; i++)
    {
        int a;
        scanf ("%d", &a);
        
        if (a > 3 * d)
        {
            answer += a - 2 * d;
            DBG ("attach %d, answer is %d", a - 2 * d, answer);
        }
        else
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
            
            if (a > thirdMaxChunk)
                thirdMaxChunk = a;
        }
    }*/
    
    /* ... */
    
    /*if (answer != 0)
        printf ("%d\n", answer - 2 * d + maxChunk + secondMaxChunk);
    else
        printf ("%d\n", thirdMaxChunk);
    */
    
    return 0;
}

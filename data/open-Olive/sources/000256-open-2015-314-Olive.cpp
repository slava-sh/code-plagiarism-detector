/**
 * EASY.
**/

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <memory.h>
#include <stack>
#include <queue>
#include <deque>
#include <assert.h>


using namespace std;

int dist(int a, int pa)
{
    return a - pa;
}

int delta(int a, int pa, int b, int pb)
{
    return abs(a - pa) + abs(b - pb) - abs(a - pb) - abs(b - pa);
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int a;
    scanf("%d", &a);
    int curmax = a, curpos = 1;
    int maxd = 0;
    int oa = -1, ob = -1;
    for(int i = 2; i <= n; ++i)
    {
        scanf("%d", &a);

        if(delta(a, i, curmax, curpos) > maxd)
        {
            maxd = delta(a, i, curmax, curpos);
            oa = curpos;
            ob = i;
            //cout << "go update " << i << endl;
        }

        if(dist(a, i) > dist(curmax, curpos))
        {
            curmax = a;
            curpos = i;
        }
    }
    cout << oa << " " << ob << endl;
    return 0;
}

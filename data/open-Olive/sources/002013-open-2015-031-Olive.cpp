#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <map>
#include <stdlib.h>

using namespace std;

int a[1000010];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int answi = -2, answj = -2;
    int best = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int dist1 = abs(i - a[i]) + abs(j - a[j]);
            int dist2 = abs(i - a[j]) + abs(j - a[i]);
            //cout << i << ' ' << j << ' ' << dist1 << ' ' << dist2 << ' ' << dist2 - dist1 << '\n';
            if (dist2 - dist1 < best)
            {
                answi = i;
                answj = j;
                best = dist2 - dist1;
            }
        }
    }
    cout << answi + 1 << ' ' << answj + 1;
    return 0;
}


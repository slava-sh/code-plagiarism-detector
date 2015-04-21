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

int bub(int a[], int n)
{
    int b[n];
    for(int i = 0; i < n; ++i)
        b[i] = a[i];
    int c = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n - 1; ++j)
        {
            if(b[j] > b[j + 1])
            {
                swap(b[j], b[j + 1]);
                ++c;
            }
        }
    }
    return c;
}

pair<int, int> silly(int a[], int n)
{
    int opt = bub(a, n), oa = -2, ob = -2;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
            swap(a[i], a[j]);
            auto res = bub(a, n);
            //cout << i << " " << j << " -> " << res << endl;
            if(res < opt)
            {
                oa = i;
                ob = j;
                opt = res;
            }
            swap(a[i], a[j]);
        }
    cout << oa + 1 << " " << ob + 1 << endl;
    return {oa + 1, ob + 1};
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    //cout << bub(a, n) << endl;
    silly(a, n);
    return 0;
}

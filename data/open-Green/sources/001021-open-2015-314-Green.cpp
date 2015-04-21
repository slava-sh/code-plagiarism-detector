/**
 * “¿Ÿ»Ã
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


using namespace std;
//
const int TLE = 6;

long long go(long long x, int l, long long last)
{
    //printf("%*s", sp * 4, "");
    //cout << "go begin " << x << " " << l << endl;
    if(l == 1)
    {
        //printf("%*s", sp * 4, "");
        //cout << "end return " << x / 2 + x % 2 << endl;
        return x / 2 + x % 2;
    }

    vector<long long> nums;
    long long sqrt_x = sqrt(x);
    long long cur = 1e+16;
    int t = 0;

    for(int i = 1; i <= sqrt_x; ++i)
    {
        if(x % i == 0)
            nums.push_back(x / i);
        else
            continue;

        if(i < last)
            continue;

        auto res = (i / 2 + i % 2) * go(x / i, l - 1, i);

        if(res < 0)
            continue;

        cur = min(cur, res);

        if(++t >= TLE)
            break;
    }
    if(t < TLE)
    {
        reverse(nums.begin(), nums.end());
        for(auto i : nums)
        {
            auto res = (i / 2 + i % 2) * go(x / i, l - 1, i);

            if(res < 0)
                continue;

            cur = min(cur, res);

            if(++t >= TLE)
                break;
        }
    }
    if(cur == (long long)1e+16)
        return -1;

    return cur;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    long long n;
    int k;
    cin >> n >> k;
    cout << go(n, k, 0) << endl;
    return 0;
}

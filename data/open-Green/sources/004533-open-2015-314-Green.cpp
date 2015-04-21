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

int TLE = 1;
const int prime_size = 2e+7;
vector<bool> prime(prime_size, true);

long long go(long long x, int l, long long last)
{
    if(l == 1)
    {
        return x / 2 + x % 2;
    }

    vector<long long> nums;
    long long sqrt_x = sqrt(x);
    long long cur = 1e+16;
    int t = 0;

    for(long long i = 1; i <= sqrt_x; ++i)
    {
        if(x % i == 0)
            nums.push_back(x / i);
        else
        {
            if(x < prime_size and prime[x])
                break;
            continue;
        }


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
    if(cur > 2e+15)
        return -1;

    return cur;
}

int main()
{
    prime[0] = prime[1] = false;
    for(int i = 2; i < prime_size; ++i)
    {
        if(prime[i])
            for(int j = i + i; j < prime_size; ++j)
                prime[j] = false;
    }
    freopen("input.txt", "r", stdin);
    long long n;
    int k;
    cin >> n >> k;
    long long best = 1e+18;
    auto t = time(nullptr);
    for(; time(nullptr) - t < 3; ++TLE)
    {
        best = min(best, go(n, k, 0));
    }
    cout << best << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> d;

void get_d(long long n)
{
    long long x = 1;
    while (x <= n)
    {
        if (n % x == 0)
        {
            d.push_back(x);
        }
        x++;
    }
}

int main()
{
    long long N, K;
    cin >> N >> K;
    //get_d(N);
    long long MIN_ANS = N;
    if (K == 3)
    {
        cout << 2 << endl;
        return 0;
    }
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            long long t1 = i, t2 = N / i;
            long long ans2 = ((t2 - 1) / 2 + 1) * ((t1 - 1) / 2 + 1);
            MIN_ANS = min(MIN_ANS, ans2);
        }
    }
    cout << MIN_ANS << endl;
}

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

int get_max_val(long long n, int k)
{
    long long l = 0, r = d.size();
    while (r - l > 1)
    {
        long long m = (l + r) / 2;
        if (pow(d[m], k) <= n)
        {
            l = m;
        }
        else
        {
            r = m;
        }
        //cout << l << " " << r << endl;
    }
    return d[l];
}

int main()
{
    long long N, K;
    cin >> N >> K;
    get_d(N);
    long long MIN_ANS = N;
    if (K == 3)
    {
        cout << 2 << endl;
        return 0;
    }
    for (int i = 0; i < d.size(); i++)
    {
        long long t1 = d[i], t2 = N / d[i];
        long long ans2 = ((t2 - 1) / 2 + 1) * ((t1 - 1) / 2 + 1);
        MIN_ANS = min(MIN_ANS, ans2);
    }
    cout << MIN_ANS << endl;
}

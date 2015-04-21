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
    while (x * x <= n)
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
    /*for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;*/
    long long now_n = N;
    vector<long long> level;
    while (K > 0)
    {
        if (K == 1)
        {
            level.push_back(now_n);
            //cout << now_n << " " << level[level.size() - 1] << endl;
        }
        else
        {
            long long value = get_max_val(now_n, K);
            level.push_back(value);
            now_n /= value;
            //cout << value <<" " << level[level.size() - 1] << endl;
        }
        K--;
    }
    /*for (int i = 0; i < level.size(); i++)
    {
        cout << level[i] << " ";
    }
    cout << endl;*/
    long long ans = (level[level.size() - 1] - 1) / 2 + 1;
    for (int i = level.size() - 2; i >= 0; i--)
    {
        ans *= ((level[i] - 1) / 2 + 1);
    }
    cout << ans << endl;
}

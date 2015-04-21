#include <iostream>
//#include <ctime>
#include <set>
#include <cmath>
#include <unordered_map>
#define div _Unused_namE_

using namespace std;

unordered_map<int64_t, unordered_map<int, int64_t>> m;
unordered_map<int64_t, set<int64_t>> div;
//unordered_map<pair<int64_t, int>, int64_t> m;

const int64_t INF = int64_t(1000000000000) * 1000000;

void divc(int64_t n)
{
    if (div.find(n) != div.end())
        return;
    for (int64_t i = 2; i * i <= n; ++i)
    {
        if (n % i != 0)
            continue;
        divc(n / i), divc(i);
        if (div.find(n) == div.end())
        {
            auto x = div[i].begin(), y = div[n / i].begin();
            while (x != div[i].end() && y != div[n / i].end())
            {
                if (*x > *y)
                {
                    div[n].insert(div[n].end(), *(y++));
                    continue;
                }
                if (*y > *x)
                    div[n].insert(div[n].end(), *(x));
                x++;
            }
            while (x != div[i].end())
                div[n].insert(*(x++));
            while (y != div[n / i].end())
                div[n].insert(*(y++));
            div[n].insert(i);
            div[n].insert(n / i);
        }
    }
}

int64_t ans(int64_t n, int k)
{
    int debuh;
    if (k == 0)
        return (n + 1) / 2;
    if (n == 1)
        return 1;
    auto t = m.find(n);
    if (t != m.end() && t->second.find(k) != t->second.end())
        return m[n][k];
    m[n][k] = (n + 1) / 2;
    int x = pow(n, 1.0 / (k + 1));
    int am = 0;
    for (auto i = x + 1; i * i < n && am < 2; i++)
        if (n % i == 0)
        {
            debuh = m[n][k] = min(m[n][k], min(ans(n / (i), k - 1) * (((i) + 1) / 2), ans((i), k - 1) * ((n / (i) + 1) / 2)));
            am++;
        }
    am = 0;
    for (auto i = x; i && am < 2; i--)
        if (n % i == 0)
        {
            debuh = m[n][k] = min(m[n][k], min(ans(n / (i), k - 1) * (((i) + 1) / 2), ans((i), k - 1) * ((n / (i) + 1) / 2)));
            am++;
        }
    if (n % 2 == 0)
        debuh = m[n][k] = min(m[n][k], min(ans(n / (2), k - 1) * (((2) + 1) / 2), ans((2), k - 1) * ((n / (2) + 1) / 2)));
//    for (auto i = 2; i < 10 && i < x && i + x < n; i++)
//    {
//        if (n % i == 0)
//            debuh = m[n][k] = min(m[n][k], min(ans(n / (i), k - 1) * (((i) + 1) / 2), ans((i), k - 1) * ((n / (i) + 1) / 2)));
//    }
    return m[n][k];
}

int main()
{
    int k = 10;
//    int64_t n = 2073989836800000ll;
    int64_t n = 1000000000 * 1000000ll;
//    auto t = clock();
    cin >> n >> k;
//    divc(n);
//    cout << (clock() - t) * 1000.0 / CLOCKS_PER_SEC << '\n';
    cout << ans(n, k - 1);
//    cout << n << ", " << k << ": " << ans(n, k);
    return 0;
}

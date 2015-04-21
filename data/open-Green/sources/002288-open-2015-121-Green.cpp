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
            /*if (x * x != n)
            {
                d.push_back(n / x);
            }*/
        }
        x++;
    }
}

int main()
{
    long long N, K;
    cin >> N >> K;
    get_d(N);
    if (K == 1)
    {
        cout << (N - 1) / 2 + 1 << endl;
        return 0;
    }
    //sort(d.begin(), d.end());
    vector<vector<long long> > a(K + 1, vector<long long>(d.size()));
    for (int i = 0; i < d.size(); i++)
    {
        a[1][i] = (d[i] - 1) / 2 + 1;
        //cout << a[1][i] << " ";
    }
    //cout << endl;
    for (int i = 2; i <= K; i++)
    {
        for (int j = 0; j < d.size(); j++)
        {
            a[i][j] = (d[j] - 1) / 2 + 1;
            int now_i = j;
            while (now_i >= 0)
            {
                if (d[j] % d[now_i] == 0)
                {
                    a[i][j] = min(a[i][j], a[i - 1][now_i] * ((d[j] / d[now_i] - 1) / 2 + 1));
                }
                now_i--;
            }
            //cout << a[i][j] << " ";
        }
        //cout << endl;
    }
    cout << a[K][d.size() - 1] << endl;
    /*for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            long long t1 = i, t2 = N / i;
            long long ans2 = ((t2 - 1) / 2 + 1) * ((t1 - 1) / 2 + 1);
            MIN_ANS = min(MIN_ANS, ans2);
        }
    }
    cout << MIN_ANS << endl;*/
    return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

long long n, k, c, d;
vector<int> a;
vector<int> b;

#define INF 1791791791791791791LL

long long count_opt()
{
    vector<vector<long long> > opt(n + 1, vector<long long>(k + 1, INF));
    opt[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        opt[i][0] = INF;
        //for (int j = 1; j <= k; j++)
            //opt[i][0] = min(opt[i][0], opt[i - 1][j] + c + d * (a[i] - b[i - 1] + b[i] - a[i]));
        for (int j = 1; j <= k; j++)
        {
            opt[i][j] = INF;
            if (opt[i - 1][j - 1] != INF)
                opt[i][j] = min(opt[i][j], opt[i - 1][j - 1]);
            if (opt[i - 1][j] != INF)
                opt[i][j] = min(opt[i][j], opt[i - 1][j] + d * (a[i] - b[i - 1]));
            if (opt[i][j] != INF)
            {
                opt[i][j] += (b[i] - a[i]) * d;
            }
        }
        for (int j = 1; j <= k; j++)
            opt[i][0] = min(opt[i][0], opt[i][j] + c);
    }
    long long mn = INF;
    for (int i = 0; i <= k; i++)
        mn = min(mn, opt[n][i]);
    /*for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
            cout << opt[j][i] << " ";
        cout << endl;
    }*/
    return mn;
}

int main()
{
    cin >> n >> k >> c >> d;
    a.resize(n + 1, 0);
    b.resize(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i + 1] >> b[i + 1];
    b[0] = a[1];
    cout << count_opt() << endl;
    return 0;
}

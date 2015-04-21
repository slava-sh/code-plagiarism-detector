#include <iostream>
#include <cstring>

using namespace std;

int64_t b[100000], e[100000];
int64_t ans[4000][4000];

int main()
{
    memset(ans, 63, sizeof(ans));
    int64_t n, k, c, d, sum = ans[0][0];
    cin >> n >> k >> c >> d;
    for (int64_t i = 0; i < n; ++i)
        cin >> b[i] >> e[i];
    ans[0][k - 1] = (e[0] - b[0]) * d;
    for (int64_t i = 1; i < n; ++i)
    {
        for (int64_t j = 0; j < k; ++j)
        for (int64_t l = j; l < k; ++l)
            ans[i][j] = min(ans[i][j], min(ans[i - 1][l] + (b[i] - e[i - 1]) * d + (e[i] - b[i]) * d, ans[i - 1][l + 1] + (e[i] - b[i]) * d));
        for (int64_t l = 0; l < k; ++l)
            ans[i][k - 1] = min(ans[i][k - 1], ans[i - 1][l] + c + (e[i] - b[i]) * d);
    }
    for (int64_t j = 0; j < k; ++j)
        if (sum > ans[n - 1][j])
            sum = ans[n - 1][j];
    cout << sum;
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int l[n], r[n], x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i] >> x[i];
    }
    for (int i = 0; i < m; i++)
    {
        int y, ans = 0;
        cin >> y;
        for (int j = 0; j < n; j++)
        {
            if (l[j] <= y && r[j] >= y)
            {
                if ((y - l[j]) % 2 == 0)
                {
                    ans += x[j];
                }
                else
                {
                    ans -= x[j];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

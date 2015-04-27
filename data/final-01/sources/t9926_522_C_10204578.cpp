#include <iostream>
using namespace std;

const int M = 100005;
int cnt[M], cnt2[M];

int main()
{
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++)
    {
        int m, k;
        cin >> m >> k;
        for (int i = 1; i <= k; i++)
            cin >> cnt[i];

        int left = 0, left2 = 0;
        bool flag = false;

        for (int i = 1; i <= m-1; i++)
        {
            int j, r;
            cin >> j >> r;
            if (!flag && r == 1)
            {
                flag = true;
                for (int l = 1; l <= k; l++) cnt2[l] = cnt[l];
            }

            if (flag)
            {
                if (j == 0) left2++;
                else cnt2[j]--;
            }
            else
            {
                if (j == 0) left++;
                else cnt[j]--;
            }
        }

        int min_cnt = M;
        if (flag)
        {
            for (int i = 1; i <= k; i++)
                if (cnt[i] == cnt2[i]) min_cnt = min(min_cnt, cnt[i]);
        }

        for (int i = 1; i <= k; i++)
        {
            if (flag)
            {
                if (cnt[i] == cnt2[i] && cnt[i] <= left) cout << "Y";
                else if (cnt2[i] <= (left - min_cnt) + left2) cout << "Y";
                else cout << "N";
            }
            else
            {
                if (cnt[i] <= left) cout << "Y";
                else cout << "N";
            }
        }
        cout << endl;
    }
}

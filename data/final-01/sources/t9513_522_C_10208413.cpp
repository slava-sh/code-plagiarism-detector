#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    vector<vector<char> > output;

    cin >> N;
    for (int val = 0; val < N; ++val)
    {

        int m, k;
        cin >> m >> k;

        vector<int> a;
        a.resize(k);
        cin >> a[0];
        int min = a[0];
        for (int i = 1; i < k; ++i)
        {
            cin >> a[i];
            if (a[i] > min)
                min = a[i];
        }

        vector<int> res, max, mas_of_t;
        max.assign(k,-1);
        res.assign(k,0);
        mas_of_t.resize(m - 1);
        int num_of_first = -1;
        int r;
        for (int i = 0; i < m - 1; ++i)
        {
            cin >> mas_of_t[i] >> r;
            --mas_of_t[i];
            if (mas_of_t[i] != -1)
                max[mas_of_t[i]] = i;
            if ((r == 1) && (num_of_first == -1))
                num_of_first = i;
        }

        int num = 0;
        vector<int> cnd;
        cnd.assign(k,0);
        for (int i = 0; i < k; ++i)
        {
            if (max[i] < num_of_first)
            {
                cnd[i] = 1;
                if (a[i] <= min)
                {
                    min = a[i];
                    num = i;
                }
            }
        }

        int K = 0;
        for (int i = 0; i < m - 1; ++i)
        {
            if (i == num_of_first)
            {
                for (int j = 0; j < k; ++j)
                {
                    if ((cnd[j] == 1) && (a[j] <= K))
                        res[j] = 1;
                }
                K -= a[num];
            }
            int t = mas_of_t[i];
            if (t != -1)
            {
                a[t] -= 1;
                if ((cnd[t] == 1) && (a[t] < min))
                {
                    min = a[t];
                    num = t;
                }
            }
            else
                ++K;
        }
        vector<char> tmp;
        for (int i = 0; i < k; ++i)
        {
            if ((a[i] - K < 1) || (res[i] != 0))
                tmp.push_back('Y');
            else
                tmp.push_back('N');
        }
        output.push_back(tmp);
    }
    for (int i = 0; i < N; ++i)
    {
        for (unsigned int j = 0; j < output[i].size(); ++j)
            cout << output[i][j];
        cout << endl;
    }
    return 0;
}

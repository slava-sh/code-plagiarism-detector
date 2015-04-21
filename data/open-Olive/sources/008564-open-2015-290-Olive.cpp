#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int bubble_sort(vector<int> a)
{
    int n = a.size(), res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j - 1] > a[j])
            {
                res += 1;
                swap(a[j], a[j - 1]);
            }
        }
    }
    return res;
}

/*int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k = bubble_sort(a);
    int i_min = -1, j_min = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int nk = k;
            int ti = a[i], tj = a[j];
            for (int t = i; t <= j; t++)
                if (a[i] > a[t])
                    nk -= 1;
            for (int t = i + 1; t <= j; t++)
                if (a[t] > a[j])
                    nk -= 1;
            a[i] = tj; a[j] = ti;
            for (int t = i; t <= j; t++)
                if (a[i] > a[t])
                    nk += 1;
            for (int t = i + 1; t <= j; t++)
                if (a[t] > a[j])
                    nk += 1;
            cout << i << " " << j << " " << k << " " << nk << " " << bubble_sort(a) << endl;
            assert(nk == bubble_sort(a));
            swap(a[i], a[j]);
            if (nk < k)
            {
                k = nk;
                i_min = i + 1;
                j_min = j + 1;
            }
        }
    }
    cout << i_min << " " << j_min << endl;
    return 0;
}*/

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int> > inv_b(n, vector<int>(n));
    vector<vector<int> > inv_f(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        inv_b[i][i] = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            inv_b[i][j] = inv_b[i][j + 1];
            if (a[j] > a[i])
                inv_b[i][j] += 1;
        }
        inv_f[i][i] = 0;
        for (int j = i + 1; j < n; j++)
        {
            inv_f[i][j] = inv_f[i][j - 1];
            if (a[j] < a[i])
                inv_f[i][j] += 1;
        }
    }
    int k = bubble_sort(a);
    int min_i = -1, min_j = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int nk = k - inv_b[j][i + 1] - inv_f[i][j - 1];
            for (int t = i + 1; t < j; t++)
            {
                if (a[t] < a[j])
                    nk += 1;
                if (a[t] > a[i])
                    nk += 1;
            }
            if (nk < k)
            {
                k = nk;
                min_i = i + 1;
                min_j = j + 1;
            }
        }
    }
    cout << min_i << " " << min_j << endl;
    return 0;
}

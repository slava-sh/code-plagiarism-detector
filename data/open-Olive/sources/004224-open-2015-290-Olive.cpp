#include <iostream>
#include <vector>

using namespace std;

int bubble_sort(vector<int> a)
{
    int n = a.size(), res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                res += 1;
                swap(a[j], a[j + 1]);
            }
        }
    }
    return res;
}

int main()
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
        for (int j = 0; j < n; j++)
        {
            swap(a[i], a[j]);
            int nk = bubble_sort(a);
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
}

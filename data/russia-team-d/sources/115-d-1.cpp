#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector <int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int l = 0, r = A[0] + 1;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        int now = A[0] - 1;
        for (int i = 0; i < n; i++)
        {
            now += mid;
        }
        if (now > k)
            r = mid;
        else
            l = mid;
    }
    cout << l << endl;
    return 0;
}

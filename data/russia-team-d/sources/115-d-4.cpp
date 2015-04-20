#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    vector <long long> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    long long l = 0, r = A[0] + 1;
    while (r - l > 1)
    {
        long long mid = (l + r) / 2;
        long long now = A[0];
        for (int i = 1; i < n; i++)
        {
            now += max(mid, A[i] - A[i - 1]);
        }
        if (now > k)
            r = mid;
        else
            l = mid;
    }
    cout << l << endl;
    return 0;
}

#include <iostream>
#include <fstream>

using namespace std;

const long long int Max_n = 301000;
const long long int inf = 10000000000;
long long int A[Max_n];

int main()
{
    freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);
    long long int n, d;
    cin >> n >> d;
    long long int i;
    for (i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    A[n] = inf;
    long long int l = 0;
    long long int r = 0;
    long long int num = 0;
    while (l != n)
    {
        while (A[r] - A[l] <= d)
        {
            r += 1;
        }
        num += n - r;
        l += 1;
    }
    cout << num;
    return 0;
}

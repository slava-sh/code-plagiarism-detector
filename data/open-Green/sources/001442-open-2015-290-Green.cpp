#include <iostream>
#include <vector>

using namespace std;

long long generate_next(long long n, int k, int last)
{
    if (k == 1)
        return (n + 1) / 2;
    long long ans = 1791791791791791;
    for (long long i = last; i > 0; i--)
    {
        if (n % i == 0)
            ans = min(ans, ((i + 1) / 2) * generate_next(n / i, k - 1, i));
    }
    return ans;
}

int main()
{
    long long n; int k;
    cin >> n >> k;
    cout << generate_next(n, k, n) << endl;
    return 0;
}

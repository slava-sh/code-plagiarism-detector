#include <iostream>

using namespace std;

int b[100000], e[100000];

int main()
{
    int n, k, c, d, sum = 0;
    cin >> n >> k >> c >> d;
    for (int i = 0; i < n; ++i)
        cin >> b[i] >> e[i];
    sum = (e[0] - b[0]) * d;
    for (int i = 1; i < n; ++i)
        sum += min((b[i] - e[i - 1]) * d, c) + (e[i] - b[i]) * d;
    cout << sum;
    return 0;
}

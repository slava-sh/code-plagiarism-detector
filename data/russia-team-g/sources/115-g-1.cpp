#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    long long N, M;
    cin >> N >> M;
    --N;
    --M;
    if (N == 0 && M == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    if (N == 0 || M == 0)
    {
        int k = 0;
        if ((max(N, M) - 1) % 4 != 0)
        {
            k = 1;
        }
        cout << (max(N, M) - 1) / 4 + k << endl;
        return 0;
    }
    long long D = min(N, M) - 1;
    int k = 0;
        if (D % 4 != 0)
        {
            k = 1;
        }
        cout << D / 4 + k << endl;
        return 0;
}

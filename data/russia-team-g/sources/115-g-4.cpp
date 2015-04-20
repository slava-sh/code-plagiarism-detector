#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    long long k = min(n, m);
    if (k < 3)
        cout << "0" << endl;
    else if (k == 3)
    {
        cout << "1" << endl;
    }
    else
    {
        cout << (k - 3) / 4 + 1 << endl;
    }
    return 0;
}

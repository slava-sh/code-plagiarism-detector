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
    long long k1 = max(n, m);
    if (k == 1)
    {
        if (k1 < 3)
        {
            cout << "0" << endl;
            return 0;
        }
        else if (k1 == 3)
        {
            cout << "1" << endl;
            return 0;
        }
        else
        {
            cout << (k1 - 3) / 4 + 1 << endl;
            return 0;
        }
    }
    if (k < 3)
    {
        cout << "0" << endl;
        return 0;
    }
    cout << 1 << endl;
    return 0;
}

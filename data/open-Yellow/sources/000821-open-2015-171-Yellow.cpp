#include <iostream>
#include <vector>

using namespace std;

const long long inf = 1e10;

int main()
{
    long long n, q, i, impas = 0, p , c;
    cin >> n;
    vector<long long> t(n + 2, inf);
    for (i = 0; i < n; i++)
    {
        cin >> t[i + 1];
        if (t[i + 1] != t[i]) impas++;
    }
    cin >> q;
    for (i = 0; i<q; i++)
    {
        cin >> p >> c;
        impas -= (t[p] != t[p - 1]) + (t[p] != t[ p + 1]);
        t[p] = c;
        impas += (t[p] != t[p - 1]) + (t[p] != t[ p + 1]);
        cout << impas << endl;
    }
//    for (auto w:t)
//    {
//        cout << w << ' ';
//    }
    return 0;
}

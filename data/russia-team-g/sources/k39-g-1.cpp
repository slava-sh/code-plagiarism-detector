#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define sc scanf
#define pr printf
#define fi first
#define se second
#define mk make_pair
#define pb push_back

int d[300002];

int main()
{
    //freopen ("in.txt", "r", stdin);freopen ("out.txt", "w", stdout);
    freopen ("prizes.in", "r", stdin);freopen ("prizes.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    if (n <= 2 && m <= 2)
    {
        cout << 0;
        return 0;
    }
    if (n == 1)
    {
        cout << m / 4;
        return 0;
    }
    if (m == 1)
    {
        cout << n / 4;
        return 0;
    }
    cout << 1;
}

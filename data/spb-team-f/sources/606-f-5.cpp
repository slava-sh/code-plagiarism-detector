#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

long long nod(int a,int b)
{
    if (b != 0)
    {
        return nod(b, a % b);
    }
    else
    {
        return a;
    }
}

int main()
{
    freopen("gcm.in","r", stdin);
    freopen("gcm.out","w", stdout);
    long long a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    long long d = nod(a, b);
    a/=d; b/=d;
    long long x, y;
    for (int i = 1; i <= sqrt(b / a); i++)
    {
        if (b % i == 0)
        {
            x = a * i; y = b / i;
        }
    }
    cout << x * d<<" "<< y * d;
    return 0;
}

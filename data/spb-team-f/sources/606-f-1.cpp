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
    long long c = a * b;
    long long d = nod(a, b);
    c/=d*d;
    for (int i = sqrt(c); i >= 1; i--)
    {
        if (c % i == 0)
        {
            if (nod(i,c/i) == 1)
            {
                cout << i * d << " " << (c/i)*d;
                return 0;
            }
        }
    }
    return 0;
}

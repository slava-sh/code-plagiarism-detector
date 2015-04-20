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
    long long d = nod(a, b);
    a/=d; b/=d;
    int x, y;
    for (int i = 1; i <= sqrt(double(b) / double(a)); i++)
    {
        if (b % i == 0)
        {
            x = a * i; y = b / i;
        }
    }
    cout << x <<" "<< y;
    return 0;
}

#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#pragma comment (linker, "/STACK:136667216")

using namespace std;

vector <int> d;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}
int main()
{
    freopen("gcm.in", "r", stdin);
    freopen("gcm.out", "w", stdout);
    long long a, b, x, y, p, g, w, xbest = 0, ybest = 0, best = 1LL << 40;
    cin >> a >> b;
    int a1 = a, b1 = b;
    g = gcd(a, b);
    a /= g;
    b /= g;
    w = sqrt(a);
    for(int i = 2; i <= w; i++){
        long long q = 1;
        while(a % i == 0)
            q *= i, a /= i;
        if(q != 1)
            d.push_back(q);
    }
    if(a > 1)
        d.push_back(a);
    w = sqrt(b);
    for(int i = 2; i <= w; i++){
        long long q = 1;
        while(b % i == 0)
            q *= i, b /= i;
        if(q != 1)
            d.push_back(q);
    }
    if(b > 1)
        d.push_back(b);
    //for(int i = 0; i < d.size(); i++)
    //    cout << d[i] << ' ';
    for(int i = 0; i <= (1 << d.size()); i++){
        x = y = 1;
        for(int j = 0; j < d.size(); j++)
            if(i & (1 << j))
                x *= d[j];
            else
                y *= d[j];
        //cout << x << ' ' << y << ' ' << best << endl;
        if(abs(x - y) < best)
            best = abs(x - y), xbest = x, ybest = y;
    }
    if(xbest > ybest){
        w = xbest;
        xbest = ybest;
        ybest = w;
    }
    cout << xbest * g << ' ' << ybest * g << endl;
    return 0;
}

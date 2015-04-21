#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    long long n, k, i, ans = 1, buf, j, pred;
    cin >> n >> k;
    if (n == 1) {cout << 1 << endl; return 0;}
    vector<int> a;
    i = 0; buf = n;
    j = 2;
    pred = ceil(sqrt(buf)) + 10;
    while (i < k && buf > 1 && j <= pred)
    {
        if (buf % j == 0)
        {
            a.push_back(j);
            buf/=j;
            i++;
        }
        else
        {
            j++;
        }
    }
    if (i < k && buf > 1)
        a.push_back(buf);
    else
    a[a.size()-1]*=buf;
    ans = 1;
    for (i = 0; i < a.size(); i++)
        ans *=a[i]/2 + a[i]%2;
    cout << ans << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    long long n, k, i, buf, del, ans, k1, pred, l, r;
    cin >> n >> k;
    vector<long long> a;
    buf = n;
    del = 0;
    while (buf % 2 == 0 && del < k)
    {
        del++;
        buf/=2;
    }
    if (del >= k) {cout << buf << endl; return 0;}
    k1 = k - del;
    pred = ceil(sqrt(buf)) + 10;
    l = floor(pow(buf, (double)1 / (double)k1));
    r = max(l + 1, (long long )3);
    while (k1 > 0 && buf > 1)
        {
            if (l <= 2 && r >= pred) {k1--; a.push_back(1);}
            if (l > 2)
            {
                if (buf % l == 0)
                {
                    a.push_back(l);
                    k1--;
                    buf /= l;
                }
                else l--;
            }
            if (r < pred)
            {
                if (buf % r == 0)
                {
                    a.push_back(r);
                    k1--;
                    buf /= r;
                }
                else r++;
            }
        }
    sort(a.begin(), a.end());
    a[0] *= buf;
    ans = 1;
    //cout << k - del << endl;
    for (i = 0; i < a.size(); i++)
        {ans *= a[i]/2 + a[i]%2;} //cout << a[i] << ' ';}
        //cout << endl;
    cout << ans << endl;
    return 0;
}

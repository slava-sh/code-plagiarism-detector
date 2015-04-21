#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, i, j, l, r, ans, mid;
    cin >> n;
    vector<int> h(n + 1);
    for (i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    if (n == 1) {cout << "-1 -1\n"; return 0;}
    h[n] = n + 1;
    vector<int> d(n + 2, 0);
    vector<int> pred(n + 1), num(n + 1, n + 1);
    d[0] = n + 1;
    for (i = 0; i < n; i++)
    {
        l = 0;
        r = n + 1;
        while (l + 1 < r)
        {
            mid = (l + r)/2;
            if (d[mid] < h[i]) r = mid;
            else l = mid;
        }
        if (d[l + 1] < h[i]) {d[l + 1] = h[i]; num[l + 1] = i; pred[i] = num[l];}
    }
//    for (auto w: d)
//        cout << w << ' ';
//        cout << endl;
//        for (auto w: pred)
//            cout << w<< ' ' ;
//        cout << endl;
//    for (auto w:num)
//        cout << w << ' ';
//    cout << endl;
    if (d[2] == 0) {cout << "-1 -1\n"; return 0;}
    for (i = 0; i < n + 2; i++)
        if (d[i] == 0)
        {
            r = num[i - 1];
            l = r;
            while (pred[l]!=n+1)
                l = pred[l];
                cout << l + 1<< ' ' << r + 1;
            return 0;
        }
    return 0;
}

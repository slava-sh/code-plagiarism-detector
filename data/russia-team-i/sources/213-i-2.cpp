#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream cin("sochi.in");
    ofstream cout("sochi.out");
    int n, d;
    cin >> n >> d;
    vector<int> a;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    long long len = 0;
    int pos = -1;
    int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] >= 3 * d)
            len += a[i], cnt++;
        if(a[i] < 3 * d)
        {
            pos = i;
            break;
        }
    }
    if(pos != -1)
    {
        if(pos == n - 1 && a[pos] > 2 * d)
            len += a[pos], cnt++;
        if(pos <= n - 2)
        {
            if(a[pos] > 2 * d)
                len += a[pos], cnt++;
            if(a[pos + 1] > 2 * d)
                len += a[pos+1], cnt++;
        }
    }
    if(cnt == 0)
        cout << a[0] << endl;
    else
        cout << len - 2 * (cnt - 1) * d << endl;
    return 0;
}


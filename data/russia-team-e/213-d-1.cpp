#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int n, k;
vector<int> a;
bool f(long long x)
{
    long long t = 0;
    for(int i = 0; i < a.size(); ++i)
    {
        if(t >= a[i] - x)
            t += x;
        else
            t = a[i];
        if(k - t < x * (a.size() - i - 1))
            return false;
    }
    return true;
}
int main()
{
    ifstream cin("fence.in");
    ofstream cout("fence.out");
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    long long l = 0, r = min((k / n) + 1, a[0] + 1);
    for(int i = 0; i < 100; ++i)
    {
        long long m = (l + r) / 2;
        //cout << m << " " << l << endl;
        if( f(m))
            l = m;
        else
            r = m;
    }
    cout << l << endl;
    return 0;
}


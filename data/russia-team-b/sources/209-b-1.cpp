#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream cin("che.in");
    ofstream cout("che.out");
    long long ans, r;
    int n;
    vector <long long> in;
    cin >> n >> r;
    in.resize(n);
    for(int i = 0; i < n; ++i)
        cin >> in[i];
    sort(in.begin(), in.end());
    ans = 0;
    for(int i = 0; i < n; ++i)
    {
        int left = 0, right = n;
        while(right - left > 1)
        {
            int m = (left + right) / 2;
            if(in[m] < in[i] - r)
                left = m;
            else
                right = m;
        }
        if(in[left] < in[i] - r)
            ans += left + 1;
        left = -1, right = n - 1;
        while(right - left > 1)
        {
            int m = (left + right) / 2;
            if(in[m] > in[i] + r)
                right = m;
            else
                left = m;
        }
        if(in[right] > in[i] + r)
            ans += n - right;
    }
    cout << ans / 2 << endl;
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include<cmath>
#include<algorithm>

using namespace std;



int main(){
    freopen ("merlin.in", "r", stdin);
    freopen ("merlin.out", "w", stdout);
    int n, a;
    vector<int> nums;
    cin >> n;
    int l = -1, r = n, m;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        nums.push_back(a);
    }
    sort(nums.begin(), nums.end());
    long long sum, su;
    while (r - l > 1)
    {
        sum = 0;
        m = (r + l) / 2;
        //cerr << r << ' ' << l << ' ' << m << endl;
        for (int i = 0; i < m; i++) sum += nums[nums.size() - 1 - i];
        su = 0;
        for (int i = 0; i < nums.size() - m - 1; i++) su += nums[nums.size() - m - 1] - nums[i];
        if (sum >= su) r = m;
        else l = m;

    }
    cout << r << endl;
    return 0;
}

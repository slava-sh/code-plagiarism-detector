#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    long long n, k, c, d, i, a, b, b1, sum, ans, vk, sum1;
    cin >> n >> k >> c >> d;
    vector<long long> st(n - 1);
    cin >> a >> b1;
    sum = (b1 - a) * d;
    for (i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        st[i] = (a - b1)*d;
        sum+=(b - a)*d;
        b1 = b;
    }
    sort(st.begin(), st.end());
    vk = n;
    sum1 = 0;
    ans = (vk/k + (vk%k!= 0) - 1)*c;
    for (i = 0; i < n - 1; i++)
    {
        vk--;
        sum1+=st[i];
        //cout << ans << ' ' << sum1 <<  ' ' << (vk/k + (vk%k!= 0))*c << endl;
        ans = min(ans, (vk/k + (vk%k!= 0) - 1)*c + sum1);
    }
    cout << ans + sum;
    return 0;
}

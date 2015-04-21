#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long N, K, C, D;
    cin >> N >> K >> C >> D;
    vector<long long> per(N - 1);
    long long count_dl = 0;
    long long count_per = 0;
    long long prev_b = -1;
    for (long long i = 0; i < N; i++)
    {
        long long a, b;
        cin >> a >> b;
        count_dl += (b - a);
        if (i > 0)
        {
            per[i - 1] = a - prev_b;
            count_per += per[i - 1];
        }
        prev_b = b;
    }
    long long MIN = D * (count_dl + count_per);
    //cout << MIN << endl;
    long long last_k = K - 1;
    long long now_p = MIN;
    sort(per.begin(), per.end());
    for (long long i = per.size() - 1; i >= 0; i--)
    {
        last_k--;
        if (last_k < 0)
        {
            now_p += C;
            last_k = K - 1;
        }
        now_p -= per[i] * D;
        //cout << now_p << endl;
        MIN = min(MIN, now_p);
    }
    cout << MIN << endl;
}

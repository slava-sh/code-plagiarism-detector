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
    vector<pair<int, int> > t(N);
    vector<int> per(N - 1);
    vector<int> dl(N);
    long long count_dl = 0;
    long long count_per = 0;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        t[i] = make_pair(a, b);
        dl[i] = b - a;
        count_dl += (b - a);
        if (i > 0)
        {
            per[i - 1] = a - t[i - 1].second;
            count_per += per[i - 1];
        }
    }
    long long MIN = D * count_dl + count_per * D;
    int last_k = K - 1;
    long long now_p = MIN;
    sort(per.begin(), per.end());
    for (int i = per.size() - 1; i >= 0; i--)
    {
        last_k--;
        if (last_k < 0)
        {
            now_p += C;
        }
        now_p -= per[i] * D;
        MIN = min(MIN, now_p);
    }
    cout << MIN << endl;
}

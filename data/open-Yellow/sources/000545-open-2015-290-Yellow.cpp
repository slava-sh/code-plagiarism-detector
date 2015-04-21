#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class street
{
    vector<int> cur;
  public:
    street(const vector<int>& start)
    {
        cur = start;
    }
    int update(int k, int t)
    {
        cur[k] = t;
        int ans = 0;
        int current = 1791791791;
        for (int i = 0; i < (int)cur.size(); i++)
        {
            if (cur[i] != current)
                ans += 1;
            current = cur[i];
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> start(n);
    for (int i = 0; i < n; i++)
        cin >> start[i];
    street st = start;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int k, t;
        cin >> k >> t;
        cout << st.update(k - 1, t) << endl;
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class street
{
    vector<int> cur;
    int cur_ans = 0;
  public:
    street(const vector<int>& start)
    {
        cur = start;
        int current = 1791791791;
        for (int i = 0; i < (int)start.size(); i++)
        {
            if (cur[i] != current)
                cur_ans += 1;
            current = cur[i];
        }
    }
    int update_cur_ans(int k, int t)
    {
        if (cur[k] == t)
            return cur_ans;
        int n = cur.size();
        if (n == 1)
            return 1;
        if (k == 0)
        {
            if (cur[k] != cur[k + 1])
            {
                if (cur[k + 1] == t)
                {
                    cur_ans -= 1;
                    return cur_ans;
                }
                else
                    return cur_ans;
            }
            else
            {
                cur_ans += 1;
                return cur_ans;
            }
        }
        if (k == n - 1)
        {
            if (cur[k] != cur[k - 1])
            {
                if (cur[k - 1] == t)
                {
                    cur_ans -= 1;
                    return cur_ans;
                }
                else
                    return cur_ans;
            }
            else
            {
                cur_ans += 1;
                return cur_ans;
            }
        }
        if (cur[k - 1] == cur[k + 1])
        {
            if (t == cur[k - 1])
            {
                cur_ans -= 2;
                return cur_ans;
            }
            else if (cur[k] == cur[k - 1])
            {
                cur_ans += 2;
                return cur_ans;
            }
            else
                return cur_ans;
        }
        else
        {
            if (cur[k] == cur[k - 1])
            {
                if (cur[k + 1] == t)
                    return cur_ans;
                else
                {
                    cur_ans += 1;
                    return cur_ans;
                }
            }
            else if (cur[k] == cur[k + 1])
            {
                if (cur[k - 1] == t)
                    return cur_ans;
                else
                {
                    cur_ans += 1;
                    return cur_ans;
                }
            }
            else
            {
                if (cur[k - 1] == t)
                {
                    cur_ans -= 1;
                    return cur_ans;
                }
                else if (cur[k + 1] == t)
                {
                    cur_ans -= 1;
                    return cur_ans;
                }
                else
                    return cur_ans;
            }
        }
    }
    int update(int k, int t)
    {
        update_cur_ans(k, t);
        cur[k] = t;
        return cur_ans;
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

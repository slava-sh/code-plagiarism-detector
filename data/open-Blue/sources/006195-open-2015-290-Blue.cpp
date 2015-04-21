#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const long long m = 5LL;
const long long p = 1000000007LL;

long long mod(long long n)
{
    return ((n % p) + p) % p;
}

int is_cyclear(string s, int l, int g = 0)
{
    int n = s.size();
    vector<long long> hashes(n + 1);
    hashes[0] = 0;
    for (int i = 1; i <= n; i++)
        hashes[i] = mod(hashes[i - 1] * m + s[i - 1] - 'a' + 1);
    vector<long long> m_pows(n + 1, 1);
    for (int i = 1; i <= n; i++)
        m_pows[i] = mod(m_pows[i - 1] * m);
    for (int i = 1; i <= l && i <= n; i++)
    {
        if (n % i == 0 && g % i == 0 && hashes[n - i] == mod(hashes[n] - hashes[i] * m_pows[n - i]))
            return i;
    }
    return 0;
}

string to_string(char c)
{
    string res = "";
    res.push_back(c);
    return res;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    if (a < b)
        return gcd(b, a);
    return gcd(b, a % b);
}

vector<string> get_ans(string s, int l)
{
    if (is_cyclear(s, l))
        return {s.substr(0, is_cyclear(s, l))};
    set<char> st;
    for (char c : s)
        st.insert(c);
    if (st.size() < 3)
    {
        vector<string> res;
        for (char c : st)
            res.push_back(to_string(c));
        return res;
    }
    int n = s.size();
    vector<long long> hashes(n + 1);
    hashes[0] = 0;
    for (int i = 1; i <= n; i++)
        hashes[i] = mod(hashes[i - 1] * m + s[i - 1] - 'a' + 1);
    vector<long long> m_pows(n + 1, 1);
    for (int i = 1; i <= n; i++)
        m_pows[i] = mod(m_pows[i - 1] * m);
    for (int i = 0; i < l; i++)
    {
        vector<bool> in_use(n, true);
        for (int j = 0; j <= i; j++)
            in_use[j] = false;
        int j = i + 1;
        while (j + i < n)
        {
            if (mod(hashes[j + i + 1] - hashes[j] * m_pows[i + 1]) == hashes[i + 1])
            {
                for (int k = j; k <= j + i; k++)
                    in_use[k] = false;
                j += i + 1;
            }
            else
                j += 1;
        }
        string t = "";
        for (j = 0; j < n; j++)
            if (in_use[j])
                t.push_back(s[j]);
        int cur = !in_use[0];
        int g = 0;
        for (j = 1; j < n; j++)
        {
            if (in_use[j])
            {
                if (!in_use[j - 1])
                    g = gcd(g, cur);
            }
            else
            {
                if (in_use[j - 1])
                    cur = 0;
                cur += 1;
            }
        }
        if (!in_use[n - 1])
            g = gcd(g, cur);
        if (is_cyclear(t, l, g))
        {
            return {s.substr(0, i + 1), t.substr(0, is_cyclear(t, l, g))};
        }
    }
    return {"a", "b", "c"};
}

int main()
{
    string s;
    int l;
    cin >> l >> s;
    vector<string> res = get_ans(s, l);
    cout << res.size() << endl;
    for (string& t : res)
        cout << t << endl;
    return 0;
}

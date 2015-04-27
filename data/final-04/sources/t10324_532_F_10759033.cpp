
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>

using namespace std;

struct Hash
{
    long long MOD;
    long long P;
    vector <long long> p;
    vector <long long> pow;
    Hash(string &s, long long MOD, long long P)
    {
        this->MOD = MOD;
        this->P = P;
        int n = s.size();
        p.assign(n + 1, 0);
        pow.assign(n + 1, 0);
        pow[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            pow[i] = (pow[i - 1] * P) % MOD;
            p[i] = ((p[i - 1] * P) % MOD + s[i - 1]) % MOD;
        }
    }
    //[i, j]: 1 - numeration
    bool equal(int i, int j, long long X)
    {
//         cout << P << "\n";
//         cout << p[j] << " " << p[i - 1] << " " << pow[j - i + 1] << " " << i << " " << j << "\n";
        return ((p[j] - ((p[i - 1] * pow[j - i + 1]) % MOD) + MOD) % MOD == X);
    }
};

const long long MOD1 = 2147483647;
const long long P1 = 257;
const long long MOD2 = 2147483629;
const long long P2 = 263;

long long PP1[26];
long long PP2[26];

int main()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector <int> ans;
    vector <vector <int> > first(n, vector <int> (26, INT_MAX));
    
    for (int i = n - 1; i >= 0; --i)
    {
        if (i != n - 1)
            for (int j = 0; j < 26; ++j)
                first[i][j] = first[i + 1][j];
        first[i][s[i] - 'a'] = i;
        
    }
    
    vector <int> in(26, 0);
    for (int i = 0; i < m; ++i)
    {
        in[t[i] - 'a'] = 1;
    }
    
    int ccnt = 0;
    for (int i = 0; i < 26; ++i)
        ccnt += in[i];
    
    Hash s1(s, MOD1, P1);
    Hash s2(s, MOD2, P2);
    Hash t1(t, MOD1, P1);
    Hash t2(t, MOD2, P2);
    
    
    for (int i = 0; i < m; ++i)
    {
        int c = t[i] - 'a';
        PP1[c] += t1.pow[m - i - 1];
        PP1[c] %= MOD1;
        PP2[c] += t2.pow[m - i - 1];
        PP2[c] %= MOD2;
    }
//     for (int i = 0; i < 26; ++i)
//     {
//         cout << PP1[i] << "\n";
//     }
    
    for (int i = 0; i < n - m + 1; ++i)
    {
        vector <int> perm(26, -1);
        bool flag = 1;
        int cnt = 0;
        for (int j = 0; j < 26; ++j)
        {
            if (first[i][j] <= i + m - 1)
            {
                ++cnt;
                if (perm[j] != -1)
                {
                    if (perm[j] != t[first[i][j] - i] - 'a')
                    {
                        flag = 0;
                        break;
                    }
                }
                if (perm[t[first[i][j] - i] - 'a'] != -1)
                {
                    if (perm[t[first[i][j] - i] - 'a'] != j)
                    {
                        flag = 0;
                        break;
                    }
                }
                perm[t[first[i][j] - i] - 'a'] = j;
                perm[j] = t[first[i][j] - i] - 'a';
            }
        }
        long long newHash1 = 0, newHash2 = 0;
        for (int j = 0; j < 26; ++j)
        {
            if (perm[j] != -1)
            {
                newHash1 += 1ll * (perm[j] + 'a') * PP1[j];
                newHash1 %= MOD1;
                newHash2 += 1ll * (perm[j] + 'a') * PP2[j];
                newHash2 %= MOD2;
            }
        }
        if (flag && cnt == ccnt && s1.equal(i + 1, i + m - 1 + 1, newHash1) && s2.equal(i + 1, i + m - 1 + 1, newHash2))
        {
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " " ;
    if (ans.size())
        cout << "\n";
    return 0;
}
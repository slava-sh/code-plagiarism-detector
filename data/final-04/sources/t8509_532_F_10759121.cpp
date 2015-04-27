#include <bits/stdc++.h>

using namespace std;

const unsigned long long p = 179, q = (1ll << 61) - 1;

inline unsigned long long mulMod(unsigned long long a, unsigned long long b)
{
    return (a * b - (unsigned long long)((long double)a * b / q) * q + 5 * q) % q;
}

inline unsigned long long getHash(int l, int r, unsigned long long P, vector<vector<unsigned long long>> & V, vector<char> mul)
{
    unsigned long long ans = 0;
    for (size_t i = 0; i < V[r].size(); i++)
        ans = (ans + mulMod(V[r][i], mul[i])) % q;
    for (size_t i = 0; i < V[l].size(); i++)
        ans = (ans + q - mulMod(mulMod(V[l][i], mul[i]), P)) % q;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string S, SS;
    cin >> S >> SS;
    vector<vector<int>> Salph(S.size() + 1, vector<int>(26));
    vector<vector<unsigned long long>> HS(S.size() + 1, vector<unsigned long long>(26));
    vector<unsigned long long> HSS(SS.size() + 1), P(300000);
    HSS[0] = 0;
    P[0] = 1;
    for (size_t i = 1; i < P.size(); i++)
        P[i] = mulMod(P[i - 1], p);
    for (size_t i = 1; i < HSS.size(); i++)
        HSS[i] = (mulMod(HSS[i - 1], p) + SS[i - 1]) % q;
    vector<int> places(26, 300000);
    Salph[S.size()] = places;
    for (int i = (int)S.size() - 1; i + 1; --i)
        places[S[i] - 'a'] = i, Salph[i] = places;
    HS[0] = vector<unsigned long long>(26, 0);
    for (size_t i = 0; i < S.size(); ++i)
    {
        HS[i + 1] = HS[i];
        for (auto & x : HS[i + 1])
            x = mulMod(x, p);
        HS[i + 1][S[i] - 'a']++;
    }
    vector<int> ans;
    for (int start = 0; start <= S.size() - SS.size(); ++start)
    {
        vector<char> link(26);
        vector<bool> ok(26, true);
        for (size_t i = 0; i < 26; i++)
            link[i] = (char)('a' + i);
        for (int i = 0; i < 26; i++)
        {
            if (Salph[start][i] < start + SS.size() && ok[i] && ok[SS[Salph[start][i] - start] - 'a'])
            {
                swap(link[i], link[SS[Salph[start][i] - start] - 'a']);
                ok[i] = ok[SS[Salph[start][i] - start] - 'a'] = false;
            }
        }
        if (getHash(start, start + SS.size(), P[SS.size()], HS, link) == HSS[SS.size()])
            ans.emplace_back(start + 1);
    }
    cout << ans.size() << '\n';
    for (auto x : ans)
        cout << x << ' ';
}

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <fstream>

#define pb push_back

using namespace std;

vector <vector <string> > G;
vector <string> C;
long long N, M, k;
string a;

string to(string S)
{
    string ans;
    if (S.size() == 7)
    {
        ans += S.substr(0, 3);
        ans += '-';
        ans += S.substr(3, 2);
        ans += '-';
        ans += S.substr(5, 2);
    }
    if (S.size() == 6)
    {
        ans += S.substr(0, 2);
        ans += '-';
        ans += S.substr(2, 2);
        ans += '-';
        ans += S.substr(4, 2);
    }
    if (S.size() == 5)
    {
        ans += S.substr(0, 3);
        ans += '-';
        ans += S.substr(3, 2);
    }
    if (S.size() == 4)
    {
        ans += S.substr(0, 2);
        ans += '-';
        ans += S.substr(2, 2);
    }
    if (S.size() == 3)
    {
        ans += S.substr(0, 3);
    }
    return ans;
}

bool del(string num)
{
    for (int i = 0; i < N; ++i)
    {
        string f = num;
        string t = f.substr(0, C[i].size());
        if (t == C[i])
        {
            f = num.substr(C[i].size(), 11 - C[i].size());
            for (int j = 0; j < G[i].size(); ++j)
            {
                string q = f.substr(0, G[i][j].size());
                string w = f.substr(G[i][j].size(), f.size() - G[i][j].size());
                if (q == G[i][j] && w[0] != '0')
                {
                    return true;
                }
            }
        }
    }
    return false;
}

string deli(string num)
{
    for (int i = 0; i < N; ++i)
    {
        string f = num;
        string t = f.substr(0, C[i].size());
        //cout << t << " " << C[i] << endl;
        if (t == C[i])
        {
            f = num.substr(C[i].size(), 11 - C[i].size());
            //cout << f << endl;
            for (int j = 0; j < G[i].size(); ++j)
            {
                string q = f.substr(0, G[i][j].size());
                string w = f.substr(G[i][j].size(), f.size() - G[i][j].size());
                if (q == G[i][j] && w[0] != '0')
                {
                    string ans;
                    ans += '+';
                    ans += t;
                    ans += '(';
                    ans += q;
                    ans += ')';
                    ans += to(w);
                    return ans;
                }
            }
        }
    }
    //return false;
}

int main()
{
   freopen("numbers.in", "r", stdin);
 freopen("numbers.out", "w", stdout);
    cin >> N;
    G.resize(N, vector<string> ());
    C.resize(N);
    //S.resize(12);
    long long u = 1;
    for (long long i = 0; i < N; ++i)
    {
        cin >> C[i] >> k;
        for (long long j = 0; j < k; ++j)
        {
            cin >> a;
            G[i].pb(a);
        }
    }
    cin >> M;
    for (long long i = 0; i < M; ++i)
    {
        cin >> a;
        //cout << a << "  f" << endl;
        if (del(a))
        {
            cout << deli(a) << endl;
        }
        else
        {
            cout << "Incorrect" << endl;
        }
    }
    return 0;
}

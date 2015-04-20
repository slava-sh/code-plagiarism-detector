#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <fstream>

#define pb push_back

using namespace std;

vector <vector <long long> > G;
vector <long long> C;
long long N, M, a, k;
vector <long long> S;

string tostring(long long a)
{
    string Str;
    while (a != 0)
    {
        Str += '0' + a % 10;
        a /= 10;
    }
    reverse(Str.begin(), Str.end());
    return Str;
}

string tostring1(long long a, long long d)
{
    string Str;
    while (a != 0)
    {
        Str += '0' + a % 10;
        a /= 10;
        --d;
    }
    while (d != 0)
    {
        --d;
        Str += '0';
    }
    reverse(Str.begin(), Str.end());
    return Str;
}


string to(long long num)
{

    string Str;
    if (num / S[6] > 0)
    {
        Str +=tostring1(num / S[4], 3);
        Str += '-';
        Str += tostring1((num % S[4]) / S[2], 2);
        Str += '-';
        Str += tostring1(num % S[2], 2);
        return Str;
    }
    if (num / S[5] > 0)
    {
        Str +=tostring1(num / S[4], 2);
        Str += '-';
        Str += tostring1((num % S[4]) / S[2], 2);
        Str += '-';
        Str += tostring1(num % S[2], 2);
        return Str;
    }
    if (num / S[4] > 0)
    {
        Str += tostring1(num / S[2], 3);
        Str += '-';
        Str += tostring1(num % S[2], 2);
        return Str;
    }
    if (num / S[3] > 0)
    {
        Str += tostring1(num / S[2], 2);
        Str += '-';
        Str += tostring1(num % S[2], 2);
        return Str;
    }
    return tostring(num);
}

bool del(long long num)
{
    if (num < S[10])
    {
        return false;
    }
    for (int i = 0; i < N; ++i)
    {
        long long f = num;
        //cout << f % S[10] << " " << f / S[10] << " " << C[i] << endl;
        if (f / S[10] == C[i]  && f % S[10] >= S[9])
        {
           // cout << f % S[10] << " " << f<< endl;
            f = f % S[10];
            for (int j = 0; j < G[i].size(); ++j)
            {
                if (f / S[7] == G[i][j] && f % S[7] >= S[6])
                {
                    f = f % S[7];
                    return true;
                }
                if(f / S[6] == G[i][j]  && f % S[6] >= S[5])
                {
                    f = f % S[6];
                    return true;
                }
                if(f / S[5] == G[i][j] && f % S[5] >= S[4])
                {
                    f = f % S[5];
                    return true;
                }
            }
        }
        f = num;
        if (f / S[9] == C[i]  && f % S[9] >= S[8])
        {
            f = f % S[9];
            for (int j = 0; j < G[i].size(); ++j)
            {
                if (f / S[6] == G[i][j] && f % S[6] >= S[5])
                {
                    f = f % S[6];
                    return true;
                }
                if(f / S[5] == G[i][j] && f % S[5] >= S[4])
                {
                    f = f % S[5];
                    return true;
                }
                if(f / S[4] == G[i][j] && f % S[4] >= S[3])
                {
                    f = f % S[4];
                    return true;
                }
            }
        }
        f = num;
        if (f / S[8] == C[i]  && f % S[8] >= S[7])
        {
            f = f % S[8];
            for (int j = 0; j < G[i].size(); ++j)
            {
                if (f / S[5] == G[i][j] && f % S[5] >= S[4])
                {
                    f = f % S[5];
                    return true;
                }
                if(f / S[4] == G[i][j] && f % S[4] >= S[3])
                {
                    f = f % S[4];
                    return true;
                }
                if(f / S[3] == G[i][j] && f % S[3] >= S[2])
                {
                    f = f % S[3];
                    return true;
                }
            }
        }
    }
    return false;
}

string deli(long long num)
{
    string Str;
    long long cit, cout, nu;
    for (int i = 0; i < N; ++i)
    {
        long long f = num, cou, cit;
        //cout << f % S[10] << " " << f / S[10] << " " << C[i] << endl;
        if (f / S[10] == C[i] && f % S[10] >= S[9])
        {
           // cout << f % S[10] << " " << f<< endl;
            cou = f / S[10];
            f = f % S[10];
            for (int j = 0; j < G[i].size(); ++j)
            {
                if (f / S[7] == G[i][j] && f % S[7] >= S[6])
                {
                    cit = f / S[7];
                    nu = f % S[7];
                    Str += '+';
                    Str += tostring(cou);
                    Str += '(';
                    Str += tostring(cit);
                    Str += ')';
                    Str += to(nu);
                    return Str;

                }
                if(f / S[6] == G[i][j]  && f % S[6] >= S[5])
                {
                    cit = f / S[6];
                    nu = f % S[6];
                    Str += '+';
                    Str += tostring(cou);
                    Str += '(';
                    Str += tostring(cit);
                    Str += ')';
                    Str += to(nu);
                    return Str;
                }
                if(f / S[5] == G[i][j] && f % S[5] >= S[4])
                {
                    cit = f / S[5];
                    nu = f % S[5];
                    Str += '+';
                    Str += tostring(cou);
                    Str += '(';
                    Str += tostring(cit);
                    Str += ')';
                    Str += to(nu);
                    return Str;

                }
            }
        }
        f = num;
        if (f / S[9] == C[i]   && f % S[9] >= S[8])
        {
            cou = f / S[9];
            f = f % S[9];
            for (int j = 0; j < G[i].size(); ++j)
            {
                if (f / S[6] == G[i][j] && f % S[6] >= S[5])
                {
                    cit = f / S[6];
                    nu = f % S[6];
                    Str += '+';
                    Str += tostring(cou);
                    Str += '(';
                    Str += tostring(cit);
                    Str += ')';
                    Str += to(nu);
                    return Str;

                }
                if(f / S[5] == G[i][j] && f % S[5] >= S[4])
                {
                    cit = f / S[5];
                    nu = f % S[5];
                    Str += '+';
                    Str += tostring(cou);
                    Str += '(';
                    Str += tostring(cit);
                    Str += ')';
                    Str += to(nu);
                    return Str;
                    //return
                }
                if(f / S[4] == G[i][j] && f % S[4] >= S[3])
                {
                    cit = f / S[4];
                    nu = f % S[4];
                    Str += '+';
                    Str += tostring(cou);
                    Str += '(';
                    Str += to(cit);
                    Str += ')';
                    Str += to(nu);
                    return Str;
                    //return true;
                }
            }
        }
        f = num;
        if (f / S[8] == C[i]   && f % S[8] >= S[7])
        {
            cou = f / S[8];
            f = f % S[8];
            for (int j = 0; j < G[i].size(); ++j)
            {
                if (f / S[5] == G[i][j] && f % S[5] >= S[4])
                {
                    cit = f / S[5];
                    nu = f % S[5];
                    Str += '+';
                    Str += tostring(cou);
                    Str += '(';
                    Str += tostring(cit);
                    Str += ')';
                    Str += to(nu);
                    return Str;
                    //return true;
                }
                if(f / S[4] == G[i][j] && f % S[4] >= S[3])
                {
                    cit = f / S[4];
                    nu = f % S[4];
                    Str += '+';
                    Str += tostring(cou);
                    Str += '(';
                    Str += tostring(cit);
                    Str += ')';
                    Str += to(nu);
                    return Str;
                    //return true;
                }
                if(f / S[3] == G[i][j] && f % S[3] >= S[2])
                {
                    cit = f / S[3];
                    nu = f % S[3];
                    Str += '+';
                    Str += tostring(cou);
                    Str += '(';
                    Str += tostring(cit);
                    Str += ')';
                    Str += to(nu);
                    return Str;
                    //S +
                }
            }
        }
    }
    //return false;
}


int main()
{
   // freopen("numbers.in", "r", stdin);
   // freopen("numbers.out", "w", stdout);
    cin >> N;
    G.resize(N, vector<long long> ());
    C.resize(N);
    S.resize(12);
    long long u = 1;
    for (long long i = 0; i < 12; ++i)
    {
        S[i] = u;
        u *= 10;
        //cout << S[i] << endl;
    }
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
            //cout << "F " << a << endl;
            cout << deli(a) << endl;
        }
        else
        {
            cout << "Incorrect" << endl;
        }
    }
    return 0;
}

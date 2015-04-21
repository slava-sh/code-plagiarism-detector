#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>

using namespace std;

long long MOD = 1e9 + 9;
int POW = 179;

int L, N;
string S;
vector<long long> Hash, Pows;
vector<char> Dyn;

long long get_hash(int L, int R)
{
    return (Hash[R] + MOD * MOD - Hash[L] * Pows[R - L]) % MOD;
}

int main()
{
    freopen("input.txt", "r", stdin);

    cin >> L >> S;
    N = S.size();

    if (L >= N)
    {
        cout << 1 << endl << S << endl;
    }
    else
    {
        bool Flag = 0;
        int i;
        for (i = 1; i <= L; ++i)
        {
            Flag = 1;
            for (int j = i; j < N; ++j)
            {
                if (S[j] != S[j - i])
                {
                    Flag = 0;
                    break;
                }
            }
            if (Flag)
            {
                break;
            }
        }
        if (Flag)
        {
            cout << 1 << endl << S.substr(0, i);
            return 0;
        }
////////////////////////////////////////////////////////////////////
        Pows.resize(N + 1);
        Pows[0] = 1;
        long long Curr = 1;
        for (int i = 1; i <= N; ++i)
        {
            Curr = (Curr * POW) % MOD;
            Pows[i] = Curr;
        }

        Hash.resize(N + 1, 0);
        Curr = 0;
        for (int i = 0; i < N; ++i)
        {
            Curr = (Curr * POW + S[i]) % MOD;
            Hash[i + 1] = Curr;
        }
/*
        for (int i = 0; i <= N; ++i)
        {
            printf("%d ", Pows[i]);
        }
        printf("\n");
        for (int i = 0; i <= N; ++i)
        {
            printf("%d ", Hash[i]);
        }
        printf("\n");

        for (int i = 0; i < N; ++i)
        {
            for (int j = i + 1; j <= N; ++j)
            {
                cout << S.substr(i, j - i) << " : " << get_hash(i, j) << endl;
            }
        }
*/
        for (int F = 1; F <= L; ++F)
        {
            int E = F;
            while (E + F <= N and get_hash(E, E + F) == get_hash(0, F))
            {
                E += F;
            }
            for (int Sec = 1; Sec < L and E + Sec <= N; ++Sec)
            {
                //printf("%d %d %d\n", F, E, Sec);
                Dyn.resize(N + 1, 0);
                Dyn[0] = 1;
                for (int i = 0; i <= N; ++i)
                {
                    if (Dyn[i] and get_hash(i, i + F) == get_hash(0, F))
                    {
                        Dyn[i + F] = 1;
                    }
                    if (Dyn[i] and get_hash(i, i + Sec) == get_hash(E, E + Sec))
                    {
                        Dyn[i + Sec] = 1;
                    }
                }
                if (Dyn[N])
                {
                    cout << 2 << endl << S.substr(0, F) << endl << S.substr(E, Sec) << endl;
                    return 0;
                }
            }
        }

        cout << "3\na\nb\nc" << endl;
    }
}


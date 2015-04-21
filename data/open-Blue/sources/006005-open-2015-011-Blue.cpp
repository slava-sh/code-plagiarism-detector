#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>

using namespace std;

long long MOD_1 = 1e9 + 7, MOD_2 = 1e9 + 9;
int POW_1 = 179, POW_2 = 181;

int L, N;
string S;
vector<long long> Hash_1, Hash_2, Pows_1, Pows_2;
vector<char> Dyn;

pair<long long, long long> get_hash(int L, int R)
{
    return make_pair((Hash_1[R] + MOD_1 * MOD_1 - Hash_1[L] * Pows_1[R - L]) % MOD_1, (Hash_2[R] + MOD_2 * MOD_2 - Hash_2[L] * Pows_2[R - L]) % MOD_2);
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
        Pows_1.resize(N + 1);
        Pows_1[0] = 1;
        long long Curr = 1;
        for (int i = 1; i <= N; ++i)
        {
            Curr = (Curr * POW_1) % MOD_1;
            Pows_1[i] = Curr;
        }
        Pows_2.resize(N + 1);
        Pows_2[0] = 1;
        Curr = 1;
        for (int i = 1; i <= N; ++i)
        {
            Curr = (Curr * POW_2) % MOD_2;
            Pows_2[i] = Curr;
        }

        Hash_1.resize(N + 1, 0);
        Curr = 0;
        for (int i = 0; i < N; ++i)
        {
            Curr = (Curr * POW_1 + S[i]) % MOD_1;
            Hash_1[i + 1] = Curr;
        }
        Hash_2.resize(N + 1, 0);
        Curr = 0;
        for (int i = 0; i < N; ++i)
        {
            Curr = (Curr * POW_2 + S[i]) % MOD_2;
            Hash_2[i + 1] = Curr;
        }

        bool Flag = 0;
        int i;
        for (i = 1; i <= L; ++i)
        {
            if (N % i == 0 and get_hash(0, N - i) == get_hash(i, N))
            {
                Flag = 1;
                break;
            }
        }
        if (Flag)
        {
            cout << 1 << endl << S.substr(0, i);
            return 0;
        }

        for (int F = 1; F <= L; ++F)
        {
            int E = F;
            while (E + F <= N and get_hash(E, E + F) == get_hash(0, F))
            {
                E += F;
            }
            for (int Sec = 1; Sec <= L and E + Sec <= N; ++Sec)
            {
                //printf("%d %d %d\n", F, E, Sec);
                Dyn.resize(N + 1, 0);
                Dyn[0] = 1;
                for (int i = 0; i <= N; ++i)
                {
                    if (i + F <= N and Dyn[i] and get_hash(i, i + F) == get_hash(0, F))
                    {
                        Dyn[i + F] = 1;
                    }
                    if (i + Sec <= N and Dyn[i] and get_hash(i, i + Sec) == get_hash(E, E + Sec))
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


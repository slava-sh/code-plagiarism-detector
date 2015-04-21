#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>

using namespace std;

double EPS = 1e-9;
int A, B, N;
vector<vector<pair<int, int> > > Mounts;
vector<pair<double, int> > Order;
vector<pair<int, double> > Pts;

double Coeff(pair<int, int> a, pair<int, int> b)
{
    return double(b.second - a.second) / double(b.first - a.first);
}

double H(pair<int, int> a, pair<int, int> b, int X)
{
    //printf("%d %d, %d %d, %d\n", a.first, a.second, b.first, b.second, X);
    return double(a.second) + double(Coeff(a, b) * double(X - a.first));
}

int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &A, &B, &N);

    Mounts.resize(N);
    //Order.resize(N);

    for (int i = 0; i < N; ++i)
    {
        int K;
        scanf("%d", &K);
        Mounts[i].resize(K + 1);
        for (int j = 0; j <= K; ++j)
        {
            scanf("%d%d", &Mounts[i][j].first, &Mounts[i][j].second);
        }
        //Order[i].first = Coeff(Mounts[i][0], Mounts[i][1]);
        //printf("%f\n", Order[i].first);
        //Order[i].second = i;
    }

    //sort(Order.begin(), Order.end());

    //int F, S;
    //for (int i = 0; i < N - 1; ++i)
    for (int F = 0; F < Mounts.size(); ++F)
    {
        for (int S = F + 1; S < Mounts.size(); ++S)
        {
            bool Flag_1 = 0, Flag_2 = 0;
            //F = Order[i].second; S = Order[i + 1].second;
            int Ind = 0; double h;
            for (int j = 0; j < Mounts[F].size(); ++j)
            {
                while (not(Mounts[S][Ind].first <= Mounts[F][j].first and Mounts[F][j].first <= Mounts[S][Ind + 1].first))
                {
                    ++Ind;
                }    if (Rez == "N")
    {
        Find(S2);
    }
                h = H(Mounts[S][Ind], Mounts[S][Ind + 1], Mounts[F][j].first);
                //printf("%d %d, %d %d: %f\n", S, Ind, F, j, h);
                if (h + EPS < Mounts[F][j].second)
                {
                    //printf("1 1: %d, %f %d\n", Mounts[F][j].first, h, Mounts[F][j].second);
                    Flag_1 = 1;
                }
                else if (h > Mounts[F][j].second + EPS)
                {
                    //printf("1 2: %d, %f %d\n", Mounts[F][j].first, h, Mounts[F][j].second);
                    Flag_2 = 1;
                }
            }

            Ind = 0;
            for (int j = 0; j < Mounts[S].size(); ++j)
            {
                while (not(Mounts[F][Ind].first <= Mounts[S][j].first and Mounts[S][j].first <= Mounts[F][Ind + 1].first))
                {
                    ++Ind;
                }
                h = H(Mounts[F][Ind], Mounts[F][Ind + 1], Mounts[S][j].first);
                //printf("%d %d, %d %d: %f\n", F, Ind, S, j, h);
                if (h > Mounts[S][j].second + EPS)
                {
                    //printf("2 1: %d, %f\n", Mounts[S][j].first, h);
                    Flag_1 = 1;
                }
                else if (h + EPS < Mounts[S][j].second)
                {
                    //printf("2 2: %d, %f\n", Mounts[S][j].first, h);
                    Flag_2 = 1;
                }
            }
            if (Flag_1 and Flag_2)
            {
                printf("No\n%d %d\n", F + 1, S + 1);
                return 0;
            }
        }
    }

    printf("Yes\n");

    return 0;
}


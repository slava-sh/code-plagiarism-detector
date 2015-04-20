#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

struct country
{
    int num;
    int len;
    int All[111];
};

country C[111];
int n;
string Ans;

bool PrintNum(int p, char *now)
{

    if (now[p] == '0')
    {
        return false;
    }
    if (11 - p < 3 || 11 - p > 7)
    {
        return false;
    }

    if (11 - p == 3)
    {
        Ans += now[p] ;
        Ans += now[p + 1];
        Ans += now[p + 2];
    }
    else if (11 - p == 4)
    {
        Ans += now[p];
        Ans += now[p + 1];
        Ans  += '-';
        Ans += now[p + 2];
        Ans += now[p + 3];
    }
    else if (11 - p == 5)
    {
        Ans += now[p];
        Ans  += now[p + 1];
        Ans  += now[p + 2];
        Ans += '-';
        Ans += now[p + 3];
        Ans  += now[p + 4];
    }
    else if (11 - p == 6)
    {
        Ans += now[p];
        Ans += now[p + 1];
        Ans += '-';
        Ans += now[p + 2];
        Ans  += now[p + 3];
        Ans += '-';
        Ans += now[p + 4];
        Ans += now[p + 5];
    }
    else if (11 - p == 7)
    {
        Ans += now[p];
        Ans += now[p + 1];
        Ans += now[p + 2];
        Ans += '-';
        Ans  += now[p + 3];
        Ans += now[p + 4];
        Ans += '-';
        Ans += now[p + 5];
        Ans += now[p + 6];
    }


    return true;
}

string IntToChar(int n)
{
    string r;
    if (n == 0)
    {
        r = '0';
    }
    while (n != 0)
    {
        r += n % 10 + '0';
        n /= 10;
    }
    string a = r;
    for (int i = 0; i < r.length(); i++)
    {
        a[i] = r[r.length() - i- 1];
    }
    return a;
}

void PrintIt(char *now)
{
    if (now[0] == '0')
    {
        printf("Incorrect\n");
        return;
    }
    int S[3];
    int R[3];
    S[0] = now[0] - '0';
    S[1] = S[0] * 10 + now[1] - '0';
    S[2] = S[1] * 10 + now[2] - '0';
    //cout << S[0] << ' ' << S[1] << ' '  <<  S[2] << "\n";
    Ans = '+';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (S[j] == C[i].num)
            {
                Ans += IntToChar(S[j]);
                R[0] = (now[j + 1] - '0') * 100 + (now[j + 2] - '0') * 10 + now[j + 3] - '0';
                R[1] = R[0] * 10  + now[j + 4] - '0';
                R[2] = R[1] * 10 + now[j + 5] - '0';

                //cout << R[0] << ' ' << R[1] << ' '  <<  R[2] << "\n";

                for (int k = 0; k < C[i].len; k++)
                {

                    for (int l = 0; l < 3; l++)
                    {
                        if (C[i].All[k] == R[l])
                        {
                            Ans += '(' + IntToChar(R[l]) + ')';
                            if (!PrintNum((j + 1) + (3 + l), now))
                            {
                                printf("Incorrect\n");
                                return;
                            }
                            else
                            {
                                cout << Ans << "\n";
                                return;
                            }
                        }
                    }

                }
            }
        }
    }
    printf("Incorrect\n");

}

int main()
{
    freopen("numbers.in", "r", stdin);
    freopen("numbers.out", "w", stdout);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> C[i].num >> C[i].len;
        for (int j = 0; j < C[i].len; j++)
        {
            cin >> C[i].All[j];
        }
    }
    int k;
    cin >> k;
    char now[12];

    for (int i = 0; i < k; i++)
    {
        scanf("%s", &now);
        //cout <<" "<<  now << " ";

        PrintIt(now);

    }

    return 0;
}
/*
2
7 3
981
3517
812
351 3
34712
1234
963
8
79818266456
35196328463
78122472557
01234567890
73517960326
35134712239
35112342013
78120203040
*/

/*
2
7 3
981
3517
812
351 3
34712
1234
963
1
73517960326
*/

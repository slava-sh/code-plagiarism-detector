#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>

using namespace std;

int S1 = 20, S2 = 300, S3 = 2000, S4 = 6000;
string Rez;
//string ALL;

void Find(int S)
{
    //cout << S << endl;
    int Curr;
    for (int i = 1; i < S; ++i)
    {
        Curr = (S + i - 1) / i + 1;
        for (int j = 0; j < Curr; ++j)
        {
            printf("D\n");
            //ALL += "D";
            fflush(stdout);
            cin >> Rez;
            if (Rez == "E" or Rez == "Y")
            {
                return;
            }
        }
        printf("R\n");
        //ALL += "R";
        fflush(stdout);
        cin >> Rez;
        if (Rez == "E" or Rez == "Y")
        {
            return;
        }
    }
    for (int i = 1; i < S; ++i)
    {
        Curr = (S + i - 1) / i + 1;
        for (int j = 0; j < Curr; ++j)
        {
            printf("R\n");
            //ALL += "R";
            fflush(stdout);
            cin >> Rez;
            if (Rez == "E" or Rez == "Y")
            {
                return;
            }
        }
        printf("D\n");
        //ALL += "D";
        fflush(stdout);
        cin >> Rez;
        if (Rez == "E" or Rez == "Y")
        {
            return;
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    Rez = "N";
    //ALL = "";
    Find(S1);
    if (Rez == "N")
    {
        Find(S2);
    }
    if (Rez == "N")
    {
        Find(S3);
    }
    if (Rez == "N")
    {
        Find(S4);
    }
    //cout << ALL << endl;

    return 0;
}



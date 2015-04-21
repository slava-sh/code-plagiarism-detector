#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>

using namespace std;

string Rez;
string ALL;

bool Move(char S)
{
    printf("%c", S);
    fflush(stdout);
    cin >> Rez;/*
    if (Rez != "N")
    {
        exit(0);
    }*/
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int Num = 2;
    Rez = "N";
    while (1)
    {
        for (int i = 0; i < Num; ++i)
        {
            Move('R');
        }
        Move('U');
        for (int i = 1; 2 * i <= Num; ++i)
        {
            for (int j = 0; j < Num / i; ++j)
            {
                Move('L');
            }
            Move('U');
        }
        //Num *= 2;

        for (int i = 0; i < Num; ++i)
        {
            Move('U');
        }
        Move('R');
        for (int i = 1; 2 * i <= Num; ++i)
        {
            for (int j = 0; j < Num / i; ++j)
            {
                Move('D');
            }
            Move('R');
        }
        Num *= 2;
    }

    return 0;
}



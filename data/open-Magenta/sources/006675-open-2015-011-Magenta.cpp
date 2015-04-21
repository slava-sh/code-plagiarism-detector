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

void Find(int S)
{
    //cout << S << endl;
    int Curr;
    for (int i = 1; i <= S; ++i)
    {
        Curr = (S / i);
        for (int j = 0; j < Curr; ++j)
        {
            printf("D\n");
            fflush(stdout);
            //ALL += "D";
            cin >> Rez;
            if (Rez != "N")
            {
                return;
            }
        }
        printf("R\n");
        fflush(stdout);
        //ALL += "R";
        cin >> Rez;
        if (Rez != "N")
        {
            return;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //Rez = "N";
    //ALL = "";
    Rez = "N";
    int Curr = 20;
    while (Rez == "N")
    {
        Find(Curr);
        Curr *= 2;
    }

    return 0;
}



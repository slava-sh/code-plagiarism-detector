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
    Find(S1);
    //cout << ALL << endl;
    if (Rez == "N")
    {
        //ALL = "";
        Find(S2);
        //cout << ALL << endl;
    }
    if (Rez == "N")
    {
        //ALL = "";
        Find(S3);
        //cout << ALL << endl;
    }
    if (Rez == "N")
    {
        //ALL = "";
        Find(S4);
        //cout << ALL << endl;
    }

    return 0;
}


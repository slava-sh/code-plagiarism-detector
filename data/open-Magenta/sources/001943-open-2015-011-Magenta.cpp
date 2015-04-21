#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int Curr = 0, Num = 1;
    string Rez = "N";
    while (Rez != "E" and Rez != "Y")
    {
        for (int i = 0; i < Num; ++i)
        {
            if (Curr == 0)
            {
                printf("U\n");
            }
            else if (Curr == 1)
            {
                printf("R\n");
            }
            else if (Curr == 2)
            {
                printf("D\n");
            }
            else
            {
                printf("L\n");
            }
            fflush(stdout);
            cin >> Rez;
            if (Rez == "E" or Rez == "Y")
            {
                return 0;
            }
        }
        Num += Curr % 2;
        Curr = (Curr + 1) % 4;
    }

    return 0;
}



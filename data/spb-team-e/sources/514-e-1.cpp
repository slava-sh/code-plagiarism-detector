#include <fstream>
#define MAX 100000
using namespace std;

struct power
{
    int max, min;
};

int main()
{
    int stolb, kol, buff, how_p = 0, how_v = 0;
    bool who = 0;
    power vas, pet;
    ifstream in ("game.in");
    in>>stolb>>kol>>pet.min>>pet.max>>vas.min>>vas.max;
    for (int i = 0; i < stolb; i++)
    {
        in>>buff;
        if (((buff <= pet.max) and (buff >= pet.min) and (buff <= vas.max) and (buff >= vas.min)) and (who == 0))
        {
            how_p++;
            who = 1;
        }
        else if (((buff <= pet.max) and (buff >= pet.min) and (buff <= vas.max) and (buff >= vas.min)) and (who == 1))
        {
            how_v++;
            who = 0;
        }
        else if ((buff <= pet.max) and (buff >= pet.min) and !((buff <= vas.max) and (buff >= vas.min)))
            how_p++;
        else if ((buff <= vas.max) and (buff >= vas.min) and !((buff <= pet.max) and (buff >= pet.min)))
            how_v++;
    }
    in.close();
    if(kol % 2 == 0)
    {
        kol /= 2;
        who = 0;
    }
    else
    {
        kol /= 2;
        who = 1;
    }
    if (how_p > kol)
        how_p = kol + who;
    if (how_v > kol)
        how_v = kol;
    ofstream out ("game.out");
    if (how_p > how_v)
        out<<"Petya";
    else if (how_p < how_v)
        out<<"Vasya";
    else
        out<<"Draw";
    out.close();
    return 0;
}

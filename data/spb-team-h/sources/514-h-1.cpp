#include <string>
#include <fstream>
#include <algorithm>
#define MAX 1000

using namespace std;

struct who
{
    string fam, imy, otch;
    bool check;
};

who buff[MAX];

void fix(int n)
{
    for (int i = 0; i < n; i++)
        if (buff[i].check != 1)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (buff[i].fam == buff[j].fam)
                {
                    swap(buff[j].imy, buff[j].otch);
                    swap(buff[j].fam, buff[j].imy);
                    buff[j].check = 1;
                    buff[i].check = 1;
                }
                else if (buff[i].fam == buff[j].imy)
                {
                    buff[j].check = 1;
                    buff[i].check = 1;
                }
            }
            if (buff[i].check == 1)
            {
                swap(buff[i].imy, buff[i].otch);
                swap(buff[i].fam, buff[i].imy);
            }
        }
}

int comp(const who a, const who b)
{
    for (unsigned int i = 0; i < min(a.fam.size(), b.fam.size()); i++)
    {
        if (a.fam[i] < b.fam[i])
            return 1;
        else if (a.fam[i] > b.fam[i])
            return 0;
    }
    if (a.fam.size() < b.fam.size())
        return 1;
    else
        return 0;
}

int main()
{
    int n;
    ifstream in ("names.in");
    in>>n;
    for (int i = 0; i < n; i++)
    {
        in>>buff[i].fam>>buff[i].imy>>buff[i].otch;
        buff[i].check = 0;
    }
    in.close();
    fix(n);
    sort(buff, buff+n, comp);
    ofstream out ("names.out");
    for (int i = 0; i < n; i++)
        out<<buff[i].fam<<' '<<buff[i].imy<<' '<<buff[i].otch<<endl;
    out.close();
    return 0;
}

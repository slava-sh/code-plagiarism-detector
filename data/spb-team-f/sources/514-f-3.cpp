#include <fstream>
#include <cmath>

using namespace std;

int nod(int a, int b)
{
    while (a != 0 or b != 0)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    if (a == 0)
        return b;
    else
        return a;
}

int main()
{
    int a, b, noda, i = 0;
    long long nok, start;
    ifstream in ("gcm.in");
    in>>a>>b;
    in.close();
    noda = nod(a, b);
    nok = a * b / noda;
    start = sqrt(a*b);
    ofstream out ("gcm.out");
    if (start * start != a * b)
        start++;
    else
    {
        out<<start<<' '<<start;
        out.close();
        return 0;
    }
    if (start )
    for (; (start - i < a) or (start + i > b); i++)
        if (((start - i) * (start + i) == a * b) and ((start - i) * (start + i) == nok * noda))
            break;
    out<<start + i - 1<<' '<<start - i;
    out.close();
    return 0;
}

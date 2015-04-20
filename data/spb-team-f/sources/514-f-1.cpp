#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

int nod(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
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

#include <fstream>

using namespace std;

int main()
{
    ifstream in("chess.in");
    ofstream out("chess.out");

    int n, sum = 0;
    int a;

    in >> n;

    for(int i = 0; i < n; i++)
    {
        in >> a;
        if (a >= i) sum++;
        else break;
    }

    out << sum;

    return 0;
}

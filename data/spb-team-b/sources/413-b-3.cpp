#include <fstream>

using namespace std;

int main()
{
    ifstream in("chess.in");
    ofstream out("chess.out");

    int n, sum = 0;
    int a, b[1001];

    in >> n;

    for(int i = 0; i < n; i++)
    {
        in >> a;
        if (a >= i) b[sum++] = i+1;
        else break;
    }

    out << sum << endl;
    for(int i = 0; i < sum; i++)
        out << b[i] << " " << b[i] << endl;


    return 0;
}

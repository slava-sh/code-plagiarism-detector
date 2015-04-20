#include <fstream>
#include <functional>

using namespace std;

ifstream in("prizes.in");
ofstream out("prizes.out");

int main()
{
    long long n, m;
    in >> n >> m;

    if (n == 1 || m == 1)
    {
        out << ((max(n, m) + 1) / 4);
    }
    else if (n == 2 || m == 2)
    {
        out << 0;
    }
    else
    {
        out << 1;
    }

    in.close();
    out.close();

    return 0;
}
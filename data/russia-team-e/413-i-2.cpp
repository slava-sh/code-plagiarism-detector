#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("sochi.in");
ofstream out("sochi.out");

long long n, d, a[200000];

int main()
{
    in >> n >> d;
    long long mx1 = 0, mx2 = 0, mx = 0, sum = 0;

    for (long long i = 0; i < n; i++)
    {
        in >> a[i];
        mx = max(mx, a[i]);
        if (a[i] > 2 * d)
        {
            if (a[i] >= 3 * d)
                sum += a[i] - 2 * d;
            else
            {
                if (a[i] > mx1)
                {
                    mx2 = mx1;
                    mx1 = a[i];
                }
                else if (a[i] > mx2)
                    mx2 = a[i];
            }
        }
    }

    if (sum)
    {
        if (!mx1)
            sum += 2 * d;
        else if (!mx2)
            sum += mx1;
        else 
            sum += mx1 + mx2 - 2 * d;
    }
    else if (mx2 > 0)
        sum += mx1 + mx2 - 2 * d;
    out << max(mx, sum);

    in.close();
    out.close();

    return 0;
}
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("che.in");
ofstream out("che.out");

int main()
{
    size_t n;
    unsigned long long r;
    in >> n >> r;

    vector <unsigned long long> monuments(n, 0);
    unsigned long long answer = 0;
    for (size_t i = 0; i != n; ++i)
    {
        in >> monuments[i];

        size_t left = 0, right = i, middle;

        if (monuments[0] + r >= monuments[i])
            continue;

        while (right - left != 1)
        {
            middle = (left + right) / 2;

            if (monuments[middle] + r < monuments[i])
                left = middle;
            else
                right = middle;
        }

        answer += (i - left);
    }

    out << answer;

    in.close();
    out.close();

    return 0;
}
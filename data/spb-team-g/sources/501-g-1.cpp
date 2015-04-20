#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    FILE *fin, *fout;

    fin = fopen ("merlin.in", "rt");
    fout = fopen ("merlin.out", "wt");

    int n;
    vector<int> litres;

    fscanf (fin, "%d", &n);

    for (unsigned int i = 0; i < n; i++)
    {
        int tmp;

        fscanf (fin, "%d", &tmp);
        litres.push_back (tmp);
    }

    sort (litres.begin (), litres.end ());

    long long diff = 0, sum = 0;
    int curr = n;

    for (int i = 0; i < n; i++)
        diff += litres[n - 1] - litres[i];

    while (diff > sum)
    {
        sum += litres[--curr];
        diff -= (litres[curr] - litres[curr - 1]) * curr;
    }

    fprintf (fout, "%d", n - curr);

    return 0;
}

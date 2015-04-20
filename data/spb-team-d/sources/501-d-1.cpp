#include <cstdio>
#include <vector>

using namespace std;

class wind
{
    int l, r, s;

public:
    wind (const int &l, const int &r, const int &s) : l (l), r (r), s (s)
    {}

    int is_inside (const int &a)
    {
        if (a >= l && a <= r)
            return ((a - l) % 2) == 0 ? s : -s;

        return 0;
    }
};

int main ()
{
    FILE *fin, *fout;

    fin = fopen ("dunes.in", "rt");
    fout = fopen ("dunes.out", "wt");

    int n, m;

    fscanf (fin, "%d %d", &n, &m);

    vector<wind> winds;

    for (int i = 0; i < n; i++)
    {
        int l, r, s;

        fscanf (fin, "%d %d %d", &l, &r, &s);

        winds.push_back (wind (l, r, s));
    }

    for (int i = 0; i < m; i++)
    {
        int res = 0, num;

        fscanf (fin, "%d", &num);

        for (unsigned int j = 0; j < winds.size (); j++)
            res += winds[j].is_inside (num);

        fprintf (fout, "%d\n", res);
    }

    return 0;
}

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    FILE *fin, *fout;

    fin = fopen ("game.in", "rt");
    fout = fopen ("game.out", "wt");

    int n, m, pl, pr, vl, vr, unicp = 0, unicv = 0, common = 0;

    fscanf (fin, "%d %d", &n, &m);
    fscanf (fin, "%d %d", &pl, &pr);
    fscanf (fin, "%d %d", &vl, &vr);

    for (int i = 0; i < n; i++)
    {
        int h;

        fscanf (fin, "%d", &h);

        if (h >= pl && h <= pr)
            if (h >= vl && h <= vr)
                common++;
            else
                unicp++;
        else if (h >= vl && h <= vr)
            unicv++;
    }

    int v = m / 2;
    int p = m - v;

    int commonv = min (common / 2, v),
        commonp = min ((common + 1) / 2, p);
    int unicdonev = min (unicv, v - commonv),
        unicdonep = min (unicp, p - commonp);
    int donev = unicdonev + commonv,
        donep = unicdonep + commonp;

    if (donep > donev)
        fprintf (fout, "Petya");
    else if (donep == donev)
        fprintf (fout, "Draw");
    else
        fprintf (fout, "Vasya");

    return 0;
}

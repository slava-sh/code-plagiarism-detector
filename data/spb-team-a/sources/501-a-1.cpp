#include <cstdio>

int main ()
{
    FILE *fin, *fout;

    fin = fopen ("abcd.in", "rt");
    fout = fopen ("abcd.out", "wt");

    int t;

    fscanf (fin, "%d", &t);

    for (int i = 0; i < t; i++)
    {
        int tmpf, tmps;

        fscanf (fin, "%d", &tmpf);

        tmps = tmpf % 100;
        tmpf /= 100;

        fprintf (fout, ((tmpf * tmpf + tmps * tmps) % 7) == 1 ? "YES\n" : "NO\n");
    }

    return 0;
}

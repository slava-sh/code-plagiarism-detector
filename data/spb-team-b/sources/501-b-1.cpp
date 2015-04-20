#include <cstdio>

int main ()
{
    FILE *fin, *fout;

    fin = fopen ("chess.in", "rt");
    fout = fopen ("chess.out", "wt");

    int t, res, i;

    fscanf (fin, "%d", &t);

    for (i = 0; i < t; i++)
    {
        int tmp;

        fscanf (fin, "%d", &tmp);

        if (tmp <= i)
            break;
    }

    fprintf (fout, "%d\n", i);

    for (int j = 1; j <= i; j++)
        fprintf (fout, "%d %d\n", j, j);

    return 0;
}

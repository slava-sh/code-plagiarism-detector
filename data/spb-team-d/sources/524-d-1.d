module main;

import std.stdio;

int main()
{
    stdin = File("dunes.in", "rt");
    stdout = File("dunes.out", "wt");
    int n, m, i, l, r, x, a, j, w = 1;
    readf(" %s %s ", &n, &m);
    auto W = new int[][](n, 3);
    auto U = new int[m];

    for(i = 0; i < n; i++)
        readf(" %s %s %s ", &W[i][0], &W[i][1], &W[i][2]);

    for(i = 0; i < m; i++)
        readf(" %s ", &U[i]);


    auto D = new int[U[U.length - 1]];

    foreach(int[] e; W)
    {
        l = e[0];
        r = e[1];
        x = e[2];

        for(j = l; j <= r; j++)
        {
            if(w % 2 == 0 )
                D[j] -= x;
            else
                D[j] += x;
            w++;
        }
    }
    foreach(int q; U)
        writeln(D[q]);
	return 0;
}


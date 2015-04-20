module main;

import std.stdio;

int main()
{
    stdin = File("dunes.in", "rt");
    stdout = File("dunes.out", "wt");
    int n, m, i, l, r, x, a, j, w;
    readf(" %s %s ", &n, &m);
    //auto W = new int[][](n, 3);
    //auto U = new int[m];
    int[] D;
    D ~= 0;
    D ~= 0;
    for(i = 0; i < n; i++)
    {
        w = 1;

        readf(" %s %s %s ", &l, &r, &x);
        if(D.length < l)
            for(j = D.length; j <= l + 1; j++)
                D ~= 0;

        for(j = l + 1; j <= r + 1; j++)
        {
            if(w % 2 == 0 )
                D[j - 1] -= x;
            else
                D[j - 1] += x;
            w++;
            D ~= 0;
        }
    }
    debug{writeln(D);}
    for(i = 0; i < m; i++)
    {
        readf(" %s ", &a);
        writeln(D[a]);
    }


	return 0;
}


module main;

import std.stdio;

int main()
{
    stdin = File("abcd.in", "rt");
    stdout = File("abcd.out", "wt");
    int i, n, a;
    readf(" %s ", &n);
    for(i = 0; i < n; i++)
    {
        readf(" %s ", &a);
        if(((cast (int) (a / 2)) ^^ 2 + (a % 100) ^^ 2) % 7 == 1)
            writeln("YES");
        else
            writeln("NO");
    }
	return 0;
}

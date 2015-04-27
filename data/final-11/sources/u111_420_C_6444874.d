import std.algorithm;
import std.array;
import std.bigint;
import std.conv;
import std.exception;
import std.math;
import std.numeric;
import std.random;
import std.range;
import std.stdio;
import std.string;
import std.typecons;
import core.bitop;

immutable int NA = -1;

void main ()
{
	int n, p;
	while (readf (" %s %s", &n, &p) > 0)
	{
		auto a = new int [int] [n];
		auto d = new int [n];
		foreach (w; 0..n)
		{
			int u, v;
			readf (" %s %s", &u, &v);
			u--;
			v--;
			a[u][v]++;
			a[v][u]++;
			d[u]++;
			d[v]++;
		}

		auto s = new int [n + 1];
		foreach (u; 0..n)
		{
			s[d[u]]++;
		}
		foreach (i; 0..n)
		{
			s[i + 1] += s[i];
		}
		debug {writeln (d);}
		debug {writeln (s);}

		long res = 0L;
		foreach (u; 0..n)
		{
			int more = p - d[u];
			res += n - 1;
			int less = 0;
			if (more > 0)
			{
				less = s[more - 1];
				if (d[u] <= more - 1)
				{
					less--;
				}
			}
			res -= less;
			debug {writefln ("u = %s, more = %s, less = %s",
			                 u, more, less);}
			foreach (v, x; a[u])
			{
				if (d[v] >= more)
				{
					if (d[v] - x < more)
					{
						res--;
						debug {writefln ("(%s, %s): " ~
						    "minus %s edges",
						    u, v, x);}
					}
				}
			}
		}
		res /= 2;
		writeln (res);
	}
}

import std.algorithm;
import std.array;
import std.container;
import std.conv;
import std.exception;
import std.functional;
import std.math;
import std.numeric;
import std.range;
import std.stdio;
import std.string;
import std.typecons;
import core.bitop;

immutable int MOD  = 1_000_000_007;
immutable int BASE =            10;

int powmod (int a, int p, int m)
{
	int res = 1;
	while (p)
	{
		if (p & 1)
		{
			res = (cast (long) res * a) % m;
		}
		a = (cast (long) a * a) % m;
		p >>= 1;
	}
	return res;
}

int inv (int a)
{
	return powmod (a, MOD - 2, MOD);
}

void main ()
{
	int n, k;
	while (readf (" %s %s ", &n, &k) > 0)
	{
		auto a = readln ().strip ().map !(q{a - '0'}) ().array ();
		debug {writeln (a);}

		long [] p = [1];
		foreach (i; 0..n)
		{
			p ~= (p[$ - 1] * BASE) % MOD;
		}
		debug {writeln (p);}

		long [] c = [1];
		foreach (i; k..n - 1)
		{
			c ~= (((c[$ - 1] * i) % MOD) * inv (i - k + 1)) % MOD;
		}
		reverse (c);
		debug {writeln (c);}

		long s = 0;
		foreach (i; 0..c.length)
		{
			s = (s + c[i] * p[i]) % MOD;
		}
		debug {writeln (s);}

		long res = 0;
		foreach (i; 0..n)
		{
			res = (res + s * a[i]) % MOD;
			int j = n - i - 1;
			if (0 < j && j < c.length)
			{
				s = (s - c[j] * p[j]) % MOD;
				s = (s + c[j] * p[j - 1]) % MOD;
				c[j - 1] = (c[j - 1] + c[j]) % MOD;
				j--;
				s = (s + MOD) % MOD;
				debug {writeln (c, ' ', s);}
			}
		}
		writeln (res);
	}
}

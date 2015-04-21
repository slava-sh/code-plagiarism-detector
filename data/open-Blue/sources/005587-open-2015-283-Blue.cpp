#include <bits/stdc++.h>
#define TASK "a"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef std::pair < int , int > pair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = std::numeric_limits < double > ::infinity();
const ld LDINF = std::numeric_limits < ld > ::infinity();
const double EPS = 1e-9;

const int N = 20179;
const ull P = 1000000007ll;

int l, n;
std::string s;

void theEnd()
{
#ifdef LOCAL
	std::cerr << "TIME = " << clock()*1./CLOCKS_PER_SEC << "\n";
#endif
	exit(0);
}

void check1()
{
	for (int i = 1; i <= l; ++i)
	{
		bool ok = true;
		for (int j = 0; j + i < n; ++j)
			if (s[j] != s[j + i])
			{
				ok = false;
				break;
			}
		if (ok)
		{
			std::cout << 1 << "\n" << s.substr(0, i) << "\n";
			theEnd();
		}
	}
}

ull ppow[N];
ull hash[N];

inline ull getHash(int l, int r)
{
	return hash[r + 1] - hash[l] * ppow[r - l + 1];
}

void check2()
{
	ppow[0] = 1;
	for (int i = 1; i < N; ++i)
		ppow[i] = ppow[i - 1] * P;
	hash[0] = 0;
	for (int i = 0; i < N - 1; ++i)
		hash[i + 1] = hash[i] * P + s[i];

	for (int len1 = 1; len1 <= l; ++len1)
	{
		//std::cerr << "len1 = " << len1 << "\n";
		ull s1 = getHash(0, len1 - 1);
		int cl = 0, cr = n - 1;
		while (cr - cl + 1 >= len1 && getHash(cl, cl + len1 - 1) == s1)
			cl += len1;
		while (cr - cl + 1 >= len1 && getHash(cr - len1 + 1, cr) == s1)
			cr -= len1;
		//std::cerr << " cl=" << cl << " " << "cr=" << cr << "\n";

		if (cr - cl + 1 <= l)
		{
			std::cout << "2\n";
			std::cout << s.substr(0, len1) << "\n";
			std::cout << s.substr(cl, cr - cl + 1) << "\n";
			theEnd();
		}

		for (int len2 = 1; len2 <= l; ++len2)
		{
			if (cr - cl + 1 < len2 * 2)
				break;
			ull s2 = getHash(cl, cl + len2 - 1);
			if (getHash(cr - len2 + 1, cr) != s2)
				break;
			//std::cerr << " len2 = " << len2 << "\n";
			bool curr1 = false;
			int ccl = cl, ccr = cr;
			while (ccl <= ccr)
			{
				//std::cerr << "  ccl=" << ccl << " ccr=" << ccr << "\n";
				ull ws;
				int wlen;
				if (curr1)
				{
					ws = s1;
					wlen = len1;
				} else {
					ws = s2;
					wlen = len2;
				}
				curr1 ^= true;

				bool ok = false;
				while (ccr-ccl+1 >= wlen && getHash(ccl, ccl+wlen-1) == ws)
				{
					ok = true;
					ccl += wlen;
				}
				if (!ok)
					break;
				while (ccr-ccl+1 >= wlen && getHash(ccr-wlen+1, ccr) == ws)
				{
					ok = true;
					ccr -= wlen;
				}
				if (!ok)
					break;
			}
			if (ccl > ccr)
			{
				std::cout << "2\n";
				std::cout << s.substr(0, len1) << "\n";
				std::cout << s.substr(cl, len2) << "\n";
				theEnd();
			}
		}
	}
}

void check3()
{
	std::cout << "3\na\nb\nc\n";
	theEnd();
}

int main()
{
	/*freopen("input.txt", "w", stdout);
	std::cout << "10000\n";
	for (int i = 0; i < 19999; ++i)
		std::cout << "a";
	std::cout << "b" << "\n";
	return 0;
*/
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
#ifdef LOCAL
	std::cerr << "START\n";
#endif
	std::cin >> l >> s;
	n = s.length();
	l = std::min(l, n);
	check1();
	check2();
	check3();
	return 0;
}

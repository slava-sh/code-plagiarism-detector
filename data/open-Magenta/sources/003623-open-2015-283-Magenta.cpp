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

const int N = 6179;

void myMain()
{
	int cx = 1, cy = 1;
	for (int i = 2; i < N; ++i)
	{
		for (int x = 1; x <= i; ++x)
		{
			if (i % x != 0)
				continue;
			int y = i / x;
			while (cx > x)
			{
				--cx;
				std::cout << "L\n";
				std::cout.flush();
				std::string s;
				std::cin >> s;
				if (s != "N")
					return;
			}
			while (cx < x)
			{
				++cx;
				std::cout << "R\n";
				std::cout.flush();
				std::string s;
				std::cin >> s;
				if (s != "N")
					return;
			}
			while (cy < y)
			{
				++cy;
				std::cout << "U\n";
				std::cout.flush();
				std::string s;
				std::cin >> s;
				if (s != "N")
					return;
			}
			while (cy > y)
			{
				--cy;
				std::cout << "D\n";
				std::cout.flush();
				std::string s;
				std::cin >> s;
				if (s != "N")
					return;
			}
		}
	}
}

void generateTest()
{
}

int main()
{
#ifdef GEN
	freopen("input.txt", "w", stdout);
	generateTest();
	return 0;
#endif

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
#ifdef LOCAL
	std::cerr << "START\n";
#endif

	myMain();

#ifdef LOCAL
	std::cerr << "TIME = " << clock() * 1. / CLOCKS_PER_SEC << "\n";;
#endif
	return 0;
}

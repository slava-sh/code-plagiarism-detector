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

const int N = 101;
bool w[N][N];

void go(const std::string & s)
{
	for (char c : s)
	{
		std::cout << c << "\n";
		static std::string s1;
		std::cin >> s1;
		if (s1 != "N")
		{
		#ifdef LOCAL
			std::cerr << "TIME = " << clock() * 1. / CLOCKS_PER_SEC << "\n";;
		#endif
			exit(0);
		}
	}
}

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
			if (i % 2 == 0)
				std::swap(x, y);
			if (w[x][y])
				continue;
			while (cx < x)
			{
				++cx;
				w[cx][cy] = true;
				std::cout << "R\n";
				std::cout.flush();
				std::string s;
				std::cin >> s;
			}
			while (cx > x)
			{
				--cx;
				w[cx][cy] = true;
				std::cout << "L\n";
				std::cout.flush();
				std::string s;
				std::cin >> s;
			}
			while (cy < y)
			{
				++cy;
				w[cx][cy] = true;
				std::cout << "U\n";
				std::cout.flush();
				std::string s;
				std::cin >> s;
			}
			while (cy > y)
			{
				--cy;
				w[cx][cy] = true;
				std::cout << "D\n";
				std::cout.flush();
				std::string s;
				std::cin >> s;
			}
		}
	}
}

void generateTest()
{
	for (int i = 0; i < 1000000; ++i) std::cout << "N ";
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
	freopen("output.txt", "w", stdout);
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

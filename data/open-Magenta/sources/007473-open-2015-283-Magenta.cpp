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

const int N = 2000;
bool w[N*2][N*2];

void go(const std::string & s)
{
	for (char c : s)
	{
		std::cout << c << "\n";
		std::cout.flush();
/*
		static bool w[N*2][N*2];
		static int x=0, y=0;
		switch (c)
		{
		case 'U': ++y; break;
		case 'D': --y; break;
		case 'R': ++x; break;
		case 'L': --x; break;
		};
		w[x][y] = true;
		for (int i = 0; i <= N; ++i)
		{
			for (int j = 0; j <= N; ++j)
				if (x == i && y == j)
					std::cerr << "@";
				else if (w[i][j])
					std::cerr << "o";
				else
					std::cerr << ".";
			std::cerr << "\n";
		}
		std::cerr << "\n";
*/
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
	/*int cm = 1;
	std::cout << "1 1\n";
	while (cm < N)
	{
		std::set < int > uu;
		for (int i = 1; i <= cm; ++i)
		{
			uu.insert(cm/i*i + i);
			uu.insert(cm/i*i + i + cm/i - 1);
		}
		std::cout << cm + 1 << " ";
		std::cout << (cm = *(--uu.end())) << "\n";
	}
	return;*/

	int cx = 1, cy = 1;
	int cl = 2;
	while (cl < N)
	{
		int cr = cl * 2 - 2;
		//std::cerr << "!" << " " << cl << " " << cr << "\n";
		if (cr >= N)
			cr = N - 1;
		if (cx == 1)
		{
			for (int x = 1; x <= cr; ++x)
			{
				int yl = (cl + x - 1) / x;
				int yr = cr / x;
				//std::cerr << " " << "(" << cl << "," << cr << ")";
				//std::cerr << " " << x << " " << yl << "-" << yr << "\n";
				if (yl > yr)
				{
					++cx;
					go("R");
					continue;
				}
				while (cy < yr)
				{
					go("U");
					++cy;
				}
				while (cy > yl)
				{
					go("D");
					--cy;
				}
				++cx;
				go("R");
			}
			while (cy > 1)
			{
				--cy;
				go("D");
			}
		}
		else
		{
			for (int y = 1; y <= cr; ++y)
			{
				int xl = (cl + y - 1) / y;
				int xr = cr / y;
				//std::cerr << " " << "(" << cl << "," << cr << ")";
				//std::cerr << " " << y << " " << xl << "-" << xr << "\n";
				if (xr < xl)
				{
					++cy;
					go("U");
					continue;
				}
				while (cx < xr)
				{
					go("R");
					++cx;
				}
				while (cx > xl)
				{
					go("L");
					--cx;
				}
				++cy;
				go("U");
			}
			while (cx > 1)
			{
				--cx;
				go("L");
			}
		}
		cl *= 2;
		--cl;
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

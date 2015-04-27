#include <iostream>
#include <vector>

int n, h1, h2;

int v[100];
char c[100];
long long a[100];
long long b[100];

const int H = 100;

int func(char z1)
{
	int r = 0;
	for (int k = 2 ; k <= n + 1 ; ++k)
	{
		char z = z1;
		std::vector<bool> ok(n);
		int rr = 0;
		long long dx = 100000;
		long long dy = (k - 2) * H 
			+ (z == 'F' ? h1 : H - h1) 
			+ (((k % 2 != 0 && z == 'F') || (k % 2 == 0 && z == 'T')) ? H - h2 : h2);
		for (int i = 0 ; i < k - 1 ; ++i)
		{
			long long y = (z1 == 'F' ? h1 : H - h1) + i * H;
			int vv = 0;
			for (int m = 0 ; m < n ; ++m)
				if (c[m] == z && !ok[m])
				{
					if (dx * y >= a[m] * dy && dx * y <= b[m] * dy)
					{
						vv = v[m];
						ok[m] = true;
						break;
					}
				}
			if (vv)
			{
				rr += vv;
			}
			else
			{
				rr = 0;
				break;
			}
			z = z == 'F' ? 'T' : 'F';
		}
		if (r < rr)
			r = rr;
	}

	return r;
}

int main()
{
	std::cin >> h1 >> h2 >> n;
	for (int i = 0 ; i < n ; ++i)
		std::cin >> v[i] >> c[i] >> a[i] >> b[i];

	int r = std::max(func('F'), func('T'));

	std::cout << r;

	return 0;
}


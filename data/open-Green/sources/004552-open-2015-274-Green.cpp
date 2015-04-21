#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	if (k == 3)
		cout << 2 << endl;
	else if (k == 1)
		cout << (n + 1) / 2 << endl;
	else
	{
		int answer = 1000 * 1000 * 1000;
		for (int i = 1; i <= n; ++i)
		{
			if (n % i == 0)
			{
				int temp = n / i;
				for (int j = 1; j <= temp; ++j)
				{
					if (temp % j == 0)
					{
						answer = min(answer, ((i + 1) / 2) * ((j + 1) / 2) * (temp / j));
					}
				}
			}
		}
		cout << answer << endl;
	}
}
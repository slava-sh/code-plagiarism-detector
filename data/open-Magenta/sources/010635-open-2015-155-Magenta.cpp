#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <unordered_map>
#include <ctime>

using namespace std;

int main()
{
	srand(1293);
	int t = 0;
	int cnt = 1;
	int c = 0;
	char ch[4] = {'U', 'R', 'D', 'L'};
	int cnt1 = 0;
	int s = 1;
	char ans;
	while (true)
	{
			for (int a = 1; a < s; ++a)
			{
				cout << 'L' << endl;
				cout.flush();
				cin >> ans;
				if (ans == 'Y' || ans == 'E')
					return 0;
				int x1 = a + 1;
				int x2 = s / a;
				int d = x2;
				for (int i = 0; i < d; ++i)
				{
					cout << 'U' << endl;
					cout.flush();
					cin >> ans;
					if (ans == 'Y' || ans == 'E')
						return 0;
				}
				for (int i = 0; i < d; ++i)
				{
					cout << 'D' << endl;
					cout.flush();
					cin >> ans;
					if (ans == 'Y' || ans == 'E')
						return 0;
				}
				for (int i = 0; i < d; ++i)
				{
					cout << 'D' << endl;
					cout.flush();
					cin >> ans;
					if (ans == 'Y' || ans == 'E')
						return 0;
				}
				for (int i = 0; i < d; ++i)
				{
					cout << 'U' << endl;
					cout.flush();
					cin >> ans;
					if (ans == 'Y' || ans == 'E')
						return 0;
				}
			}
			for (int a = 1; a < s; ++a)
			{
				cout << 'R' << endl;
				cout.flush();
				cin >> ans;
				if (ans == 'Y' || ans == 'E')
					return 0;
			}

			for (int a = 1; a < s; ++a)
			{
				cout << 'R' << endl;
				cout.flush();
				cin >> ans;
				if (ans == 'Y' || ans == 'E')
					return 0;
				int x1 = a + 1;
				int x2 = s / a;
				int d = x2;
				for (int i = 0; i < d; ++i)
				{
					cout << 'U' << endl;
					cout.flush();
					cin >> ans;
					if (ans == 'Y' || ans == 'E')
						return 0;
				}
				for (int i = 0; i < d; ++i)
				{
					cout << 'D' << endl;
					cout.flush();
					cin >> ans;
					if (ans == 'Y' || ans == 'E')
						return 0;
				}
				for (int i = 0; i < d; ++i)
				{
					cout << 'D' << endl;
					cout.flush();
					cin >> ans;
					if (ans == 'Y' || ans == 'E')
						return 0;
				}
				for (int i = 0; i < d; ++i)
				{
					cout << 'U' << endl;
					cout.flush();
					cin >> ans;
					if (ans == 'Y' || ans == 'E')
						return 0;
				}
			}
			for (int a = 1; a < s; ++a)
			{
				cout << 'L' << endl;
				cout.flush();
				cin >> ans;
				if (ans == 'Y' || ans == 'E')
					return 0;
			}
		s *= 2;
	}
}
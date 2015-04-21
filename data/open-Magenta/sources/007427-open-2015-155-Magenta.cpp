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
	while (true)
	{
		cout << ch[t] << endl;
		cout.flush();
		++c;
		++cnt1;
		if (c == cnt)
		{
			t = (t + 1) % 4;
			c = 0;
			if (t == 2)
				++cnt;
		}
		char ans;
		cin >> ans;
		if (ans == 'Y' || ans == 'E')
			return 0;
		if (cnt1 > 1201)
		{
			cnt = 1;
			t = 0;
			c = 0;
		}	
	}
}
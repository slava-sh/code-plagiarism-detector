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
	int t = 0;
	char ch[4] = {'U', 'R', 'D', 'L'};
	while (true)
	{
		cout << ch[t] << endl;
		cout.flush();
		t = (t + 1) % 4;
		char ans;
		cin >> ans;
		if (ans == 'Y' || ans == 'E')
			return 0;
	}
}
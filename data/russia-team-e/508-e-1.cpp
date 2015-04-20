#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#pragma comment(linker, "/STACK:256000000");
using namespace std;

int main()
{
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	int n, i,j , h, z;
	cin >> n;
	bool b[1000][1000];
	bool a[1000];
	for (i = 0; i< 1000; i++)
		for(j = 0; j < 1000; j ++)
			b[i][j] = false;
	for (i = 0; i < 1000; i++)
		a[i] = false;
	for(int i = 0; i < n; i++)
	{
		int c, k;
		cin >> c >> k;
		a[c] = true;
		for (j = 0; j < k; j++)
		{
			int t;
			cin >> t;
			b[c][t] = true;
		}
	}
	int m;
	cin >> m;
	for(i = 0; i < m; i++)
	{
		string num;
		cin >> num;
		bool flag = false;
		for(j = 1; j <= 3 && !flag; j++)
		{
			int ctr = atoi(num.substr(0, j).c_str());
			if (a[ctr] && num[0] != '0')
				for(z = 3; z <= 5 && !flag; z++)
				{
					int city = atoi(num.substr(j, z).c_str());
					if (b[ctr][city] && num[j] != '0')
					{
						if (num[j + z] != '0')
						{
							flag = true;
							int cnt = 11 - z - j;
							cout << "+" << num.substr(0, j) << "(" << num.substr(j, z) << ")";
							if (cnt == 3)
								cout << num.substr(j + z, 3)<< endl;
							else if(cnt == 4)
								cout << num.substr(j + z, 2) << "-" << num.substr(j + z + 2, 2) << endl;
							else if (cnt == 5)
								cout << num.substr(j + z, 3) << "-" << num.substr(j + z + 3, 2) << endl;
							else if (cnt == 6)
								cout << num.substr(j + z, 2) << "-" << num.substr(j + z + 2, 2) << "-" << num.substr(j + z + 4, 2) << endl;
							else if(cnt == 7)
								cout << num.substr(j + z, 3) << "-" << num.substr(j + z + 3, 2) << "-" << num.substr(j + z + 5, 2) << endl;
						}
					}
				}
		}
		if (flag)
		{
			
		}
		else
			cout << "Incorrect" << endl;
	}
	return 0;
}
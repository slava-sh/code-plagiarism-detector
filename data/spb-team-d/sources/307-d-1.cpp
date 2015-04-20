#include <fstream>

using namespace std;

int arr[1000][3];

int main()
{
	ifstream fin("dunes.in");
	ofstream fout("dunes.out");
	int n, m, i, x, j, ans;
	fin >> n >> m;
	for (i = 0; i < n; i++)
		fin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	for (i = 0; i < m; i++)
	{
		ans = 0;
		fin >> x;
		for (j = 0; j < n; j++)
			if (arr[j][0] <= x && x <= arr[j][1])
			{
				if ((x - arr[j][0]) % 2)
					ans -= arr[j][2];
				else
					ans += arr[j][2];
			}
		fout << ans << '\n';
	}
	return 0;
}
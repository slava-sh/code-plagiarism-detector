#include<fstream>

using namespace std;

ifstream fin;
ofstream fout;

const int nmax = 330000;

int d[nmax];
int ans, n, rrr;


void readdata()
{
	fin >> n >> rrr;
	for (int i = 0; i < n; i++)
		fin >> d[i];
}


void solve()
{
	ans = 0;
	for (int i = 0; i < n; i++)
	{
		int l = i;
		int r = n;
		while (r - l > 1)
		{
			int m = (l + r) / 2;
			if (d[m] - d[i] > rrr)
				r = m;
			else
				l = m;
		}
		ans += n - r;
	}
	fout << ans << endl;
}


int main()
{
	fin.open("che.in");
	fout.open("che.out");
	readdata();
	solve();
	return 0;
}
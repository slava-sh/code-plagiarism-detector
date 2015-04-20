#include <fstream>

using namespace std;

int main()
{
	ifstream fin("chess.in");
	ofstream fout("chess.out");
	int n, a, i, m;
	fin >> m;
	for (n = 1; n <= m; n++)
	{
		fin >> a;
		if (a < n)
			break;
	}
	fout << n << '\n';
	for (i = 1; i < n; i++)
		fout << i << ' ' << i << '\n';
	return 0;
}
#include <fstream>

using namespace std;

bool Check(int a, int b)
{
	int c = a * a + b * b;
	return c % 7 == 1;
}

int main()
{
	ifstream fin("abcd.in");
	ofstream fout("abcd.out");
	int t, x, i, y;
	fin >> t;
	for (i = 0; i < t; i++)
	{
		fin >> x;
		y = x - (x / 100) * 100;
		x /= 100;
		if (Check(x, y))
			fout << "YES\n";
		else
			fout << "NO\n";
	}
	return 0;
}
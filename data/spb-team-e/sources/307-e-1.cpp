#include <fstream>

int Min(int a, int b)
{
	return a < b ? a : b;
}

using namespace std;

int main()
{
	ifstream fin("game.in");
	ofstream fout("game.out");
	int n, m, i, l1, r1, l2, r2, x;
	int P, V, B;
	P = V = B = 0;
	fin >> n >> m >> l1 >> r1 >> l2 >> r2;
	for (i = 0; i < n; i++)
	{
		fin >> x;
		if (x >= l1 && x <= r1 && x >= l2 && x <= r2)
			B++;
		else
		{
			if (x >= l1 && x <= r1)
				P++;
			else
				V++;
		}
	}
	P = Min(P + (B + 1) / 2, (m + 1) / 2);
	V = Min(V + B / 2, m / 2);
	if (P > V)
		fout << "Petya";
	if (V > P)
		fout << "Vasya";
	if (P == V)
		fout << "Draw";
	return 0;
}
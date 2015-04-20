#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{

	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);

	vector<int> stolbs;
	int n, m;
	cin >> n >> m;
	int l1, r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;
	stolbs.resize(n);
	int l3, r3;
	l3 = max(l1, l2);
	r3 = min(r1, r2);

	int x = 0, y = 0, z = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> stolbs[i];
		if (stolbs[i] >= l3 && stolbs[i] <= r3)
			x++;
		else if (stolbs[i] >= l2 && stolbs[i] <= r2)
			z++;
		else if (stolbs[i] >= l1 && stolbs[i] <= r1)
			y++;
	}

	y += x / 2 + x % 2;
	z += x / 2;


	if (min(z, y) * 2 >= m)
	{
		if (m & 1)
			cout << "Petya";
		else
			cout << "Draw";
	}
	else
	{
		if (z > y)
			cout << "Vasya";
		else if (z == y && !(m & 1))
			cout << "Draw";
		else
			cout << "Petya";
	}

	return 0;
}
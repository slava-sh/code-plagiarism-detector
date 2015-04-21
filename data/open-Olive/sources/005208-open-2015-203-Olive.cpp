#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;

//int func(int i, int q)
//{
//	int first_perm = abs(i + 1 - a[i]) + abs(q + 1 - a[q]);
//	int second_perm = abs(i + 1 - a[q]) + abs(q + 1 - a[i]);
//	return second_perm - first_perm;
//}

int main()
{
	int N;
	cin >> N;
	a.resize(N);
	for (int i = 0; i < N; i++)
		cin >> a[i];
	//int mn = 0;
	int rem1 = -1, rem2 = -1;
	/*for (int i = 0; i < N - 1; i++)
	{
		for (int q = i + 1; q < N; q++)
		{
			int ans = func(i, q);
			if (ans < mn)
			{
				mn = ans;
				rem1 = i + 1;
				rem2 = q + 1;
			}
		}
	}
	cout << rem1 << ' ' << rem2 << endl;*/
	int min_p = 0;
	vector<int> b = a;
	for (int it1 = 0; it1 < N; it1++)
	{
		for (int it2 = 0; it2 < N - 1; it2++)
		{
			if (b[it2] > b[it2 + 1])
			{
				swap(b[it2], b[it2 + 1]);
				min_p++;
			}
		}
	}
	rem1 = -1;
	rem2 = -1;
	for (int i = 0; i < N - 1; i++)
	{
		for (int q = i + 1; q < N; q++)
		{
			vector<int> b = a;
			swap(b[i], b[q]);
			int n_ans = 0;
			for (int it1 = 0; it1 < N; it1++)
			{
				for (int it2 = 0; it2 < N - 1; it2++)
				{
					if (b[it2] > b[it2 + 1])
					{
						swap(b[it2], b[it2 + 1]);
						n_ans++;
					}
				}
			}
			if (n_ans < min_p)
			{
				min_p = n_ans;
				rem1 = i + 1;
				rem2 = q + 1;
			}
		}
	}
	cout << rem1 << ' ' << rem2 << endl;
	return 0;
}
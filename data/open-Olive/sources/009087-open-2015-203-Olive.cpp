#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long srt(vector<int>& a)
{
	if (a.size() == 1)
	{
		return 0;
	}
	else
	{
		long long ans = 0;
		int m = a.size() / 2;
		vector<int> first, second;
		for (int i = 0; i < a.size(); i++)
		{
			if (i < m)
				first.push_back(a[i]);
			else
				second.push_back(a[i]);
		}
		ans += srt(first);
		ans += srt(second);
		int it1 = 0, it2 = 0;
		vector<int> b;
		for (int i = 0; i < a.size(); i++)
		{
			if (it1 == first.size())
			{
				b.push_back(second[it2]);
				it2++;
				continue;
			}
			if (it2 == second.size())
			{
				b.push_back(first[it1]);
				it1++;
				continue;
			}
			if (first[it1] < second[it2])
			{
				b.push_back(first[it1]);
				it1++;
			}
			else
			{
				b.push_back(second[it2]);
				it2++;
				ans += (first.size() - it1);
			}
		}
		a = b;
		return ans;
	}
}


int main()
{
	int N;
	cin >> N;
	vector<int> a;
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
			if (a[i] > a[q])
			{
				vector<int> b = a;
				swap(b[i], b[q]);
				int n_ans = 0;
				n_ans = srt(b);
				if (n_ans < min_p)
				{
					min_p = n_ans;
					rem1 = i + 1;
					rem2 = q + 1;
				}
			}
		}
	}
	cout << rem1 << ' ' << rem2 << endl;
	return 0;
}
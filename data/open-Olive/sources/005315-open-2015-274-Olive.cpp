#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(NULL);

	// ifstream cin("");
	// ofstream cout("");

	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; ++i)
		cin >> A[i];

	int answer = 0, ii = -1, jj = -1;

	for (int k = 0; k < n; ++k)
		for (int l = k + 1; l < n; ++l)
			answer += (int)(A[k] > A[l]);

	int init = answer;

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int current = init;

			if (A[i] > A[j])
				current -= 1;
			else
				current += 1;

			for (int k = i + 1; k < j; ++k)
			{
				if (A[i] > A[k])
					current -= 1;
				else
					current += 1;

				if (A[k] > A[j])
					current -= 1;
				else
					current += 1;
			}

			if (current < answer)
			{
				answer = current;
				ii = i + 1;
				jj = j + 1;
			}
		}
	}

	cout << ii << " " << jj << endl;
}
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

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			swap(A[i], A[j]);
			int current = 0;
			for (int k = 0; k < n; ++k)
				for (int l = k + 1; l < n; ++l)
					current += (int)(A[k] > A[l]);
			if (current < answer)
			{
				answer = current;
				ii = i + 1;
				jj = j + 1;
			}
			swap(A[i], A[j]);
		}
	}

	cout << ii << " " << jj << endl;
}
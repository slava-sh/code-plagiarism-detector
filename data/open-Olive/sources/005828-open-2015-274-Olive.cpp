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






	vector<vector<int> > P(n, vector<int>(n, 0)); //, S(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j == 0)
				P[i][j] = (int)(A[j] < A[i]);
			else
				P[i][j] = P[i][j - 1] + (int)(A[j] < A[i]);
		}
	}

	// for (int i = n - 1; i > -1; --i)
	// {
	// 	for (int j = n - 1; j > -1; --j)
	// 	{
	// 		if (j == n - 1)
	// 			S[i][j] = (int)(A[j] < A[i]);
	// 		else
	// 			S[i][j] = S[i][j + 1] + (int)(A[j] < A[i]);
	// 	}
	// }




	int init = answer;

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int current = init;

			int less_A = P[i][j - 1] - P[i][i];
			int less_B = P[j][j - 1] - P[j][i];

			current -= less_A;
			current += (j - i - 1) - less_A;

			current += less_B;
			current -= (j - i - 1) - less_B;

			if (A[i] > A[j])
				current -= 1;
			else
				current += 1;

			// for (int k = i + 1; k < j; ++k)
			// {
			// 	if (A[i] > A[k])
			// 		current -= 1;
			// 	else
			// 		current += 1;

			// 	if (A[k] > A[j])
			// 		current -= 1;
			// 	else
			// 		current += 1;
			// }

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
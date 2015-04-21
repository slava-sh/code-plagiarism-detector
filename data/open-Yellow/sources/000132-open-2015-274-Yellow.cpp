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
	int current = 1;
	for (int i = 1; i < n; ++i)
		if (A[i] != A[i - 1])
			current += 1;
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int index, value, amount = 0;
		cin >> index >> value;
		if (index - 1 != 0 && A[index - 1] != A[index - 2] && value == A[index - 2])
			amount -= 1;
		if (index - 1 != n - 1 && A[index - 1] != A[index] && value == A[index])
			amount -= 1;

		if (index - 1 != 0 && A[index - 1] == A[index - 2] && value != A[index - 2])
			amount += 1;
		if (index - 1 != n - 1 && A[index - 1] == A[index] && value != A[index])
			amount += 1;

		current += amount;

		A[index - 1] = value;
		cout << current << endl;
	}
}
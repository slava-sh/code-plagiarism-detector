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
#define int long long int

using namespace std;

int f(int n, int k)
{
	if (k == 1)
		return (n + 1) / 2;
	int current = 1000 * 1000 * 1000;
	for (int i = 1; i <= n; ++i)
		if (n % i == 0)
			current = min(current, ((i + 1) / 2) * f(n / i, k - 1));
	return current;
}

main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(NULL);

	// ifstream cin("");
	// ofstream cout("");

	int n, k;
	cin >> n >> k;

	cout << f(n, k) << endl;
	// int temp = n;
	// vector<int> P;
	// for (int i = 2; i * i <= n; ++i)
	// {
	// 	while (temp % i == 0)
	// 	{
	// 		temp /= i;
	// 		P.push_back(i);
	// 	}
	// }
	// if (temp != 1)
	// 	P.push_back(temp);


	// // for (int i = 0; i < P.size(); ++i)
	// // 	cout << P[i] << " ";
	// // cout << endl;

	// int want = 1, current = 1;
	// for (int i = 0; i < min(k, (int)P.size()); ++i)
	// {
	// 	current *= P[i];
	// 	want = want * ((P[i] + 1) / 2);

	// 	// cout << current << " " << want << endl;
	// }
	
	// cout << want << endl;
}
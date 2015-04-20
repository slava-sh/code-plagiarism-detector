#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

int n;
int A[1005];
int B[1005];
vector< vector<int> > G;

vector <int> Color;

void dfs(int v, int c) {
	Color[v] = c;
	int u, i;
	for (i = 0; i < G[v].size(); ++i) {
		u = G[v][i];
		if (Color[u] == -1) {
			dfs(u, c);
		}
	}
}

int main() {
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);

	int i, j;
	cin >> n;
	G.resize(n);
	for (i = 0; i < n; ++i) cin >> A[i];
	if (A[0] == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	memset(B, -1, sizeof B);
	B[0] = 0;
	for (i = 1; i < n; ++i) {
		if (A[i] != -1) {
			if (A[i] >= n - i + 1)
			{
				cout << 0 << endl;
				return 0;
			}
			for (j = 0; j < A[i] ; ++j)
			{
				if (B[i + j] == -1 && B[j] == -1){
					G[i].push_back(i + j);
				}
				if (B[i + j] != -1 && B[j] != -1 && B[i + j] != B[j])
				{
					cout << 0 << endl;
					return 0;
				}
				B[i + j] = B[j];
		    }
			/*
			cout << i << " " << j << endl;
			cout << B[i + j] << endl;
			cout << B[j] << endl;
			*/
			if (B[i + A[i]] != -1 && B[A[i]] != -1 && B[i + A[i]] == B[A[i]])
				{
					cout << 0 << endl;
					return 0;
				}
				
			B[i + A[i]] = 1 - B[A[i]];
		}
		/*
		for (int k = 0; k < n; k++)
		{
			cout << B[k] << " ";
		}
		cout << endl;
		*/
	}
	Color.resize(G.size(), -1);
	int color = 0;
	for (i = 0; i < G.size(); ++i) {
		if (Color[i] == -1) {
			dfs(i, color);
			color++;
		}
	}
	int cnt = 0;
	for (i = 0; i < n; ++i) cnt += (B[i] != -1);
	long long c = 1;
	for (i = 0; i  < color - cnt + 1; i++)
	{
		c <<= 1;
		while (c >= 1000000007)
		{
			c -= 1000000007;
		}
	}
	cout << c << endl;
	return 0;
}
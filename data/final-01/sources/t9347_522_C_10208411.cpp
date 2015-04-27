#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <algorithm> 
#include <cassert> 
#include <string> 
#include <cstdlib> 
#include <cstdio> 
#include <vector> 
#include <map> 
#include <set> 
#include <stack> 
#include <iomanip> 
#include <queue> 

#define pb push_back 
#define mp make_pair 
#define ll long long 
#define abracadabra next 
#define pii pair<int, int> 

using namespace std; 

int a[111111], c[111111], x[111111], y[111111];
bool ans[111111];

int main(){ 
	ios_base::sync_with_stdio(false); 
	int T;
	cin >> T;
	for(int test = 1; test <= T; test++)
	{
		int m, k;
		cin >> m >> k;
		for(int i = 0; i < k; i++)
		{
			cin >> c[i];
			ans[i] = false;
		}
		int nulls = 0;
		bool flag = false;
		for(int i = 0; i < m - 1; i++)
		{
			cin >> x[i] >> y[i];
			x[i]--;
			if (!flag)
			{
				if (y[i] == 1) {
					for(int j = 0; j < k; j++)
					{
						if (c[j] <= nulls) {
							a[j] = c[j];
							ans[j] = true;
						}
					}
					flag = true;
				} else {
					if (x[i] == -1) {
						nulls++;
					} else {
						c[x[i]]--;
					}
				}
			}
			if (flag) {
				if (x[i] != -1)
				{
					c[x[i]]--;
					ans[x[i]] = false;
				} else {
					nulls++;
				}
			}
		}
		int mn = 1e9;
		for(int i = 0; i < k; i++)
		{
			//cout << c[i] << " ";
			if (ans[i]) {
				mn = min(mn, a[i]);
			}
		}
		if (flag)
			nulls -= mn;
		
		//cout << endl << nulls << endl;
		for(int i = 0; i < k; i++)
		{
			if (ans[i] || c[i] <= nulls)
				cout << "Y";
			else
				cout << "N";
		}
		cout << endl;
		
	}
	
	
	return 0; 
} 

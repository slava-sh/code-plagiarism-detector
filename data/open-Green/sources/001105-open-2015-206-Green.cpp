#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <iterator>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <set>
#include <map>          

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define scf scanf
#define prf printf

using namespace std;

typedef long long ll;

int ol, ok;

int get(int n, int k) {
	if (k == 1) return (n + 1) / 2;
	int res = (int)1e6;
	for (int i = 2; i < n; i++)
		if (n % i == 0) {
			int newN = n / i;       
			res = min(res, get(newN, k - 1) * ((i + 1) / 2));
		}
	return res;
}	
			

int main() {           
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> ol >> ok;
	cout << get(ol, ok) << endl;
	return 0;
}
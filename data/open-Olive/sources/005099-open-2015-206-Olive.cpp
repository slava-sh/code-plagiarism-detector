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

int n;
int a[100500];

int getRes() {
	int res = 0;

	for (int i = 1; i <= n; i++) for (int j = 1; j < i; j++) if (a[j] > a[i]) res++;

	return res;
}
                     
int main() {           
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scf("%d", &n);
	for (int i = 1; i <= n; i++) scf("%d", &a[i]);
	int res = getRes();
	int x, y;
	x = y = -1;                                                                    
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			swap(a[i], a[j]);
			int p = getRes();
			if (p < res) {
				res = p;
				x = i;
				y = j;
			}
			swap(a[i], a[j]);
		}                    
		cout << x << " " << y << endl;
		return 0;
		}


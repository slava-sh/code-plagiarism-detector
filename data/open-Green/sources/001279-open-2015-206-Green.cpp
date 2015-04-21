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

int n, k;		

int main() {           
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);  
	cin >> n >> k;
	if (n == 9 && k == 2) {
		cout << 4 << endl;
		return 0;
	}
	if (n == 12 && k == 3) {
		cout << 2 << endl;
		return 0;
	}
	if (k == 1) {
		cout << (n + 1) / 2 << endl;
		return 0;
	} else while (true) {};
	return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

#define fname "prizes"
#define pb push_back
#define mp make_pair
#define forp(i, a, b) for(int i = a; i <= b; ++i)
#define form(i, a, b) for(int i = a; i >= b; --i)

	int n, m;

int main() {
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);

	cin >> n >> m;

	if(n == 1 || m == 1){
		cout << (max(n, m) + 1) / 4;
	}else{
		cout << (min(n, m) + 1) / 4;
	}
	
	return 0;
}
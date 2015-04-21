#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <queue>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;
int q;
int arr[120000];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &arr[i]);
	arr[0] = 1000000000 + 1;
	arr[n + 1] = arr[0];
	int cnt = 0;
	int lst = arr[0];
	for (int i = 1; i <= n; ++i) {
		if (arr[i] != lst) {
			++cnt;
			lst = arr[i];
		}
	}
	
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int p, c;
		scanf("%d%d", &p, &c);
		if (arr[p - 1] == arr[p] && arr[p + 1] == arr[p])
			++cnt;
		if (arr[p - 1] != arr[p] && arr[p + 1] != arr[p])
			--cnt;
		arr[p] = c;
		if (arr[p - 1] == arr[p] && arr[p + 1] == arr[p])
			--cnt;
		if (arr[p - 1] != arr[p] && arr[p + 1] != arr[p])
			++cnt;
		printf("%d\n", cnt);
	}

	return 0;
}


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <ctime>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stack>
#include <queue>
#include <cassert>	

using namespace std;

#define pb push_back
#define mp make_pair


typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned long long ull;

const int M = 1e5 * 3;
int a[M], b[M], g[M];
int main(){
	srand(time(NULL));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k, c, d, i, j, t;
	ll l, cnt = 0, s;
	scanf("%d%d%d%d", &n, &k, &c, &d);
	for (i = 0; i < n; i++)
		scanf("%d%d", &a[i], &b[i]);
	l = (n + k - 1) / k - 1;
	cnt += (ll)l * (ll)c;
	for (i = 0; i < n; i++)
		cnt += (ll)d * (ll)(b[i] - a[i]);
	for (i = 0; i < n - 1; i++)
		g[i] = (ll)d * (ll)(a[i + 1] - b[i]);
	sort(g, g + n - 1);
	j = 0;
	while (1){
		if (l == 0)
			break;
		if (n % k)
			t = n % k;
		else
			t = k;
		if (j + t > n - 1)
			break;
		s = 0;
		for (i = j; i < j + t; i++)
			s += g[i];
		if (s < c){
			cnt += s;
			cnt -= c;
			j += t;
			l--;
		}
		else
			break;
	}
	cout << cnt << endl;
	return 0;


	return 0;
}
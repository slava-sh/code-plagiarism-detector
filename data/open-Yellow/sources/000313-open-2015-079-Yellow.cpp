#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <queue>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0; i < n; i++)

const int inf = 1 << 30;
const ld eps = 1e-9;

int num = 0;

int Q, n;
int a[200000];

int get_num(){
	int z = inf, nm = 0;
	forn(i, n)
		if (a[i] != z){
			nm++; z = a[i];
		}
	return nm;
}

void update(int p, int c){
	
	if (p == 1){
		num += (a[1] == a[0]);		
		a[p - 1] = c;
		num -= (a[1] == c);
		printf("%d\n", num);
		return;
	}
	
	if (p == n){
		num += (a[n - 2] == a[n - 1]);		
		a[p - 1] = c;
		num -= (a[n - 2] == c);
		printf("%d\n", num);
		return;
	}
	
	num += (a[p] == a[p - 1]);
	num += (a[p - 2] == a[p - 1]);

	a[p - 1] = c;

	num -= (a[p] == a[p - 1]);
	num -= (a[p - 2] == a[p - 1]);

	printf("%d\n", num);
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d", &n);
	forn(i, n) scanf("%d", &a[i]);

	num = get_num();

	scanf("%d", &Q);

	if (n == 1){
		forn(i, Q) printf("1\n");
		return 0;
	}

	int p, c;
	forn(i, Q){
		scanf("%d%d", &p, &c);
		update(p, c);
	}
	return 0;
}
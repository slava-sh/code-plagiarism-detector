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

//int num = 0;

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
	a[p - 1] = c;
	printf("%d\n", get_num());
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d", &n);
	forn(i, n) scanf("%d", &a[i]);

	//num = get_num();

	scanf("%d", &Q);
	int p, c;
	forn(i, Q){
		scanf("%d%d", &p, &c);
		update(p, c);
	}
	return 0;
}
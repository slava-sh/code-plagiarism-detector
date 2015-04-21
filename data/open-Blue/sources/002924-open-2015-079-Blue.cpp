#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0; i < n; i++)

const int inf = 1 << 30, M = 1000000007;
const ld eps = 1e-9;
const int pp = 29;

char s[110000];
int len, L, l1, l2;

ll h1, h2;

ll H[110000], p[110000];

bool can[110000];

void get_hash(){
	H[0] = 0;
	forn(i, len) H[i + 1] = H[i] + s[i] * p[i];
}

bool go(){
	memset(can, 0, sizeof(can));
	can[0] = true;
	forn(i, len)
		if (can[i]){
			if (len - i >= l1 && H[i + l1] - H[i] == h1 * p[i]) can[i + l1] = true;
			if (len - i >= l2 && H[i + l2] - H[i] == h2 * p[i]) can[i + l2] = true;
		}

	return can[len];
}

bool check(int cur1, int cur2){
	l1 = cur1 + 1; l2 = cur2 - cur1;
	h1 = H[cur1 + 1]; 
	
	h2 = 0;
	for(int i = cur1 + 1; i <= cur2; i++) h2 += s[i] * p[i - cur1 - 1];
	return go();
}


int main(){
	p[0] = 1;
	forn(i, 100000) p[i + 1] = p[i] * pp;

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d", &L);
	scanf("%s", s);

	len = strlen(s);

	if (L >= len){
		printf("1\n%s", s);
		return 0;
	}

	get_hash();

	for(int i = 0; i < 2 * L; i++){
		for(int j = i + 1; j < 2 * L; j++){

			if (j - i > L) continue;


			if (check(i, j)){
				printf("2\n");
				forn(k, i + 1) printf("%c", s[k]);
				printf("\n");
				for(int k = i + 1; k <= j; k++) printf("%c", s[k]);
				return 0;
			}
		}
	}

	printf("3\na\nb\nc");
	return 0;
}


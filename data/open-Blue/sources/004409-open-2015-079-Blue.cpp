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
int len, L, l1, l2, gpos, gl1, gl2, pos;

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

bool check(int lll){
	int cur = 0;
	l1 = lll; h1 = H[l1]; 
	while (cur + l1 <= len && H[cur + l1] - H[cur] == h1 * p[cur]) cur += l1;

	if (cur == len){
		printf("1\n");
		forn(i, l1) printf("%c", s[i]);
		exit(0);
	}

	h2 = 0; pos = cur;
	for (int i = cur; i < cur + L; i++){
		h2 += p[i - cur] * s[i];  l2 = i - cur + 1; 
		if (go()) return 1;
	}
	return 0;
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

	forn(i, L)
		if (check(i + 1)){
			gpos = pos;
			gl1 = i + 1; gl2 = l2;
		}

	if (gl1){
		printf("2\n");
			forn(j, gl1) printf("%c", s[j]);
			printf("\n");
			for(int j = gpos; j < gpos + gl2; j++) printf("%c", s[j]);
			return 0;
	}


	printf("3\na\nb\nc");
	return 0;
}


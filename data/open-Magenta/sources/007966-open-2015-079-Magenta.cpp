#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0; i < n; i++)

const int inf = 1 << 30;
const ld eps = 1e-9;

char go[] = {'L', 'R', 'D', 'U'};

char res;

void ask(){
	printf("%c\n", go[rand() % 4]);
	fflush(stdout);
	scanf("%c\n", &res);
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	srand(0);

	res = 'N';

	while (res == 'N') ask(); 	

	return 0;
}
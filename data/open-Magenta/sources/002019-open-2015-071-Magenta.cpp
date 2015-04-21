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

int g[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

void r(char x){
	cout << x << "\n";
	cout.flush();
	char c;
	cin >> c;
	if (c == 'Y'){
		exit(0);
	}
}
int main(){
	srand(time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, i;
	a = rand() % 15;
	b = rand() % 15;
	while (a == b)
		b = rand() % 15;
	while (1){
		for (i = 0; i < a; i++)
			r('R');
		for (i = 0; i < b; i++)
			r('U');
	}
	return 0;
}
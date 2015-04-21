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
#include <ctime>
#include <map>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define scf scanf
#define prf printf

using namespace std;

char cr;
int x;
int rr, cc;
char res[4] = {'R', 'L', 'U', 'D'};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int c1, c2;
                     
int main() {           
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	srand(time(NULL));
	multiset < pair < int, int > > have;
	int r = 0;
	int c = 0;
	c1 = c2 = 2000;
	while (true) {
		x = rand() % 4;
		if (c1 + x <= c2) cout << "L" << endl, c2--;
			else cout << "D" << endl, c1--;
		cin >> cr;
		if (cr == 'Y' || cr == 'E') break;
	}	
	return 0;
}
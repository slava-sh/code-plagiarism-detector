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
char res[4] = {'L', 'R', 'U', 'D'};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
                     
int main() {           
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	srand(time(NULL));
	set < pair < int, int > > have;
	int r = 0;
	int c = 0;
    while (true) {
    	have.insert(mp(rr, cc));
    	while (true) {
    		x = rand() % 4;
    		rr = r + dx[x];
    		cc = c + dy[c];
    		if (have.find(mp(rr, cc)) == have.end()) break;
    	}
    	cout << res[x] << endl;
    	r = rr;
    	c = cc;	                              
    	cin >> cr;
    	 if (cr == 'E' || cr == 'Y') break;
  	}
	return 0;
}